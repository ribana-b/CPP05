/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:22:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 19:36:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout
#include <sstream>	// For std::streamstring

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

const int	Bureaucrat::HIGHEST_GRADE = 1;
const int	Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) :
	name(newName),
	grade(newGrade)
{
	OCF_MESSAGE("Bureaucrat constructor called");

	if (grade < HIGHEST_GRADE)
	{
		throw(GradeTooHighException());
	}
	if (grade > LOWEST_GRADE)
	{
		throw(GradeTooLowException());
	}
}
Bureaucrat::Bureaucrat() :
	name("Default Bureaucrat"),
	grade(Bureaucrat::LOWEST_GRADE)
{
	OCF_MESSAGE("Bureaucrat Default constructor called");
}

Bureaucrat::~Bureaucrat()
{
	OCF_MESSAGE("Bureaucrat Destructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& that) :
	name(that.name),
	grade(that.grade)
{
	OCF_MESSAGE("Bureaucrat Copy constructor called");
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& that)
{
	OCF_MESSAGE("Bureaucrat Assignment operator called");
	if (this != &that)
	{
		this->grade = that.grade;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::increaseGrade()
{
	if (grade == HIGHEST_GRADE)
	{
		throw(GradeTooHighException());
	}
	--grade;
}

void	Bureaucrat::decreaseGrade()
{
	if (grade == LOWEST_GRADE)
	{
		throw(GradeTooLowException());
	}
	++grade;
}

void	Bureaucrat::signForm(AForm& form) const
{
	if (form.getIsSigned())
	{
		std::cerr << name << " couldn't sign " << form.getName()
			<< " because it's already signed!" << std::endl;
		return;
	}

	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	static std::string message;

	if (message.empty())
	{
		std::stringstream ss;

		ss << "The grade is too high! (max: " << HIGHEST_GRADE << ")";
		message = ss.str();
	}
	return message.c_str();
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	static std::string message;

	if (message.empty())
	{
		std::stringstream ss;

		ss << "The grade is too low! (min: " << LOWEST_GRADE << ")";
		message = ss.str();
	}
	return message.c_str();
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat const& that)
{
	out << that.getName() << ", bureaucrat grade " << that.getGrade();
	return (out);
}
