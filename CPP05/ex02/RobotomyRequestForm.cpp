/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:06:13 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:18:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm :: RobotomyRequestForm( std::string target)
	: AForm("RobotomyRequestForm", 72, 45)
{
	(void)target;
	std::cout << "Makes some drilling noises. Then, informs that <target> \
	has been robotomized successfully 50% of the time. \
	Otherwise, informs that the robotomy failed." << std::endl;
}

void RobotomyRequestForm :: execute( Bureaucrat const &executor ) const
{
	(void)executor;
}
