/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:01:29 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 15:34:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap :: ScavTrap( void )
{
	_name = "default";
	_hit_points = 0;
	_energy_points = 0;
	_attack_damage = 0;
	_class_name = "ScavTrap ";
	std::cout << "Default ScavTrap constuctor called." << std::endl;
}

ScavTrap :: ScavTrap( std::string name )
{
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	_class_name = "ScavTrap ";
	std::cout << _class_name << _name << " constuctor called." << std::endl;
}

ScavTrap :: ~ScavTrap( void )
{
	std::cout << "ScavTrap " << _name << " destructor called." << std::endl;
}

ScavTrap :: ScavTrap( const ScavTrap &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << _class_name << _name
		<< " copy constructor called." << std::endl;
}

ScavTrap &ScavTrap :: operator=( const ScavTrap &obj )
{
	if (this != &obj)
	{
		_name = obj._name;
		_hit_points = obj._hit_points;
		_energy_points = obj._energy_points;
		_attack_damage = obj._attack_damage;
		_class_name = obj._class_name;
	}
	std::cout << _class_name << _name
		<< " overloaded equal called." << std::endl;
	return (*this);
}

void ScavTrap :: guardGate( void )
{
	std::cout << _class_name << _name
		<< " is now in Gatekeeper mode." << std::endl;
}
