/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/27 11:41:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void test_low_sign_grade( void )
{
	try
	{
		Form form("A1", 200, 2);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_high_sign_grade( void )
{
	try
	{
		Form form("A1", -5, 2);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_low_execute_grade( void )
{
	try
	{
		Form form("A1", 2, 200);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_high_execute_grade( void )
{
	try
	{
		Form form("A1", 2, 0);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_valid( void )
{
	try
	{
		Form form("A1", 5, 5);
		std::cout << "Both are valid" << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_high_both( void )
{
	try
	{
		Form form("A1", 1, 1);
		Bureaucrat bureaucrat("Leo", 5);
		form.beSigned(bureaucrat);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_high_sign( void )
{
	try
	{
		Form form("A1", 1, 10);
		Bureaucrat bureaucrat("Leo", 5);
		form.beSigned(bureaucrat);
		std::cout << "We are here" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}


static void test_bureaucrat_high_execute( void )
{
	try
	{
		Form form("A1", 10, 1);
		Bureaucrat bureaucrat("Leo", 5);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_sign_twice( void )
{
	try
	{
		Form form("A1", 10, 10);
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_sign_form_high_sign( void )
{
	try
	{
		Form form("A1", 1, 10);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_sign_form_high_exec( void )
{
	try
	{
		Form form("A1", 10, 1);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_valid( void )
{
	try
	{
		Form form("A1", 10, 10);
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_equal( void )
{
	try
	{
		Form form("A1", 5, 5);
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_bureaucrat_sign_form( void )
{
	try
	{
		Form form("A1", 10, 10);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat("Leo", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

int main( void )
{
	std::cout << "====================Test low signGrade==========================" << std::endl;
	test_low_sign_grade();
	std::cout << std::endl;
	std::cout << "====================Test high signGrade=========================" << std::endl;
	test_high_sign_grade();
	std::cout << std::endl;
	std::cout << "====================Test low executeGrade=======================" << std::endl;
	test_low_execute_grade();
	std::cout << std::endl;
	std::cout << "====================Test high executeGrade======================" << std::endl;
	test_high_execute_grade();
	std::cout << std::endl;
	std::cout << "====================Test valid form=============================" << std::endl;
	test_valid();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat's grade too low for exec and sign========" << std::endl;
	test_bureaucrat_high_both();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat's grade too low for sign=================" << std::endl;
	test_bureaucrat_high_sign();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat's grade too low for exec=================" << std::endl;
	test_bureaucrat_high_execute();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat signed twice=============================" << std::endl;
	test_bureaucrat_sign_twice();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat sign form high sign======================" << std::endl;
	test_sign_form_high_sign();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat sign form high exec======================" << std::endl;
	test_sign_form_high_exec();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat valid====================================" << std::endl;
	test_bureaucrat_valid();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat's grade equal form's values =============" << std::endl;
	test_bureaucrat_equal();
	std::cout << std::endl;
	std::cout << "=======Test bureaucrat signForm==================================" << std::endl;
	test_bureaucrat_sign_form();
	std::cout << std::endl;

	return (0);
}
