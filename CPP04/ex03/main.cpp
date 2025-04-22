/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 11:34:56 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <exception>

static int test_basic( void )
{
	int result;

	std::cout << "=============== Test basic ===============" << std::endl;
	AMateria* ice = nullptr;
	AMateria* cure = nullptr;
	AMateria* empty = nullptr;
	result = 0;
	try {
		Character character("Player");
		ice = new Ice();
		cure = new Cure();
		std::cout << std::endl;

		character.equip(empty);
		std::cout << std::endl;

		character.equip(ice);
		character.equip(cure);
		character.equip(new Ice());
		std::cout << std::endl;

		character.unequip(0);
		character.unequip(1);
		character.unequip(2);
		character.unequip(3);
		character.unequip(4);
		std::cout << std::endl;

		character.listDroppedMaterias();
	} catch (std::exception &e) {
		result = 1;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (result);
}

static int test_equip_max ( void )
{
	int result;

	std::cout << "=============== Test test_equip_max ===============" << std::endl;
	AMateria* ice = nullptr;
	result = 0;
	try {
		Character character("Player");
		ice = new Ice();
		std::cout << std::endl;

		character.equip(new Ice());
		character.equip(new Ice());
		character.equip(new Ice());
		character.equip(new Ice());
		character.equip(ice);
		std::cout << std::endl;

	} catch (std::exception &e) {
		result = 1;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	delete ice;
	return (result);
}

static int test_subject( void )
{
	int result;

	std::cout << "=============== Test subject ===============" << std::endl;
	IMateriaSource* src = nullptr;
	ICharacter* me = nullptr;
	AMateria* tmp = nullptr;
	ICharacter* bob = nullptr;
	result = 0;
	try {
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		me = new Character("me");
		tmp = src->createMateria("ice");
		std::cout << std::endl;

		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
	} catch (std::exception &e) {
		result = 1;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	delete bob;
	delete me;
	delete src;
	return (result);
}

int	main( void )
{
	if (test_basic())
	{
		std::cout << "Test test_basic failed" << std::endl;
		return (1);
	}
	std::cout << "Test test_basic passed" << std::endl;
	if (test_equip_max())
	{
		std::cout << "Test test_equip_max failed" << std::endl;
		return (1);
	}
	std::cout << "Test test_equip_max passed" << std::endl;
	if (test_subject())
	{
		std::cout << "Test test_subject failed" << std::endl;
		return (1);
	}
	std::cout << "Test test_subject passed" << std::endl;
	std::cout << "All tests passed" << std::endl;
	return (0);
}
