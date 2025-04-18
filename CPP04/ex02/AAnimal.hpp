/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:20:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 12:22:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {

	protected:
		std::string type;
	public:
		AAnimal( void );
		 virtual ~AAnimal( void );
		AAnimal( const AAnimal &obj );
		AAnimal &operator=(const AAnimal &obj);
		virtual void makeSound( void) const = 0;
		std::string getType( void ) const;
};
