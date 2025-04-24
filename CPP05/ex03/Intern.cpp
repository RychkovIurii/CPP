/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:29:28 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 18:02:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern :: Intern( void )
{
	forms[0] = "ShrubberyCreationForm";
	forms[1] = "RobotomyRequestForm";
	forms[2] = "PresidentialPardonForm";
	functions[0] = &Intern::getShrubbery;
	functions[1] = &Intern::getRobotomy;
	functions[2] = &Intern::getPresidential;
	functions[3] = &Intern::getError;
}

AForm* Intern :: getShrubbery (std::string formTarget)
{
	std::cout << "Intern creates " << forms[0] << std::endl;
	return new ShrubberyCreationForm(formTarget);
}

AForm* Intern :: getRobotomy (std::string formTarget)
{
	std::cout << "Intern creates " << forms[1] << std::endl;
	return new RobotomyRequestForm(formTarget);
}

AForm* Intern :: getPresidential(std::string formTarget)
{
	std::cout << "Intern creates " << forms[2] << std::endl;
	return new PresidentialPardonForm(formTarget);
}

AForm* Intern :: getError(std::string formTarget)
{
	(void)formTarget;
	/* throw FormNotFound(); */
	std::cout << "The Form doesn't exist" << std::endl;
	return (nullptr);
}

AForm* Intern :: makeForm( std::string formName, std::string formTarget)
{
	int index = 0;
	while (index < 3 && forms[index] != formName)
		index++;
	return (this->*functions[index])(formTarget);
}

/* const char *Intern::FormNotFound::what() const throw()
{
	return "The Form doesn't exist";
}
 */
