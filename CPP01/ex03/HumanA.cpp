/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:12:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 12:14:02 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA :: HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon) {}

HumanA :: ~HumanA( void ) {}

void	HumanA :: attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
