/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 13:35:09 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>

static int testBasicAAnimalBehavior()
{
	std::cout << std::endl;
	std::cout << "\t\t\t=== Test 1: Basic AAnimal Behavior ===" << std::endl;

	const AAnimal* dog = nullptr;
	const AAnimal* cat = nullptr;
	
	/* cannot declare variable 'animal' to be of abstract type 'AAnimal' */
	//AAnimal animal; 

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


int	main( void )
{
	if (testBasicAAnimalBehavior())
		return (1);
	return (0);
}
