/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:24:24 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 18:29:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern {
	private:
		AForm* getShrubbery(std::string formTarget);
		AForm* getRobotomy(std::string formTarget);
		AForm* getPresidential(std::string formTarget);
		AForm* getError(std::string formTarget);
		std::string forms[3];
		AForm* (Intern::*functions[4])( std::string formTarget );
		class FormNotFound : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		Intern( void );
		~Intern( void ) = default;
		Intern( Intern const &obj ) = delete;
		Intern &operator=( Intern const &obj ) = delete;
		AForm* makeForm( std::string formName, std::string formTarget);
};
