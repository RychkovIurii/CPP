/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:10 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:32:36 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.hpp"
#include "ATarget.hpp"
#include "AMagic.hpp"
#include <iostream>
#include "NewSpell.hpp"
#include "NewTarget.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "Fireball.hpp"

int main( void )
{
	{
		Unit richard("Richard", "foo");
		richard.setTitle("Hello, I'm Richard the Unit!");
		BrickWall model1;

		Polymorph* polymorph = new Polymorph();
		TargetGenerator tarGen;

		tarGen.learnTargetType(&model1);
		richard.learnSpell(polymorph);

		Fireball* fireball = new Fireball();

		richard.learnSpell(fireball);

		ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

		richard.introduce();
		richard.launchSpell("Polymorph", *wall);
		richard.launchSpell("Fireball", *wall);
	}

  return (0);
}