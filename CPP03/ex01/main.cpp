/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:02 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 13:58:00 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	basic_test( void )
{
	ClapTrap nick;
	nick.attack("Mike");
	std::cout << std::endl;

	std::cout << "\t\tWe execute: ScavTrap joe('Joe');"
		<< std::endl << std::endl;
	ScavTrap joe("Joe");
	std::cout << std::endl;

	std::cout << "\t\tWe execute: ScavTrap leo('Leo');"
		<< std::endl << std::endl;
	ScavTrap leo("Leo");
	std::cout << std::endl;

	std::cout << "\t\tWe execute: leo = joe;"
		<< std::endl << std::endl;
	leo = joe;
	std::cout << std::endl;

	std::cout << "\t\tWe execute: ScavTrap pekka(joe);"
		<< std::endl << std::endl;
	ScavTrap pekka(joe);
	std::cout << std::endl;

	std::cout << "\t\tWe see destructors" << std::endl << std::endl;
}

void	overflow_be_repaired( void )
{
	ScavTrap pekka("Pekka");
	pekka.beRepaired(1);
	pekka.beRepaired(4294967295);	// Pekka repairs itself till max_hp
	pekka.beRepaired(1);			// Pekka repairs itself for 0. Now is max_hp
}

void	overflow_take_damage( void )
{
	ScavTrap juho("Juho");
	juho.takeDamage(2);
	juho.beRepaired(1);
	juho.takeDamage(4294967295);	// Juho takes only 99. Hp is 99
	juho.takeDamage(1);				// We won't see, because we don't have hits
	juho.beRepaired(1);				// We won't see, because we don't have hits
	juho.attack("Santeri");			// We won't see, because we don't have hits

}

void	attack_test( void )		// Only attack and beRepaired cost 1 energy point
{
	ScavTrap mika("Mika");
	mika.takeDamage(1);			// Doesn't affect energy points
	mika.takeDamage(1);			// Doesn't affect energy points
	mika.beRepaired(1);
	mika.attack("Juho");
	std::cout << std::endl;
	for (int i = 0; i < 60; i++)
	{
		mika.attack("Pekka");	// Mika attacks only when has energy points
		std::cout << "Counter is " << i + 1 << std::endl;
	}
	mika.guardGate();
}

int	main ( void )
{
	basic_test();
	std::cout << "Test basic_test finished!\n" << std::endl;
	
 	overflow_be_repaired();
	std::cout << "Test overflow_be_repaired finished!\n" << std::endl;

	overflow_take_damage();
	std::cout << "Test overflow_take_damage finished!\n" << std::endl;

	attack_test();
	std::cout << "Test attack_test finished!\n" << std::endl;

	return (0);
}
