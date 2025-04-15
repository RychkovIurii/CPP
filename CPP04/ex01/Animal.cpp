/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 18:19:34 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal :: Animal( void )
{
	type = "base";
	std::cout << "Constructor for Animal" << std::endl;
}

Animal :: ~Animal( void )
{
	std::cout << "Destructor for Animal" << std::endl;
}

Animal :: Animal ( const Animal &obj )
{
	std::cout << "Copy constructor for Animal" << std::endl;
	if (this != &obj)
		this->type = obj.type;
}

Animal &Animal :: operator=(const Animal &obj)
{
	std::cout << "Copy assignment operator for Animal" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Animal :: makeSound( void ) const
{
	std::cout << "I'm an ANIMAL!" << std::endl;
}

std::string Animal :: getType( void ) const
{
	return (type);
}
