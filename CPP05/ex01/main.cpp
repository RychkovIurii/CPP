/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/24 10:55:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void test_low_sign_grade( void )
{
	try
	{
		Form("A1", 200, 2);
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
		Form("A1", -5, 2);
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
		Form("A1", 2, 200);
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
		Form("A1", 2, 0);
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

static void test_bureaucrat_low_both( void );
static void test_bureaucrat_high_both( void );
static void test_bureaucrat_low_sign( void );
static void test_bureaucrat_high_sign( void );
static void test_bureaucrat_low_execute( void );
static void test_bureaucrat_high_execute( void );
static void test_bureaucrat_valid( void );

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
	std::cout << "====================Test valid==================================" << std::endl;
	test_valid();
	std::cout << std::endl;

	return (0);
}
