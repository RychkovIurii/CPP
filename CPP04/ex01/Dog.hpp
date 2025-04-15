/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:42 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 12:29:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
	public:
	Dog( void );
	~Dog( void );
	Dog( const Dog &obj );
	Dog &operator=(const Dog &obj);
	void makeSound( void ) const override;
};
