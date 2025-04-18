/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 12:08:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>

static int testBasicAnimalBehavior()
{
	std::cout << std::endl;
	std::cout << "\t\t\t=== Test 1: Basic Animal Behavior ===" << std::endl;

	const Animal* dog = nullptr;
	const Animal* cat = nullptr;

	int result = 0;
	try {
		dog = new Dog();
		dog->makeSound();

		cat = new Cat();
		cat->makeSound();
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		result = 1;
	}

	delete dog;
	delete cat;

	std::cout << "\t\t\tWe finished basic animal test." << std::endl;
	std::cout << std::endl;
	return (result);
}

static int testAnimalArray()
{
	std::cout << std::endl;
	std::cout << "\t\t\t=== Test 2: Array of Cats and Dogs ===" << std::endl;

	const int amount = 4;
	const Animal* array[amount] = {};

	int result = 0;
	try {
		for (int i = 0; i < amount; i++) {
			if (i % 2 == 0)
				array[i] = new Cat();
			else
				array[i] = new Dog();
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		result = 1;
	}

	for (int i = 0; i < amount; i++) {
		delete array[i];
	}

	std::cout << "\t\t\tWe finished array of animals test." << std::endl;
	std::cout << std::endl;
	return (result);
}

static int testDeepCopyBrain()
{
	std::cout << std::endl;
	std::cout << "\t\t\t=== Test 3: Deep Copy of Brain ===" << std::endl;

	int result = 0;
	try {
		const Cat cat_milk;
		cat_milk.setIdeas("Milk");

		Cat cat_fish;
		cat_fish = cat_milk;
		cat_fish.setIdeas("Fish");

		cat_milk.getIdea();  // Should show "Milk"
		cat_fish.getIdea();  // Should show "Fish"
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		result = 1;
	}

	std::cout << "\t\t\tWe finished copy brain test." << std::endl;
	std::cout << std::endl;
	return (result);
}


int	main( void )
{
	if (testBasicAnimalBehavior())
		return (1);
	if (testAnimalArray())
		return (1);
	if (testDeepCopyBrain())
		return (1);
	return (0);
}
