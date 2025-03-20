/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:55:21 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 17:01:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie :: Zombie( void ) { }

Zombie :: ~Zombie( void )
{
	std::cout << name_ << ": We call the destructor"<< std::endl;
}

void	Zombie :: announce( void )
{
	std::cout << name_ << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie :: setName( std::string name )
{
	name_ = name;
}
