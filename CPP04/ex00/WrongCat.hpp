/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:48:25 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 14:00:33 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	WrongCat( void );
	~WrongCat( void );
	WrongCat( const WrongCat &obj );
	WrongCat &operator=(const WrongCat &obj);
	void makeSound( void ) const;
};
