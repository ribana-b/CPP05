/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:52:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 16:28:44 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout
#include <sstream>	// For std::streamstring

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

AForm::AForm(const std::string& newName, int newMinGradeToSign, int newMinGradeToExecute) :
	name(newName),
	isSigned(false),
	minGradeToSign(newMinGradeToSign),
	minGradeToExecute(newMinGradeToExecute)
{
	OCF_MESSAGE("AForm constructor called");

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

AForm::AForm() :
	name("Default AForm"),
	isSigned(false),
	minGradeToSign(Bureaucrat::LOWEST_GRADE),
	minGradeToExecute(Bureaucrat::LOWEST_GRADE)
{
	OCF_MESSAGE("AForm Default constructor called");
}

AForm::~AForm()
{
	OCF_MESSAGE("AForm Destructor called");
}

AForm::AForm(const AForm& that) :
	name(that.name),
	isSigned(that.isSigned),
	minGradeToSign(that.minGradeToSign),
	minGradeToExecute(that.minGradeToExecute)
{
	OCF_MESSAGE("AForm Copy constructor called");
}

AForm&	AForm::operator=(const AForm& that)
{
	OCF_MESSAGE("AForm Assignment operator called");
	if (this != &that)
	{
		this->isSigned = that.isSigned;
	}
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (name);
}

bool	AForm::getIsSigned() const
{
	return (isSigned);
}

int	AForm::getMinGradeToSign() const
{
	return (minGradeToSign);
}

int	AForm::getMinGradeToExecute() const
{
	return (minGradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > minGradeToSign)
	{
		throw(GradeTooLowException(minGradeToSign));
	}
	isSigned = true;
}

void	AForm::verifyExecuteRequirements(const Bureaucrat& bureaucrat) const
{
	if (!isSigned)
	{
		throw(FormNotSignedException());
	}
	if (bureaucrat.getGrade() > minGradeToExecute)
	{
		throw(GradeTooLowException(minGradeToExecute));
	}
}

AForm::GradeTooHighException::GradeTooHighException(const int newGrade) :
	grade(newGrade)
{
	OCF_MESSAGE("GradeTooHighException constructor called");
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	OCF_MESSAGE("GradeTooHighException destructor called");
}

const char*	AForm::GradeTooHighException::what() const throw()
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

AForm::GradeTooLowException::GradeTooLowException(const int newGrade) :
	grade(newGrade)
{
	OCF_MESSAGE("GradeTooLowException constructor called");
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	OCF_MESSAGE("GradeTooLowException destructor called");
}

const char*	AForm::GradeTooLowException::what() const throw()
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

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "the form is not signed!";
}

std::ostream&	operator<<(std::ostream& out, const AForm& that)
{
	out << "Name: " << that.getName();
	out << ", IsSigned: " << (that.getIsSigned() ? "Yes" : "No");
	out << ", MinGradeToExecute: " << that.getMinGradeToSign();
	out << ", MinGradeToExecute: " << that.getMinGradeToExecute();
	return (out);
}

#undef OCF_MESSAGE
