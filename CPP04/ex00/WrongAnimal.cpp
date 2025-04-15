/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:48:35 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 18:25:53 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal( void )
{
	type = "Wrongbase";
	std::cout << "Constructor for WrongBASE" << std::endl;
}

WrongAnimal :: ~WrongAnimal( void )
{
	std::cout << "Destructor for WrongBASE" << std::endl;
}

WrongAnimal :: WrongAnimal ( const WrongAnimal &obj )
{
	std::cout << "Copy constructor for WrongBASE" << std::endl;
	if (this != &obj)
		type = obj.type;
}

WrongAnimal &WrongAnimal :: operator=(const WrongAnimal &obj)
{
	std::cout << "Copy assignment operator for WrongBASE" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

void WrongAnimal :: makeSound( void ) const
{
	std::cout << "I'm a WrongANIMAL!" << std::endl;
}

std::string WrongAnimal :: getType( void ) const
{
	return (type);
}
