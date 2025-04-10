/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:01:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/10 12:03:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	private:
		std::string	_name;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap ( const ScavTrap &obj);
		~ScavTrap ( void );
		ScavTrap &operator=( const ScavTrap &obj );
		void guardGate( void );
		void attack( const std::string& target );
};
