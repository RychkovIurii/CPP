/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:02 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/08 11:21:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	basic_test( void )
{
	ClapTrap first("Joe");
	ClapTrap second("Leo");
	second = first;
	ClapTrap third(first);
}

int	main ( void )
{
	basic_test();
	std::cout << "Test finished!\n" << std::endl;
	ClapTrap pekka("Pekka");
	pekka.attack("Jaakko");
	pekka.takeDamage(10);
	pekka.beRepaired(10);

	return (0);
}
