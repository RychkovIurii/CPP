/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 18:14:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <exception>

int testCorrectAnimals()
{
	int result;
	const Animal* meta = nullptr;
	const Animal* dog = nullptr;
	const Animal* cat = nullptr;

	result = 0;
	try {
		meta = new Animal();
		dog = new Dog();
		cat = new Cat();

		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		cat->makeSound();
		dog->makeSound();
		meta->makeSound();

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		result = 1;
	}	

	delete dog;
	delete cat;
	delete meta;

	std::cout << "We finished correct animal test." << std::endl;
	std::cout << std::endl;
	return (result);
}

int testWrongAnimals()
{
	int result;
	const WrongAnimal* meta_wrong = nullptr;
	const WrongAnimal* wrong_cat = nullptr;

	result = 0;
	try {
		meta_wrong = new WrongAnimal();
		wrong_cat = new WrongCat();

		std::cout << wrong_cat->getType() << std::endl;

		wrong_cat->makeSound();
		meta_wrong->makeSound();

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		result = 1;
	}

	delete wrong_cat;
	delete meta_wrong;

	std::cout << "We finished wrong animal test." << std::endl;
	std::cout << std::endl;
	return (result);
}

int	main( void )
{
	int test1;
	int test2;

	test1 = testCorrectAnimals();
	test2 = testWrongAnimals();
	if (test1 > test2)
		return (test1);
	return (test2);
}


//TEST FOR BASIC OPERATIONS
