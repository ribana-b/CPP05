/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:07:39 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/03 11:02:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "AForm.hpp"

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);

		AForm*	makeForm(const std::string& name, const std::string& target) const;

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		typedef AForm* (*MakeFormFunc)(const std::string& name);

		struct FormMap
		{
			const std::string		name;
			Intern::MakeFormFunc	func;
		};

		std::string	convertToReadableName(const std::string& name) const;
		bool		understandFormName(const std::string& formName, const std::string& name) const;

		static AForm*	makeShrubberyCreationForm(const std::string& target);
		static AForm*	makeRobotomyRequestForm(const std::string& target);
		static AForm*	makePresidentialPardonForm(const std::string& target);
};

#endif
