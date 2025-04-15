/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:34 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 15:54:10 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain* _brain;

	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &obj );
		Cat &operator=(const Cat &obj);
		void makeSound( void ) const override;
};
