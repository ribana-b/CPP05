/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:58:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 10:24:47 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

#include <exception>	// For std::exception
#include <ostream>		// For std::ostream
#include <string>		// For std::string

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& newName, int grade);
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& that);
		Bureaucrat& operator=(const Bureaucrat& that);

		const std::string&	getName() const;
		int					getGrade() const;

		void	increaseGrade();
		void	decreaseGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		const std::string	name;
		int					grade;

	public:
		static const int	HIGHEST_GRADE;
		static const int	LOWEST_GRADE;
};

/* @------------------------------------------------------------------------@ */
/* |                            Function Section                            | */
/* @------------------------------------------------------------------------@ */

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
