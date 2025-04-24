/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:07:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:18:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm( std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	(void)target;
	std::cout << "Informs that <target> has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm :: execute( Bureaucrat const &executor ) const
{
	(void)executor;
}
