/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:20:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 12:55:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character :: Character( void )
{
	std::cout << "Default constructor for Character" << std::endl;
	_name = "default";
	_droppedCount = 0;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
		_droppedMaterials[i] = nullptr;
	}
}

Character :: Character(const std::string name)
{
	std::cout << "Constructor for Character" << std::endl;
	_name = name;
	_droppedCount = 0;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
		_droppedMaterials[i] = nullptr;
	}
}

Character :: Character( const Character &obj )
{
	std::cout << "Copy constructor for Character" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_droppedCount = obj._droppedCount;
		for (int i = 0; i < 4; i++)
		{
			if (obj._droppedMaterials[i])
				_droppedMaterials[i] = obj._droppedMaterials[i]->clone();
			else
				_droppedMaterials[i] = nullptr;
			if (obj._inventory[i])
				_inventory[i] = obj._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
}

Character &Character :: operator=(const Character &obj)
{
	std::cout << "Copy assignment operator for Character" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_droppedCount = obj._droppedCount;
		for (int i = 0; i < 4; i++)
		{
			if (_droppedMaterials[i])
				delete _droppedMaterials[i];
			if (obj._droppedMaterials[i])
				_droppedMaterials[i] = obj._droppedMaterials[i]->clone();
			else
				_droppedMaterials[i] = nullptr;
			if (_inventory[i])
				delete _inventory[i];
			if (obj._inventory[i])
				_inventory[i] = obj._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return *this;
}

Character :: ~Character( void )
{
	std::cout << "Destructor for Character" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (_droppedMaterials[i])
			delete _droppedMaterials[i];
	}
}

std::string const &Character :: getName( void ) const
{
	return (_name);
}

void Character :: equip(AMateria* m)
{
	if(!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
}

void Character::addDroppedMateria(AMateria* m)
{
	if (!m)
		return ;

	if (_droppedCount < 4)
	{
		_droppedMaterials[_droppedCount++] = m;
		std::cout << "Material unequipped, left on the ground: " << m->getType() << std::endl;
	}
	else
	{
		delete _droppedMaterials[0];
		for (int i = 1; i < 4; ++i)
			_droppedMaterials[i - 1] = _droppedMaterials[i];
		_droppedMaterials[3] = m;
		std::cout << "Dropped materials are full. Replaced the oldest material: " << m->getType() << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == nullptr)
		return ;
	AMateria* tmp = _inventory[idx];
	_inventory[idx] = nullptr;
	addDroppedMateria(tmp);
	std::cout << "Slot " << idx << " is now empty" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == nullptr)
		return ;
	_inventory[idx]->use(target);
}

void Character::listDroppedMaterias()
{
	std::cout << "Dropped materials:" << std::endl;
	for (int i = 0; i < _droppedCount; i++)
	{
		std::cout << _droppedMaterials[i]->getType() << std::endl;
	}
}
