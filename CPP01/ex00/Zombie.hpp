/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:33:29 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 12:26:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void );
	private:
		std::string	name_;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
