/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:31 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 11:46:23 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat( void )
{
	std::cout << "Constructor for Cat" << std::endl;
	type = "Cat";
	_brain = nullptr;
	_brain = new Brain();
}

Cat :: ~Cat( void )
{
	std::cout << "Destructor for Cat" << std::endl;
	delete _brain;
}

Cat :: Cat ( const Cat &obj )
{
	std::cout << "Copy constructor for Cat" << std::endl;
	if (this != &obj)
	{
		_brain = new Brain(*obj._brain);
		type = obj.type;
	}
}

Cat &Cat :: operator=(const Cat &obj)
{
	std::cout << "Copy assignment operator for Cat" << std::endl;
	if (this != &obj)
	{
		if (_brain)
			delete _brain;
		_brain = new Brain(*obj._brain);
		type = obj.type;
	}
	return *this;
}

void Cat :: makeSound( void ) const
{
	std::cout << "MEOWWWWWWWWWWWWWWWWWWWwwwwwwwwwwww!" << std::endl;
}

void Cat :: setIdeas( std::string str ) const
{
	std::cout << "We set idea " << str << " for Cat" << std::endl;
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
	std::cout << "We get idea for Cat" << std::endl;
	if (_brain)
		std::cout << _brain->ideas[0] << std::endl;
}
