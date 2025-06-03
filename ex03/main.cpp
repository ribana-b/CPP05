/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:34:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/03 11:31:24 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream> // For std::cout, std::cerr

// Helper macro to pretty-print tests
#define PP_TEST(testIndex) do{\
	std::string testName((__func__));\
	std::cout << "\033[38;2;255;128;255m- Test " << (testIndex)\
	<< " (" << testName.substr(4) << "):\033[0m" << std::endl;\
} while(0)

// Helper macro to pretty-print caught exceptions
#define PP_EXCEPTION(exception) do{\
	std::cerr << "\033[31m" << (__FILE__) << ":" << (__LINE__) << "\033[0m"\
	<< ": Exception caught. Reason:\033[0m " << (exception).what() << std::endl;\
} while(0)

// Helper macro to pretty-print uncreated unexceptions
#define PP_UNDEFINED_EXCEPTION(message) do{\
	std::cerr << "\033[31m" << (__FILE__) << ":" << (__LINE__) << "\033[0m"\
	<< ": Undefined Exception caught. Reason:\033[0m " << (message) << std::endl;\
} while(0)

// Added later, and I don't want to rename every bureaucrat...
void testSetBureaucratHighestGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat artisfo("Artisfo", Bureaucrat::HIGHEST_GRADE);

		std::cout << artisfo << std::endl;
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

// Added later, and I don't want to rename every bureaucrat...
void testSetBureaucratLowestGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat bluqfo("Bluqfo", Bureaucrat::LOWEST_GRADE);

		std::cout << bluqfo << std::endl;
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

