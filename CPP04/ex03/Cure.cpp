/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 16:50:50 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure :: Cure( void )
{
	std::cout << "Default constructor for Cure" << std::endl;
	_type = "Cure";
}

Cure :: ~Cure( void )
{
	std::cout << "Destructor for Cure" << std::endl;
}

Cure :: Cure ( const Cure &obj )
{
	std::cout << "Copy constructor for Cure" << std::endl;
	if (this != &obj)
		_type = obj._type;
}

Cure &Cure :: operator=(const Cure &obj)
{
	std::cout << "Copy assignment operator for Cure" << std::endl;
	if (this != &obj)
		_type = obj._type;
	return *this;
}

Cure :: Cure( std::string const & type )
{
	std::cout << "Default constructor for Cure" << std::endl;
	_type = type;
}

std::string const &Cure :: getType( void ) const // Think
{
	return (_type);
}

void Cure :: use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure *Cure :: clone() const 
{
	//new
}
