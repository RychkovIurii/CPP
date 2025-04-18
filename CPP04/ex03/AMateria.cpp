/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:20:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 13:58:00 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria :: AMateria( void )
{
	std::cout << "Default constructor for AMateria" << std::endl;
	_type = "base";
}

AMateria :: ~AMateria( void )
{
	std::cout << "Destructor for AMateria" << std::endl;
}

AMateria :: AMateria ( const AMateria &obj )
{
	std::cout << "Copy constructor for AMateria" << std::endl;
	if (this != &obj)
		_type = obj._type;
}

AMateria &AMateria :: operator=(const AMateria &obj)
{
	std::cout << "Copy assignment operator for AMateria" << std::endl;
	if (this != &obj)
		_type = obj._type;
	return *this;
}

AMateria :: AMateria( std::string const & type )
{
	std::cout << "Default constructor for AMateria" << std::endl;
	_type = type;
}

std::string const &AMateria :: getType( void ) const
{
	return (_type);
}

void AMateria :: use( ICharacter& target )
{
	std::cout << "U CALL use FOR BASE AMATERIA" << std::endl;
}


