/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:31 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 18:12:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat( void )
{
	type = "Cat";
	_brain = nullptr;
	_brain = new Brain();
	std::cout << "Constructor for Cat" << std::endl;
}

Cat :: ~Cat( void )
{
	delete _brain;
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
	{
		if (_brain)
			delete _brain;
		_brain = new Brain(*obj._brain);
		type = obj.type;
	}
	std::cout << "Copy assignment operator for Cat" << std::endl;
	return *this;
}

void Cat :: makeSound( void ) const
{
	std::cout << "MEOWWWWWWWWWWWWWWWWWWWwwwwwwwwwwww!" << std::endl;
}

void Cat :: setIdeas( std::string str ) const
{
	if (_brain)
	{
		for(int i = 0; i < 100; i++)
		{
			_brain->ideas[i] = str;
		}
	}
}

void Cat :: getIdea( void ) const
{
	if (_brain)
		std::cout << _brain->ideas[0] << std::endl;
}
