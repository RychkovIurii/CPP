/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:13:41 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:38:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
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
		class AlreadySigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NeedToSign : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		AForm( void ) = delete;
		AForm( std::string name, int signGrade, int executeGrade );
		virtual ~AForm( void );
		AForm( AForm const &obj ) = delete;
		AForm &operator=( AForm const &obj ) = delete;
		std::string getName( void ) const;
		bool getIsSigned( void ) const;
		int getSignGrade( void ) const;
		int getExecuteGrade( void ) const;
		void beSigned( Bureaucrat const &bureaucrat );

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<( std::ostream &out, AForm const &obj );
