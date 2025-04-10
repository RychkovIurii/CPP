/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/10 12:41:18 by irychkov         ###   ########.fr       */
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
		~Animal( void );
		Animal( const Animal &obj );
		Animal &operator=(const Animal &obj);
		void makeSound( void );
}
