/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 11:53:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>

int	main( void )
{
	{
		const Animal* dog = nullptr;
		const Animal* cat = nullptr;
		try {
			dog = new Dog();
			dog->makeSound();
			cat = new Cat();
			cat->makeSound();
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		delete dog;
		delete cat;
		std::cout << "We finished basic animal test." << std::endl;
		std::cout << std::endl;
	}
	{
		const int amount = 4;
		const Animal* array[amount] = {};
		try {
			for(int i = 0; i < amount; i++)
			{
				if (i % 2 == 0)
					array[i] = new Cat();
				else
					array[i] = new Dog();
			}
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		for(int i = 0; i < amount; i++)
		{
			delete array[i];
		}

	}
	{
		try {
			const Cat cat_milk;
			cat_milk.setIdeas("Milk");
			Cat cat_fish;
			cat_fish = cat_milk;
			cat_fish.setIdeas("Fish");
			cat_milk.getIdea();
			cat_fish.getIdea();
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "We finished copy brain test." << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
