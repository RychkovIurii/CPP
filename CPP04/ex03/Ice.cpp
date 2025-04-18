/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:15 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 16:50:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice :: Ice( void )
{
	std::cout << "Default constructor for Ice" << std::endl;
	_type = "ice";
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

Ice &Ice :: operator=(const Ice &obj)
{
	std::cout << "Copy assignment operator for Ice" << std::endl;
	if (this != &obj)
		_type = obj._type;
	return *this;
}

Ice :: Ice( std::string const & type )
{
	std::cout << "Default constructor for Ice" << std::endl;
	_type = type;
}

std::string const &Ice :: getType( void ) const // Think
{
	return (_type);
}

void Ice :: use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *Ice :: clone() const 
{
	//new
}
