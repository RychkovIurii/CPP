/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:11:53 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 12:14:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB {
	public:
		HumanB( std::string name );
		~HumanB( void );
		void attack( void );
		void setWeapon( Weapon &weapon );
	private:
		std::string name;
		Weapon *weapon;
};

#endif
