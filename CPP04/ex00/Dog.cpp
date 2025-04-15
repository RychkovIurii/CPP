/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:38 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 18:24:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog( void )
{
	type = "Dog";
	std::cout << "Constructor for Dog" << std::endl;
}

Dog :: ~Dog( void )
{
	std::cout << "Destructor for Dog" << std::endl;
}

Dog :: Dog ( const Dog &obj )
{
	std::cout << "Copy constructor for Dog" << std::endl;
	if (this != &obj)
		type = obj.type;
}

Dog &Dog :: operator=(const Dog &obj)
{
	std::cout << "Copy assignment operator for Dog" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

void Dog :: makeSound( void ) const
{
	std::cout << "BARK BARK BARK!" << std::endl;
}
