/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/21 13:59:20 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <exception>

int	main( void )
{
	Character character("Player");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	character.equip(ice);
	character.equip(cure);

	character.unequip(0);
	character.unequip(1);
	character.unequip(2);

	character.listDroppedMaterias();
	return (0);
}
