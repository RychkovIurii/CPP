/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:48:28 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 14:04:44 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat( void )
{
	type = "WrongCat";
	std::cout << "Constructor for WrongCat" << std::endl;
}

WrongCat :: ~WrongCat( void )
{
	std::cout << "Destructor for WrongCat" << std::endl;
}

WrongCat :: WrongCat ( const WrongCat &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy constructor for WrongCat" << std::endl;
}

WrongCat &WrongCat :: operator=(const WrongCat &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy assignment operator for WrongCat" << std::endl;
	return *this;
}

void WrongCat :: makeSound( void ) const
{
	std::cout << "MEOWWWWWWWWWWWWWWWWWWWwwwwwwwwwwww!" << std::endl;
}
