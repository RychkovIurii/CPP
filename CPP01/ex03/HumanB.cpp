/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:11:57 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 12:14:38 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB :: HumanB( std::string name ) : name(name) {
	weapon = nullptr;
}

HumanB :: ~HumanB( void ) {}

void	HumanB :: attack( void )
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " just swears, because they have no weapon" << std::endl;
}

void	HumanB :: setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
