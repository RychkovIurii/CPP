/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:20:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 13:32:49 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal :: AAnimal( void )
{
	std::cout << "Constructor for AAnimal" << std::endl;
	type = "base";
}

AAnimal :: ~AAnimal( void )
{
	std::cout << "Destructor for AAnimal" << std::endl;
}

AAnimal :: AAnimal ( const AAnimal &obj )
{
	std::cout << "Copy constructor for AAnimal" << std::endl;
	if (this != &obj)
		type = obj.type;
}

AAnimal &AAnimal :: operator=(const AAnimal &obj)
{
	std::cout << "Copy assignment operator for AAnimal" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

std::string AAnimal :: getType( void ) const
{
	return (type);
}
