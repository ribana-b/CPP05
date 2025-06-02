/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:27:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 10:28:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

#include "Bureaucrat.hpp"
#include <exception>	// For std::exception
#include <ostream>		// For std::ostream
#include <string>		// For std::string

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& newName, int newMinGradeToSign, int newMinGradeToExecute);
		Form();
		~Form();
		Form(const Form& that);
		Form& operator=(const Form& that);

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getMinGradeToSign() const;
		int					getMinGradeToExecute() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const int newGrade);
				virtual ~GradeTooHighException() throw();

				virtual const char*	what() const throw();

			private:
				const int	grade;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const int newGrade);
				virtual ~GradeTooLowException() throw();

				virtual const char*	what() const throw();

			private:
				const int	grade;
		};

	private:
		const std::string	name;
		bool				isSigned;
		const int			minGradeToSign;
		const int			minGradeToExecute;
};

/* @------------------------------------------------------------------------@ */
/* |                            Function Section                            | */
/* @------------------------------------------------------------------------@ */

std::ostream&	operator<<(std::ostream& out, const Form& that);

#endif
