/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:41:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 18:19:50 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

static const int MIN_GRADE_TO_SIGN = 25;
static const int MIN_GRADE_TO_EXECUTE = 5;

PresidentialPardonForm::PresidentialPardonForm(const std::string& newName, const std::string& newTarget) :
	AForm(newName, MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& newTarget) :
	AForm("Default PresidentialPardonForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Default PresidentialPardonForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target("home")
{
	OCF_MESSAGE("PresidentialPardonForm Default constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	OCF_MESSAGE("PresidentialPardonForm Destructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& that) :
	AForm(that)
{
	OCF_MESSAGE("PresidentialPardonForm Copy constructor called");
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& that)
{
	OCF_MESSAGE("PresidentialPardonForm Assignment operator called");
	if (this != &that)
	{
		AForm::operator=(that);
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	verifyExecuteRequirements(bureaucrat);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

#undef OCF_MESSAGE
