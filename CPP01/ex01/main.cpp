/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:55:09 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 16:50:11 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	horde = nullptr;
	Zombie*	horde2 = nullptr;

	try
	{
		horde = zombieHorde(5, "First Horde");
		horde2 = zombieHorde(3, "Second Horde");
		for (int i = 0; i < 5; i++)
		{
			horde[i].announce();
		}
		for (int i = 0; i < 3; i++)
		{
			horde2[i].announce();
		}
		delete [] horde;
		delete [] horde2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		delete [] horde;
		return (1);
	}
	return (0);
}
