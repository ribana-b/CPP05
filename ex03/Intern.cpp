/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:19:12 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/04 07:08:17 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cctype> // For std::tolower and std::isspace
#include <iostream> // For std::cout

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

Intern::Intern()
{
	OCF_MESSAGE("Intern Default constructor called");
}

Intern::~Intern()
{
	OCF_MESSAGE("Intern Destructor called");
}

Intern::Intern(const Intern&)
{
	OCF_MESSAGE("Intern Copy constructor called");
}

Intern&	Intern::operator=(const Intern&)
{
	OCF_MESSAGE("Intern Assignment operator called");
	return (*this);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	FormMap formMapShrubberyCreation = {
		"shrubberycreation",
		"Shrubbery Creation Form",
		makeShrubberyCreationForm,
	};
	FormMap formMapRobotomyRequest = {
		"robotomyrequest",
		"Robotomy Request Form",
		makeRobotomyRequestForm,
	};
	FormMap formMapPresidentialPardon = {
		"presidentialpardon",
		"Presidential Pardon Form",
		makePresidentialPardonForm,
	};

	FormMap formMaps[] = {
		formMapShrubberyCreation,
		formMapRobotomyRequest,
		formMapPresidentialPardon,
	};
	std::size_t formMapLength = sizeof(formMaps) / sizeof(*formMaps);

	for (std::size_t i = 0; i < formMapLength; ++i)
	{
		if (understandFormName(formMaps[i].name, name))
		{
			std::cout << "Intern creates " << formMaps[i].realName << std::endl;
			return (formMaps[i].func(target));
		}
	}

	throw(UnknownFormException());
}

std::string	Intern::convertToReadableName(const std::string& name)
{
	std::string readable;
	std::size_t length = name.length();

	for (std::size_t i = 0; i < length; ++i)
	{
		char c = std::tolower(name[i]);
		if (!std::isspace(c))
		{
			readable += c;
		}
	}
	return readable;
}

bool	Intern::understandFormName(const std::string& formName, const std::string& name)
{
	if (name.compare(formName) == 0)
	{
		return (true);
	}

	std::string readableName(convertToReadableName(name));
	std::string readableFormName(convertToReadableName(formName));

	return (readableName.compare(readableFormName) == 0);
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form");
}

AForm*	Intern::makeShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

#undef OCF_MESSAGE
