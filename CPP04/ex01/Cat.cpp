/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:31 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 12:29:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat( void )
{
	type = "Cat";
	std::cout << "Constructor for Cat" << std::endl;
}

Cat :: ~Cat( void )
{
	std::cout << "Destructor for Cat" << std::endl;
}

Cat :: Cat ( const Cat &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy constructor for Cat" << std::endl;
}

Cat &Cat :: operator=(const Cat &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy assignment operator for Cat" << std::endl;
	return *this;
}

void Cat :: makeSound( void ) const
{
	std::cout << "MEOWWWWWWWWWWWWWWWWWWWwwwwwwwwwwww!" << std::endl;
}
