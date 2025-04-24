/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 15:34:19 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	Bureaucrat joe("Joe", 1);
	ShrubberyCreationForm	form1("OUR_TARGET");
	RobotomyRequestForm		form2("OUR_TARGET");
	PresidentialPardonForm	form3("OUR_TARGET");
	joe.executeForm(form1);
	joe.executeForm(form2);
	joe.executeForm(form3);
	joe.signForm(form1);
	joe.signForm(form2);
	joe.signForm(form3);
	joe.executeForm(form1);
	joe.executeForm(form2);
	joe.executeForm(form3);
	return (0);
}
