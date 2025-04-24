/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:07:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:43:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm( std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

void PresidentialPardonForm :: execute( Bureaucrat const &executor ) const
{
	if (!_isSigned)
		throw AForm::NeedToSign();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
