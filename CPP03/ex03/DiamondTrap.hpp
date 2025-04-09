/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:29:12 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap( void ) = delete;
		DiamondTrap( std::string name );
		DiamondTrap ( const DiamondTrap &obj);
		~DiamondTrap ( void );
		DiamondTrap &operator=( const DiamondTrap &obj );
		void whoAmI( void );
};
