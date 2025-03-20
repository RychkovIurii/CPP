/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:36:00 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 12:35:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie :: Zombie( std::string name ) : name_(name) { }

Zombie :: ~Zombie( void )
{
	std::cout << name_ << ": We call the destructor"<< std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name_ << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
