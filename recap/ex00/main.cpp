/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:10 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 15:29:47 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.hpp"
#include <iostream>

int main()
{
	{
		//Unit bob;                            //Does not compile
		Unit bob("Bob", "the mag");  //Compiles
		Unit jim("Jim", "the nope");   //Compiles
		//bob = jim;                              //Does not compile
		//Unit jack(jim);                      //Does not compile
	}
	std::cout << std::endl;
	{
		Unit const richard("Richard", "Mister");
		richard.introduce();
		std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

		Unit* jack = new Unit("Jack", "the Long");
		jack->introduce();
		jack->setTitle("the Might");
		jack->introduce();

		delete jack;
	}

  return (0);
}