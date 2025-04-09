/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:05:30 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 15:34:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap :: FragTrap( void )
{
	_name = "default";
	_hit_points = 0;
	_energy_points = 0;
	_attack_damage = 0;
	_class_name = "FragTrap ";
	std::cout << "Default FragTrap constuctor called." << std::endl;
}

FragTrap :: FragTrap( std::string name )
{
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	_class_name = "FragTrap ";
	std::cout << _class_name << _name << " constuctor called." << std::endl;
}

FragTrap :: ~FragTrap( void )
{
	std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}

FragTrap :: FragTrap( const FragTrap &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << _class_name << _name
		<< " copy constructor called." << std::endl;
}

FragTrap &FragTrap :: operator=( const FragTrap &obj )
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

void FragTrap :: highFivesGuys( void )
{
	std::cout << _class_name << _name
		<< " displays a positive high fives request." << std::endl;
}
