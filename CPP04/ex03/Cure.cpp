/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 12:50:36 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure :: Cure( void ) : AMateria("cure")
{
	std::cout << "Default constructor for Cure" << std::endl;
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


void Cure :: use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure :: clone() const 
{
	return new Cure(*this);
}
