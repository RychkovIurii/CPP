/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:15 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 12:50:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice :: Ice( void ) : AMateria("ice")
{
	std::cout << "Default constructor for Ice" << std::endl;
}

Ice :: ~Ice( void )
{
	std::cout << "Destructor for Ice" << std::endl;
}

Ice :: Ice ( const Ice &obj )
{
	std::cout << "Copy constructor for Ice" << std::endl;
	if (this != &obj)
		_type = obj._type;
}


void Ice :: use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice :: clone() const 
{
	return new Ice(*this);
}
