/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/10 12:53:13 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal :: Animal( void )
{
	type = "base";
	std::cout << "Constructor for BASE" << std::endl;
}

Animal :: ~Animal( void )
{
	std::cout << "Destructor for BASE" << std::endl;
}

Animal :: Animal ( const Animal &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy constructor for BASE" << std::endl;
}

Animal &Animal :: operator=(const Animal &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy assignment operator for BASE" << std::endl;
	return *this;
}

void Animal :: makeSound( void )
{
	std::cout << "I'm an ANIMAL!" << std::endl;
}
