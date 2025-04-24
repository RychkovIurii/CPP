/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:59:42 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:48:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm :: ShrubberyCreationForm( std::string target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "Create a file <target>_shrubbery in the working directory, \
	and writes ASCII trees inside it." << std::endl;
}

void ShrubberyCreationForm :: execute( Bureaucrat const &executor ) const
{
	if (!_isSigned)
		throw AForm::NeedToSign();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}
