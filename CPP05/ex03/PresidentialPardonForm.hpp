/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:58:02 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 14:42:02 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm( void ) = delete;
		PresidentialPardonForm( std::string target);
		virtual ~PresidentialPardonForm( void ) = default;
		PresidentialPardonForm( PresidentialPardonForm const &obj ) = delete;
		PresidentialPardonForm &operator=( PresidentialPardonForm const &obj ) = delete;
		virtual void execute( Bureaucrat const &executor ) const;
};
