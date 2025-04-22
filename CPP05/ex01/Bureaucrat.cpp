/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:52 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 15:09:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << "Constructor called for Bureaucrat " << _name << std::endl;
	_grade = grade;
	if (_grade < _highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > _lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat :: ~Bureaucrat( void )
{
	std::cout << "Destructor called for Bureaucrat " << _name << std::endl;
}

Bureaucrat :: Bureaucrat( Bureaucrat const &obj )
{
	std::cout << "Copy constructor called for Bureaucrat " << obj._name << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat :: operator=( Bureaucrat const &obj )
{
	std::cout << "Copy assignment operator called for Bureaucrat " << obj._name << std::endl;
	if (this != &obj)
	{
		this->_grade = obj._grade;
	}
	return (*this);
}

std::string Bureaucrat :: getName( void ) const
{
	return (_name);
}

int Bureaucrat :: getGrade( void ) const
{
	return (_grade);
}

void Bureaucrat :: increaseGrade( void )
{
	if (_grade <= _highestGrade)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat :: decreaseGrade( void )
{
	if (_grade >= _lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<( std::ostream &out, Bureaucrat const &obj )
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}
