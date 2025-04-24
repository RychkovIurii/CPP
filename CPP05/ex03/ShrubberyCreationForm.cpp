/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:59:42 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 15:43:38 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm :: ShrubberyCreationForm( std::string target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

void ShrubberyCreationForm :: execute( Bureaucrat const &executor ) const
{
	if (!_isSigned)
		throw AForm::NeedToSign();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
		throw FileError();
	file << "    *    " << std::endl;
	file << "   ***   " << std::endl;
	file << "  *****  " << std::endl;
	file << " ******* " << std::endl;
	file << "   _|_   " << std::endl;
}

const char *ShrubberyCreationForm::FileError::what() const throw()
{
	return "Could not create new file";
}
