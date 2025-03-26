/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:54:36 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/26 10:03:14 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Zombie*	newStackZombie( std::string name )
{
	Zombie*	zombie;
	Zombie	new_zombie(name);
	zombie = &new_zombie;
	return (zombie);
} */

/* In the next line we are trying to access the instance
of the object that was destroyed */
	/* Zombie *zombie2 = newStackZombie("Stack guy");
	zombie2->announce(); */

int	main()
{
	Zombie*	zombie = nullptr;
	try
	{
		zombie = newZombie("Allocated guy");
		zombie->announce();
		delete zombie;
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return (1);
	}
	randomChump("Random stack guy");
	return (0);
}
