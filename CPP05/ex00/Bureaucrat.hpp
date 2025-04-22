/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:48 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 15:33:05 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		const int _highestGrade = 1;
		const int _lowestGrade = 150;
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
		Bureaucrat( void ) = delete;
		Bureaucrat( std::string name, int grade );
		~Bureaucrat( void );
		Bureaucrat( Bureaucrat const &obj );
		Bureaucrat &operator=( Bureaucrat const &obj );
		std::string getName( void ) const;
		int getGrade( void ) const;
		void increaseGrade( void );
		void decreaseGrade( void );
};

std::ostream &operator<<( std::ostream &out, Bureaucrat const &obj );
