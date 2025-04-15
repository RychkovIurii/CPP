/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 15:46:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>

int	main( void )
{
	const Animal* dog = nullptr;
	const Animal* cat = nullptr;
	try {
		dog = new Dog();
		cat = new Cat();
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	delete dog;
	delete cat;
	return 0;
}
