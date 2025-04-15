/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 13:36:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string type;
	public:
		Animal( void );
		 virtual ~Animal( void );
		Animal( const Animal &obj );
		Animal &operator=(const Animal &obj);
		virtual void makeSound( void) const;
		std::string getType( void ) const;
};
