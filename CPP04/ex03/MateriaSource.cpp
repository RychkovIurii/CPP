/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:10:53 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 10:57:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource :: MateriaSource( void )
{
	std::cout << "Default constructor for MateriaSource" << std::endl;
	_materiaCount = 0;
	for (int i = 0; i < 4; i++)
		_materias[i] = nullptr;
}

MateriaSource :: MateriaSource( const MateriaSource &obj )
{
	std::cout << "Copy constructor for MateriaSource" << std::endl;
	if (this != &obj)
	{
		_materiaCount = obj._materiaCount;
		for (int i = 0; i < 4; i++)
		{
			if (obj._materias[i])
				_materias[i] = obj._materias[i]->clone();
			else
				_materias[i] = nullptr;
		}
	}
}

MateriaSource &MateriaSource :: operator=(const MateriaSource &obj)
{
	std::cout << "Copy assignment operator for MateriaSource" << std::endl;
	if (this != &obj)
	{
		_materiaCount = obj._materiaCount;
		for (int i = 0; i < 4; i++)
		{
			if (obj._materias[i])
				_materias[i] = obj._materias[i]->clone();
			else
				_materias[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource :: ~MateriaSource( void )
{
	std::cout << "Destructor for MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

void MateriaSource :: learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot learn a null pointer" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == nullptr)
		{
			_materias[i] = m;
			std::cout << "Learned " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Materia source is full, cannot learn " << m->getType() << std::endl;
}

AMateria *MateriaSource :: createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
		{
			std::cout << "Created " << type << std::endl;
			return _materias[i]->clone();
		}
	}
	std::cout << "Unknown materia type: " << type << std::endl;
	return nullptr;
}
