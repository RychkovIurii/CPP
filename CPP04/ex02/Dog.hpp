/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:42 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 12:21:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain* _brain;

	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &obj );
		Dog &operator=(const Dog &obj);
		void makeSound( void ) const override;
		void setIdeas( std::string str ) const;
		void getIdea( void ) const;
};
