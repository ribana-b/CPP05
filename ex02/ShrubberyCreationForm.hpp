/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:37:54 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/02 17:27:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>	// For std::exception
#include <string>		// For std::string

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& newName, const std::string& newTarget);
		ShrubberyCreationForm(const std::string& newTarget);
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& that);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& that);

		virtual void	execute(const Bureaucrat& bureaucrat) const;

		class CouldNotCreateFileException : std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		const std::string	target;
};

#endif
