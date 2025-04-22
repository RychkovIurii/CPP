/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:24:43 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 15:33:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void test_increase( void )
{
	try
	{
		Bureaucrat juri("Juri", 1);
		std::cout << juri << std::endl;
		juri.increaseGrade();
		std::cout << juri << std::endl;		// we won't see this line
		juri.decreaseGrade();				// we won't see this line
		std::cout << juri << std::endl;		// we won't see this line
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_decrease( void )
{
	try
	{
		Bureaucrat juri("Juri", 150);
		std::cout << juri << std::endl;
		juri.decreaseGrade();
		std::cout << juri << std::endl;		// we won't see this line
		juri.increaseGrade();				// we won't see this line
		std::cout << juri << std::endl;		// we won't see this line
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

static void test_create( void )
{
	try
	{
		Bureaucrat juri("Juri", 0);
		std::cout << juri << std::endl;		// we won't see this line
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
		Bureaucrat juri("Juri", 150);
		std::cout << juri << std::endl;
		juri.increaseGrade();
		std::cout << juri << std::endl;
		juri.decreaseGrade();
		std::cout << juri << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

int main( void )
{
	std::cout << "====================Test increase====================" << std::endl;
	test_increase();
	std::cout << std::endl;
	std::cout << "====================Test decrease====================" << std::endl;
	test_decrease();
	std::cout << std::endl;
	std::cout << "====================Test create======================" << std::endl;
	test_create();
	std::cout << std::endl;
	std::cout << "====================Test valid=======================" << std::endl;
	test_valid();
	std::cout << std::endl;

	return (0);
}
