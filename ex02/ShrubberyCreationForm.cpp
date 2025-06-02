/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:37:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 19:16:09 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	// For std::cout
#include <fstream>	// For std::fstream
#include <cstdlib>	// For rand, time

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

static const int MIN_GRADE_TO_SIGN = 145;
static const int MIN_GRADE_TO_EXECUTE = 137;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& newName, const std::string& newTarget) :
	AForm(newName, MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("ShrubberyCreationForm constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& newTarget) :
	AForm("Default ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target(newTarget)
{
	OCF_MESSAGE("ShrubberyCreationForm constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Default ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE),
	target("home")
{
	OCF_MESSAGE("ShrubberyCreationForm Default constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	OCF_MESSAGE("ShrubberyCreationForm Destructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& that) :
	AForm(that)
{
	OCF_MESSAGE("ShrubberyCreationForm Copy constructor called");
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& that)
{
	OCF_MESSAGE("ShrubberyCreationForm Assignment operator called");
	if (this != &that)
	{
		AForm::operator=(that);
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	verifyExecuteRequirements(bureaucrat);

	const std::string trees[] = {
		"            *      *\n"
		"           ***    ***\n"
		"          *@*@*  *@*@*\n"
		"         **************\n"
		"           |_|    |_|\n",

		"         *      *      *\n"
		"        ***    ***    ***\n"
		"       *@*@*  *@#@*  *@*@*\n"
		"      *********************\n"
		"        |_|    |_|    |_|\n",
		"      *      *      *      *\n"
		"     ***    ***    ***    ***\n"
		"    *@*@*  *@o@*  *@o@*  *@*@*\n"
		"   ****************************\n"
		"     |_|    |_|    |_|    |_|\n",

		"   *      *      *      *      *\n"
		"  ***    ***    ***    ***    ***\n"
		" *@*@*  *@o@*  *o@o*  *@o@*  *@*@*\n"
		"***********************************\n"
		"  |_|    |_|    |_|    |_|    |_|\n",
	};
	const std::size_t treesLength = sizeof(trees) / sizeof(*trees);
	const std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		throw(CouldNotCreateFileException());
	}

	srand(time(NULL));
	file << trees[rand() % treesLength];

	file.close();
}

const char*	ShrubberyCreationForm::CouldNotCreateFileException::what() const throw()
{
	return "couldn't open file";
}

#undef OCF_MESSAGE
