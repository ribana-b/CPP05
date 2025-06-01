/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:34:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/01 15:42:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream> // For std::cout, std::cerr

// Helper macro to pretty-print tests
#define PP_TEST(i) do{\
	std::string testName((__func__));\
	std::cout << "\033[38;2;255;128;255m- Test " << (i)\
	<< " (" << testName.substr(4) << "):\033[0m" << std::endl;\
} while(0)

// Helper macro to pretty-print caught exceptions
#define PP_EXCEPTION(e) do{\
	std::cerr << "\033[31m" << (__FILE__) << ":" << (__LINE__) << "\033[0m"\
	<< ": Exception caught. Reason:\033[0m " << (e).what() << std::endl;\
} while(0)

void testSetBureaucratGradeTooHigh(std::size_t testIndex)
{
	PP_TEST(testIndex);

	try
	{
		Bureaucrat artis("Artis", 0);
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
		Bureaucrat bluq("Bluq", 151);
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

int	main()
{
	std::size_t testIndex = 0;

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

	return (0);
}
