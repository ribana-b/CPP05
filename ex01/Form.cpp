/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:41:24 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 10:28:05 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout
#include <sstream>	// For std::streamstring

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

Form::Form(const std::string& newName, int newMinGradeToSign, int newMinGradeToExecute) :
	name(newName),
	isSigned(false),
	minGradeToSign(newMinGradeToSign),
	minGradeToExecute(newMinGradeToExecute)
{
	OCF_MESSAGE("Form constructor called");

	if (minGradeToSign < Bureaucrat::HIGHEST_GRADE
		|| minGradeToExecute < Bureaucrat::HIGHEST_GRADE)
	{
		throw(GradeTooHighException(Bureaucrat::HIGHEST_GRADE));
	}
	if (minGradeToSign > Bureaucrat::LOWEST_GRADE
		|| minGradeToExecute > Bureaucrat::LOWEST_GRADE)
	{
		throw(GradeTooLowException(Bureaucrat::LOWEST_GRADE));
	}
}

Form::Form() :
	name("Default Form"),
	isSigned(false),
	minGradeToSign(Bureaucrat::LOWEST_GRADE),
	minGradeToExecute(Bureaucrat::LOWEST_GRADE)
{
	OCF_MESSAGE("Form Default constructor called");
}

Form::~Form()
{
	OCF_MESSAGE("Form Destructor called");
}

Form::Form(const Form& that) :
	name(that.name),
	isSigned(that.isSigned),
	minGradeToSign(that.minGradeToSign),
	minGradeToExecute(that.minGradeToExecute)
{
	OCF_MESSAGE("Form Copy constructor called");
}

Form&	Form::operator=(const Form& that)
{
	OCF_MESSAGE("Form Assignment operator called");
	if (this != &that)
	{
		this->isSigned = that.isSigned;
	}
	return (*this);
}

const std::string&	Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getMinGradeToSign() const
{
	return (minGradeToSign);
}

int	Form::getMinGradeToExecute() const
{
	return (minGradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > minGradeToSign)
	{
		throw(GradeTooLowException(minGradeToSign));
	}
	isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const int newGrade) :
	grade(newGrade)
{
	OCF_MESSAGE("GradeTooHighException constructor called");
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	OCF_MESSAGE("GradeTooHighException destructor called");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	static std::string message;

	if (message.empty())
	{
		std::stringstream ss;

		ss << "the grade is too high! (max: " << grade << ")";
		message = ss.str();
	}
	return message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const int newGrade) :
	grade(newGrade)
{
	OCF_MESSAGE("GradeTooLowException constructor called");
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	OCF_MESSAGE("GradeTooLowException destructor called");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	static std::string message;

	if (message.empty())
	{
		std::stringstream ss;

		ss << "the grade is too low! (min: " << grade << ")";
		message = ss.str();
	}
	return message.c_str();
}

std::ostream&	operator<<(std::ostream& out, const Form& that)
{
	out << "Name: " << that.getName();
	out << ", IsSigned: " << (that.getIsSigned() ? "Yes" : "No");
	out << ", MinGradeToExecute: " << that.getMinGradeToSign();
	out << ", MinGradeToExecute: " << that.getMinGradeToExecute();
	return (out);
}

#undef OCF_MESSAGE
