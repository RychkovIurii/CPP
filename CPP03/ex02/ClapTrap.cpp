/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:55:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 14:01:51 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <climits>

ClapTrap :: ClapTrap( void )
{
	_name = "default";
	_hit_points = 0;
	_energy_points = 0;
	_attack_damage = 0;
	_class_name = "ClapTrap ";
	std::cout << "Default ClapTrap constuctor called." << std::endl;
}

ClapTrap :: ClapTrap( std::string name )
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	_class_name = "ClapTrap ";
	std::cout << _class_name << _name << " constuctor called." << std::endl;
}

ClapTrap :: ~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}

ClapTrap :: ClapTrap( const ClapTrap &obj )
{
	if (this != &obj)
		*this = obj;
	std::cout << _class_name << _name
		<< " copy constructor called." << std::endl;
}

ClapTrap &ClapTrap :: operator=( const ClapTrap &obj )
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

void ClapTrap :: attack( const std::string& target )
{
	if (!_energy_points || !_hit_points)
		return ;
	_energy_points--;
	std::cout << _class_name << _name << " attacks "
		<< target << ", causing "<< _attack_damage
		<< " points of damage!" << std::endl;
}

void ClapTrap :: takeDamage( unsigned int amount )
{
	long long int sum;
	if (!_hit_points)
		return ;
	sum = static_cast<long long int>(_hit_points)
		- static_cast<long long int>(amount);
	if (sum < 0)
	{
		amount = _hit_points;
		_hit_points = 0;
	}
	else
		_hit_points -= amount;
	std::cout << _class_name << _name << " takes "
		<< amount << " of damage. The hit is " << _hit_points
		<< "." << std::endl;
}

void ClapTrap :: beRepaired( unsigned int amount )
{
	long long int sum;
	if (!_energy_points || !_hit_points)
		return ;
	_energy_points--;
	sum = static_cast<long long int>(_hit_points)
		+ static_cast<long long int>(amount);
	if (sum > UINT_MAX)
	{
		sum = UINT_MAX - _hit_points;
		_hit_points = UINT_MAX;
		std::cout << _class_name << _name << " repairs itself for "
		<< sum << ". The hit is maximum right now - "
		<< _hit_points << "." << std::endl;
	}
	else
	{
		_hit_points = static_cast<unsigned int>(sum);
		std::cout << _class_name << _name << " repairs itself for "
			<< amount << ". The hit is " << _hit_points 
			<< "." << std::endl;
	}
}
