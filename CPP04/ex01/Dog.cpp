/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:38 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 15:59:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog( void )
{
	type = "Dog";
	_brain = nullptr;
	_brain = new Brain();
	std::cout << "Constructor for Dog" << std::endl;
}

Dog :: ~Dog( void )
{
	delete _brain;
	std::cout << "Destructor for Dog" << std::endl;
}

Dog :: Dog ( const Dog &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy constructor for Dog" << std::endl;
}

Dog &Dog :: operator=(const Dog &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy assignment operator for Dog" << std::endl;
	return *this;
}

void Dog :: makeSound( void ) const
{
	std::cout << "BARK BARK BARK!" << std::endl;
}
