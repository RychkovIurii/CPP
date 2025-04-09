/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:07 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 13:20:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {

	protected:
		std::string		_name;
		unsigned int	_hit_points;
		int				_energy_points;
		int				_attack_damage;
		std::string		_class_name;

	public:
		ClapTrap( void );
		ClapTrap( std::string name);
		ClapTrap( const ClapTrap &obj);
		~ClapTrap( void );
		ClapTrap &operator=( const ClapTrap &obj );
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};
