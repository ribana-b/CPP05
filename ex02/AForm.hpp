/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:52:27 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 15:57:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm
{
	public:
		AForm(const std::string& newName, int newMinGradeToSign, int newMinGradeToExecute);
		AForm();
		virtual ~AForm();
		AForm(const AForm& that);
		AForm& operator=(const AForm& that);

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getMinGradeToSign() const;
		int					getMinGradeToExecute() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& bureaucrat) const = 0;
		void			verifyExecuteRequirements(const Bureaucrat& bureaucrat) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
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

std::ostream&	operator<<(std::ostream& out, const AForm& that);

#endif
