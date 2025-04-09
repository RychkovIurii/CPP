/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:05:34 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/09 14:16:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	
	public:
		FragTrap( void ) = delete;
		FragTrap( std::string name );
		FragTrap ( const FragTrap &obj);
		~FragTrap ( void );
		FragTrap &operator=( const FragTrap &obj );
		void highFivesGuys( void );
};
