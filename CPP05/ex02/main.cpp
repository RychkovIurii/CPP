/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 16:20:07 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

#define GRADE 1

static void test_execute_unsigned( void )
{
	Bureaucrat joe("Joe", GRADE);
	ShrubberyCreationForm	form1("OUR_TARGET");
	RobotomyRequestForm		form2("OUR_TARGET");
	PresidentialPardonForm	form3("OUR_TARGET");
	joe.executeForm(form1);
	joe.executeForm(form2);
	joe.executeForm(form3);
}

static void test_joe_sign_mike_exec( void )
{
	Bureaucrat joe("Joe", 1);
	Bureaucrat pekka("Pekka", 150);
	Bureaucrat mike("Mike", 1);
	RobotomyRequestForm	form1("OUR_TARGET");
	joe.signForm(form1);
	pekka.executeForm(form1);
	mike.executeForm(form1);
}

static void test_sign( void )
{
	Bureaucrat joe("Joe", GRADE);
	ShrubberyCreationForm	form1("OUR_TARGET");
	RobotomyRequestForm		form2("OUR_TARGET");
	PresidentialPardonForm	form3("OUR_TARGET");
	joe.signForm(form1);
	joe.signForm(form2);
	joe.signForm(form3);
	joe.executeForm(form1);
	joe.executeForm(form2);
	joe.executeForm(form3);
}

int main( void )
{
	try {
		//AForm form("A1", 10, 10); // only if you wanna test abstract
		std::cout << "=====Test test_execute_unsigned============" << std::endl;
		test_execute_unsigned();
		std::cout << std::endl;
		std::cout << "=====Test test_joe_sign_mike_exec==========" << std::endl;
		test_joe_sign_mike_exec();
		std::cout << std::endl;
		std::cout << "=====Test test_sign========================" << std::endl;
		test_sign();
		std::cout << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << "You catch me! " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
