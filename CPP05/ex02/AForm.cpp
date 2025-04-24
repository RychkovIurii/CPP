/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:13:03 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 13:13:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm :: AForm( std::string name, int signGrade, int executeGrade )
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	_isSigned = false;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	return;
}

AForm :: ~AForm( void ) { }

std::string AForm :: getName( void ) const
{
	return _name;
}

bool AForm :: getIsSigned( void ) const
{
	return _isSigned;
}

int AForm :: getSignGrade( void ) const
{
	return _signGrade;
}

int AForm :: getExecuteGrade( void ) const
{
	return _executeGrade;
}

void AForm :: beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (bureaucrat.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
	if (_isSigned)
		throw AForm::AlreadySigned();
	_isSigned = true;
}

const char *AForm :: GradeTooHighException :: what() const throw()
{
	return "Grade is too high.";
}

const char *AForm :: GradeTooLowException :: what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::AlreadySigned::what() const throw()
{
	return "Already signed";
}

std::ostream &operator<<( std::ostream &out, AForm const &obj )
{
	if (!obj.getIsSigned())
		out << "AForm: " << obj.getName() << ", sign grade: " << obj.getSignGrade()
			<< ", execute grade: " << obj.getExecuteGrade() << ", is signed: "
			<< "no.";
	else
		out << "AForm: " << obj.getName() << ", sign grade: " << obj.getSignGrade()
			<< ", execute grade: " << obj.getExecuteGrade() << ", is signed: "
			<< "yes.";
	return out;
}
