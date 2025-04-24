/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:06:13 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 15:09:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm :: RobotomyRequestForm( std::string target)
	: AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

void RobotomyRequestForm :: execute( Bureaucrat const &executor ) const
{
	if (!_isSigned)
		throw AForm::NeedToSign();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();

	std::cout << "Makes some drilling noises..." << std::endl;
	std::cout << "\tMakes some drilling noises..." << std::endl;
	std::cout << "\t\tMakes some drilling noises..." << std::endl;

	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, 1);
	if (dis(gen) == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}
