/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:12:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 12:10:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class	Weapon {
	public:
		Weapon( std::string type );
		~Weapon( void );
		const std::string &getType( void ) const;
		void setType( std::string type );
	private:
		std::string type;
};

#endif
