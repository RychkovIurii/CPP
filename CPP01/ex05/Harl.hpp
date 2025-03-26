/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:31:36 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/26 12:37:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string levels[4];
		void (Harl::*functions[4])( void );
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};