// Added later, and I don't want to rename every bureaucrat...
void testBureaucratIncreaseGradeInBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat ceniafo("Ceniafo", Bureaucrat::LOWEST_GRADE);
		const int amount = 20;

		std::cout << ceniafo << std::endl;
		for (int i = 0; i < amount; ++i)
		{
			ceniafo.increaseGrade();
		}
		if (ceniafo.getGrade() != Bureaucrat::LOWEST_GRADE - amount)
		{
			PP_UNDEFINED_EXCEPTION("Grades don't match");
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

// Added later, and I don't want to rename every bureaucrat...
void testBureaucratDecreaseGradeInBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat deronfo("Deronfo", Bureaucrat::HIGHEST_GRADE);
		const int amount = 20;

		std::cout << deronfo << std::endl;
		for (int i = 0; i < amount; ++i)
		{
			deronfo.decreaseGrade();
		}
		if (deronfo.getGrade() != Bureaucrat::HIGHEST_GRADE + amount)
		{
			PP_UNDEFINED_EXCEPTION("Grades don't match");
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void testSetBureaucratGradeTooHigh(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE - 1);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void testSetBureaucratGradeTooLow(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat bluq("Bluq", Bureaucrat::LOWEST_GRADE + 1);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void testIncreaseBureaucrateGradeOverBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat cenia("Cenia", 10);

	try
	{
		for (int i = 0; i < 20; ++i)
		{
			cenia.increaseGrade();
			std::cout << cenia << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << cenia << std::endl;
}

void testDecreaseBureaucrateGradeOverBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat deron("Deron", 140);

	try
	{
		for (int i = 0; i < 20; ++i)
		{
			deron.decreaseGrade();
			std::cout << deron << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << deron << std::endl;
}

void testCopyBureaucrat(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat ensi("Ensi", 140);
	Bureaucrat ensiCopy(ensi);

	std::cout << ensi << std::endl;
	std::cout << ensiCopy << std::endl;
}

void testAssignBureaucrat(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat flein("Flein", 140);
	Bureaucrat fleinCopy("FleinCopy", 1);

	fleinCopy = flein;
	std::cout << flein << std::endl;
	std::cout << fleinCopy << std::endl;
}

void testAssignAndDecreaseBureaucratGradeOutOfBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat giona("Giona", 140);
	Bureaucrat gionaCopy("GionaCopy", 1);

	gionaCopy = giona;
	try
	{
		for (int i = 0; i < 20; ++i)
		{
			gionaCopy.decreaseGrade();
			std::cout << gionaCopy << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << giona << std::endl;
	std::cout << gionaCopy << std::endl;
}

void testAssignAndIncreaseBureaucratGradeOutOfBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat hizen("Hizen", 10);
	Bureaucrat hizenCopy("HizenCopy", 150);

	hizenCopy = hizen;
	try
	{
		for (int i = 0; i < 20; ++i)
		{
			hizenCopy.increaseGrade();
			std::cout << hizenCopy << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << hizen << std::endl;
	std::cout << hizenCopy << std::endl;
}

void testAssignPointerAndIncreaseBureaucratGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat *ixnig = new Bureaucrat("Ixnig", 20);
	Bureaucrat *ixnigCopy = ixnig;

	try
	{
		for (int i = 0; i < 20; ++i)
		{
			ixnigCopy->increaseGrade();
			std::cout << *ixnigCopy << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << *ixnig << std::endl;
	std::cout << *ixnigCopy << std::endl;
	delete ixnig;
}

void testAssignReferenceAndIncreaseBureaucratGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat joplem("Joplem", 20);
	Bureaucrat *joplemCopy = &joplem;

	try
	{
		for (int i = 0; i < 20; ++i)
		{
			joplemCopy->increaseGrade();
			std::cout << *joplemCopy << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}

	std::cout << joplem << std::endl;
	std::cout << *joplemCopy << std::endl;
}

void	testEx00(std::size_t* testIndexPointer)
{
	std::size_t testIndex = *testIndexPointer;

	testSetBureaucratHighestGrade(testIndex++);
	testSetBureaucratLowestGrade(testIndex++);
	testBureaucratIncreaseGradeInBounds(testIndex++);
	testBureaucratDecreaseGradeInBounds(testIndex++);
	testSetBureaucratGradeTooHigh(testIndex++);
	testSetBureaucratGradeTooLow(testIndex++);
	testIncreaseBureaucrateGradeOverBounds(testIndex++);
	testDecreaseBureaucrateGradeOverBounds(testIndex++);
	testCopyBureaucrat(testIndex++);
	testAssignBureaucrat(testIndex++);
	testAssignAndDecreaseBureaucratGradeOutOfBounds(testIndex++);
	testAssignAndIncreaseBureaucratGradeOutOfBounds(testIndex++);
	testAssignPointerAndIncreaseBureaucratGrade(testIndex++);
	testAssignReferenceAndIncreaseBureaucratGrade(testIndex++);

	*testIndexPointer = testIndex;
}

void	testShrubberyCreationFormExecuteHighGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	ShrubberyCreationForm artisShrubbery("ArtisShrubberyForm", "Artis");
	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);

	std::cout << artisShrubbery << std::endl;
	artisShrubbery.beSigned(artis);
	artisShrubbery.execute(artis);
}

void	testShrubberyCreationFormExecuteLowGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	ShrubberyCreationForm bluqShrubbery("BluqShrubberyForm", "Bluq");
	Bureaucrat bluq("Bluq", Bureaucrat::LOWEST_GRADE);

	std::cout << bluqShrubbery << std::endl;

	try
	{
		bluqShrubbery.beSigned(bluq);
		bluqShrubbery.execute(bluq);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testShrubberyCreationFormExecuteWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	ShrubberyCreationForm ceniaShrubbery("CeniaShrubberyForm", "Cenia");
	Bureaucrat cenia("cenia", Bureaucrat::LOWEST_GRADE);

	std::cout << ceniaShrubbery << std::endl;
	try
	{
		ceniaShrubbery.execute(cenia);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testShrubberyCreationForm(std::size_t* testIndexPointer)
{
	std::size_t testIndex = *testIndexPointer;

	testShrubberyCreationFormExecuteHighGrade(testIndex++);
	testShrubberyCreationFormExecuteLowGrade(testIndex++);
	testShrubberyCreationFormExecuteWithoutSigning(testIndex++);

	*testIndexPointer = testIndex;
}

void	testRobotomyRequestFormExecuteHighGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	RobotomyRequestForm artisRobotomy("ArtisRobotomyForm", "Artis");
	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);

	std::cout << artisRobotomy << std::endl;
	artisRobotomy.beSigned(artis);
	artisRobotomy.execute(artis);
}

void	testRobotomyRequestFormExecuteLowGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	RobotomyRequestForm bluqRobotomy("BluqRobotomyForm", "Bluq");
	Bureaucrat bluq("Bluq", Bureaucrat::LOWEST_GRADE);

	std::cout << bluqRobotomy << std::endl;
	try
	{
		bluqRobotomy.beSigned(bluq);
		bluqRobotomy.execute(bluq);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testRobotomyRequestFormExecuteWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	RobotomyRequestForm ceniaRobotomy("CeniaRobotomyForm", "Cenia");
	Bureaucrat cenia("Cenia", Bureaucrat::HIGHEST_GRADE);

	std::cout << ceniaRobotomy << std::endl;
	try
	{
		ceniaRobotomy.execute(cenia);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testRobotomyRequestForm(std::size_t* testIndexPointer)
{
	std::size_t testIndex = *testIndexPointer;

	testRobotomyRequestFormExecuteHighGrade(testIndex++);
	testRobotomyRequestFormExecuteLowGrade(testIndex++);
	testRobotomyRequestFormExecuteWithoutSigning(testIndex++);

	*testIndexPointer = testIndex;
}

void	testPresidentialPardonFormExecuteValid(std::size_t testIndex)
{
	PP_TEST(testIndex);

	PresidentialPardonForm artisPresidential;
	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);

	std::cout << artisPresidential << std::endl;
	artisPresidential.beSigned(artis);
	artisPresidential.execute(artis);
}

void	testPresidentialPardonFormExecuteHighGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	PresidentialPardonForm artisPresidentialPardon("ArtisPresidentialPardonForm", "Artis");
	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);

	std::cout << artisPresidentialPardon << std::endl;
	artisPresidentialPardon.beSigned(artis);
	artisPresidentialPardon.execute(artis);
}

void	testPresidentialPardonFormExecuteLowGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	PresidentialPardonForm bluqPresidentialPardon("BluqPresidentialPardonForm", "Bluq");
	Bureaucrat bluq("Bluq", Bureaucrat::LOWEST_GRADE);

	std::cout << bluqPresidentialPardon << std::endl;
	try
	{
		bluqPresidentialPardon.beSigned(bluq);
		bluqPresidentialPardon.execute(bluq);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testPresidentialPardonFormExecuteWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	PresidentialPardonForm ceniaPresidentialPardon("CeniaPresidentialPardonForm", "Cenia");
	Bureaucrat cenia("Cenia", Bureaucrat::HIGHEST_GRADE);

	std::cout << ceniaPresidentialPardon << std::endl;
	try
	{
		ceniaPresidentialPardon.execute(cenia);
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testPresidentialPardonForm(std::size_t* testIndexPointer)
{
	std::size_t testIndex = *testIndexPointer;

	testPresidentialPardonFormExecuteValid(testIndex++);

	*testIndexPointer = testIndex;
}

void	testBureaucratExecuteShrubberyCreationForm(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);
	ShrubberyCreationForm artisShrubbery("ArtisShrubbery", "Artis");

	artis.signForm(artisShrubbery);
	artis.executeForm(artisShrubbery);
}

void	testBureaucratExecuteShrubberyCreationFormWithoutEnoughGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat artisfo("Artisfo", Bureaucrat::LOWEST_GRADE);
	ShrubberyCreationForm artisfoShrubbery("ArtisfoShrubbery", "Artisfo");

	artisfo.signForm(artisfoShrubbery);
	artisfo.executeForm(artisfoShrubbery);
}

void	testBureaucratExecuteShrubberyCreationFormWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat artisfo("Artisfo", Bureaucrat::LOWEST_GRADE);
	ShrubberyCreationForm artisfoShrubbery("ArtisfoShrubbery", "Artisfomi");

	artisfo.executeForm(artisfoShrubbery);
}

void	testBureaucratExecuteRobotomyRequestForm(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat bluq("Bluq", Bureaucrat::HIGHEST_GRADE);
	RobotomyRequestForm bluqRobotomy("BluqRobotomy", "Bluq");

	bluq.signForm(bluqRobotomy);
	bluq.executeForm(bluqRobotomy);
}

void	testBureaucratExecuteRobotomyRequestFormWithoutEnoughGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat bluqfo("Bluqfo", Bureaucrat::LOWEST_GRADE);
	RobotomyRequestForm bluqfoRobotomy("BluqfoRobotomy", "Bluqfo");

	bluqfo.signForm(bluqfoRobotomy);
	bluqfo.executeForm(bluqfoRobotomy);
}

void	testBureaucratExecuteRobotomyRequestFormWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat bluqfomi("Bluqfomi", Bureaucrat::LOWEST_GRADE);
	RobotomyRequestForm bluqfomiRobotomy("BluqfomiRobotomy", "Bluqfomi");

	bluqfomi.executeForm(bluqfomiRobotomy);
}

void	testBureaucratExecutePresidentialPardonForm(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat cenia("Cenia", Bureaucrat::HIGHEST_GRADE);
	PresidentialPardonForm ceniaPresidential("CeniaPresidential", "Cenia");

	cenia.signForm(ceniaPresidential);
	cenia.executeForm(ceniaPresidential);
}

void	testBureaucratExecutePresidentialPardonFormWithoutEnoughGrade(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat ceniafo("Ceniafo", Bureaucrat::LOWEST_GRADE);
	PresidentialPardonForm ceniafoPresidential("CeniafoPresidential", "Ceniafo");

	ceniafo.signForm(ceniafoPresidential);
	ceniafo.executeForm(ceniafoPresidential);
}

void	testBureaucratExecutePresidentialPardonFormWithoutSigning(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat ceniafomi("Ceniafomi", Bureaucrat::LOWEST_GRADE);
	PresidentialPardonForm ceniafomiPresidential("CeniafomiPresidential", "Ceniafomi");

	ceniafomi.executeForm(ceniafomiPresidential);
}

void	testEx02(std::size_t* testIndexPointer)
{
	std::size_t testIndex = *testIndexPointer;

	testShrubberyCreationForm(&testIndex);
	testRobotomyRequestForm(&testIndex);
	testPresidentialPardonForm(&testIndex);

	testBureaucratExecuteShrubberyCreationForm(testIndex++);
	testBureaucratExecuteShrubberyCreationFormWithoutEnoughGrade(testIndex++);
	testBureaucratExecuteShrubberyCreationFormWithoutSigning(testIndex++);
	testBureaucratExecuteRobotomyRequestForm(testIndex++);
	testBureaucratExecuteRobotomyRequestFormWithoutEnoughGrade(testIndex++);
	testBureaucratExecuteRobotomyRequestFormWithoutSigning(testIndex++);
	testBureaucratExecutePresidentialPardonForm(testIndex++);
	testBureaucratExecutePresidentialPardonFormWithoutEnoughGrade(testIndex++);
	testBureaucratExecutePresidentialPardonFormWithoutSigning(testIndex++);

	*testIndexPointer = testIndex;
}

void	testInternMakeShrubberyCreationForms(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Bureaucrat artis("Artis", Bureaucrat::HIGHEST_GRADE);
	Intern artisIntern;

	AForm* artisForm = artisIntern.makeForm("shrubberycreation", "artisform");
	artis.signForm(*artisForm);
	artis.executeForm(*artisForm);
	delete artisForm;

	artisForm = artisIntern.makeForm("shrubbery creation", "artis form");
	artis.signForm(*artisForm);
	artis.executeForm(*artisForm);
	delete artisForm;

	artisForm = artisIntern.makeForm("Shrubbery Creation", "Artis Form");
	artis.signForm(*artisForm);
	artis.executeForm(*artisForm);
	delete artisForm;

	artisForm = artisIntern.makeForm("SHRUBBERY CREATION", "ARTIS FORM");
	artis.signForm(*artisForm);
	artis.executeForm(*artisForm);
	delete artisForm;
}

void	testInternMakeRobotomyRequestForms(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Intern bluqIntern;
}

void	testInternMakePresidentialPardonForms(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Intern ceniaIntern;
}

void	testInternMakeInvalidForm(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Intern deronIntern;

		AForm* deronForm = deronIntern.makeForm("deronForm", "deron");
		delete deronForm;
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

int	main()
{
	std::size_t testIndex = 0;

	testEx00(&testIndex);
	testEx02(&testIndex);

	testInternMakeShrubberyCreationForms(testIndex++);
	testInternMakeRobotomyRequestForms(testIndex++);
	testInternMakePresidentialPardonForms(testIndex++);
	testInternMakeInvalidForm(testIndex++);

	return (0);
}
