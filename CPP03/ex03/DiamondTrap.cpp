/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:29:15 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/10 12:05:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap :: DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hit_points = FragTrap :: _hit_points;
	_energy_points = ScavTrap :: _energy_points;
	_attack_damage = FragTrap :: _attack_damage;
	_class_name = "DiamondTrap ";
	std::cout << _class_name << _name << " constuctor called." << std::endl;
}

DiamondTrap :: ~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << _name << " destructor called." << std::endl;
}

DiamondTrap :: DiamondTrap( const DiamondTrap &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << _class_name << _name
		<< " copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap :: operator=( const DiamondTrap &obj )
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

void DiamondTrap :: whoAmI( void )
{
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap ::_name << std::endl;
}

void DiamondTrap :: attack( const std::string& target )
{
	ScavTrap :: attack(target);
}
