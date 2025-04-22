/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:37:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 18:04:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form :: Form( std::string name, int signGrade, int executeGrade )
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	_isSigned = false;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	return;
}

Form :: ~Form( void ) { }

std::string Form :: getName( void ) const
{
	return _name;
}

bool Form :: getIsSigned( void ) const
{
	return _isSigned;
}

int Form :: getSignGrade( void ) const
{
	return _signGrade;
}

int Form :: getExecuteGrade( void ) const
{
	return _executeGrade;
}

void Form :: beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (bureaucrat.getGrade() < _signGrade)
		throw Form::GradeTooHighException();
	if (_isSigned)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << _name
			<< " because it is already signed." << std::endl;
		return;
	}
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	_isSigned = true;
}

const char *Form :: GradeTooHighException :: what() const throw()
{
	return "Grade is too high.";
}

const char *Form :: GradeTooLowException :: what() const throw()
{
	return "Grade is too low.";
}

std::ostream &operator<<( std::ostream &out, Form const &obj )
{
	if (!getIsSigned(obj))
		out << "Form: " << obj.getName() << ", sign grade: " << obj.getSignGrade()
			<< ", execute grade: " << obj.getExecuteGrade() << ", is signed: "
			<< "no";
	else
		out << "Form: " << obj.getName() << ", sign grade: " << obj.getSignGrade()
			<< ", execute grade: " << obj.getExecuteGrade() << ", is signed: "
			<< "yes";
	return out;
}
