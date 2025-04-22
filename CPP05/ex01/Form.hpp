/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:37:12 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 18:05:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _signGrade;
		int const _executeGrade;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		Form( void ) = delete;
		Form( std::string name, int signGrade, int executeGrade );
		~Form( void );
		Form( Form const &obj ) = delete;
		Form &operator=( Form const &obj ) = delete;
		std::string getName( void ) const;
		bool getIsSigned( void ) const;
		int getSignGrade( void ) const;
		int getExecuteGrade( void ) const;
		void beSigned( Bureaucrat const &bureaucrat );
};

std::ostream &operator<<( std::ostream &out, Form const &obj );
