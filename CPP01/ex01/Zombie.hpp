/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:55:24 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 13:33:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie( void );
		~Zombie( void );
		void	announce( void );
		void	setName( std::string name );
	private:
		std::string	name_;
};

Zombie* zombieHorde( int N, std::string name );

#endif
