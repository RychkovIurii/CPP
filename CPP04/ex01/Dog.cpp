/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:38 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 11:52:50 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog( void )
{
	std::cout << "Constructor for Dog" << std::endl;
	type = "Dog";
	_brain = nullptr;
	_brain = new Brain();
}

Dog :: ~Dog( void )
{
	std::cout << "Destructor for Dog" << std::endl;
	delete _brain;
}

Dog :: Dog ( const Dog &obj )
{
	std::cout << "Copy constructor for Dog" << std::endl;
	if (this != &obj)
	{
		_brain = new Brain(*obj._brain);
		type = obj.type;
	}
}

Dog &Dog :: operator=(const Dog &obj)
{
	std::cout << "Copy assignment operator for Dog" << std::endl;
	if (this != &obj)
	{
		if (_brain)
			delete _brain;
		_brain = new Brain(*obj._brain);
		type = obj.type;
	}
	return *this;
}

void Dog :: makeSound( void ) const
{
	std::cout << "BARK BARK BARK!" << std::endl;
}

void Dog :: setIdeas( std::string str ) const
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

void Dog :: getIdea( void ) const
{
	std::cout << "We get idea for Cat" << std::endl;
	if (_brain)
		std::cout << _brain->ideas[0] << std::endl;
}
