/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 17:53:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>

static void test_valid( void )
{
	Bureaucrat joe("Joe", 1);
	Intern intern;
	AForm *form;
	form = intern.makeForm("RobotomyRequestForm", "TARGET");
	joe.signForm(*form);
	joe.executeForm(*form);
	delete form;
}

int main( void )
{
	try {
		std::cout << "==============Test test_valid==============" << std::endl;
		test_valid();
		std::cout << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << "You catch me! " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
