/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:12:00 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 12:14:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA {
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );
		void attack( void );
	private:
		std::string name;
		Weapon &weapon;
};

#endif
