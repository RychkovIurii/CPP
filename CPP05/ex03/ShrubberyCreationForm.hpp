/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:48:21 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 15:39:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		class FileError : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		ShrubberyCreationForm( void ) = delete;
		ShrubberyCreationForm( std::string target);
		virtual ~ShrubberyCreationForm( void ) = default;
		ShrubberyCreationForm( ShrubberyCreationForm const &obj ) = delete;
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &obj ) = delete;
		virtual void execute( Bureaucrat const &executor ) const;
};
