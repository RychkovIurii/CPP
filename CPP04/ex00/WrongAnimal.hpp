/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:48:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 14:41:09 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {

	protected:
		std::string type;
	public:
		WrongAnimal( void );
		virtual ~WrongAnimal( void );
		WrongAnimal( const WrongAnimal &obj );
		WrongAnimal &operator=(const WrongAnimal &obj);
		void makeSound( void) const;
		std::string getType( void ) const;
};
