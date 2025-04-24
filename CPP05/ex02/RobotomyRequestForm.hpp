/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:57:29 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:24:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void ) = delete;
		RobotomyRequestForm( std::string target);
		virtual ~RobotomyRequestForm( void ) = default;
		RobotomyRequestForm( RobotomyRequestForm const &obj ) = delete;
		RobotomyRequestForm &operator=( RobotomyRequestForm const &obj ) = delete;
		virtual void execute( Bureaucrat const &executor ) const;
};
