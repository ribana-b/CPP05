/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:41:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 18:20:11 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout
#include <cstdlib>	// For rand, time

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

static const int MIN_GRADE_TO_SIGN = 72;
static const int MIN_GRADE_TO_EXECUTE = 45;

RobotomyRequestForm::RobotomyRequestForm(const std::string& newName, const std::string& newTarget) :
	AForm(newName, MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& newTarget) :
	AForm("Default RobotomyRequestForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Default RobotomyRequestForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target("home")
{
	OCF_MESSAGE("RobotomyRequestForm Default constructor called");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	OCF_MESSAGE("RobotomyRequestForm Destructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& that) :
	AForm(that)
{
	OCF_MESSAGE("RobotomyRequestForm Copy constructor called");
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& that)
{
	OCF_MESSAGE("RobotomyRequestForm Assignment operator called");
	if (this != &that)
	{
		AForm::operator=(that);
	}
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	verifyExecuteRequirements(bureaucrat);

	srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << "Drr drr drriilliiiing!!!" << std::endl;
		std::cout << target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << target << " robotomization has failed!" << std::endl;
	}
}

#undef OCF_MESSAGE
