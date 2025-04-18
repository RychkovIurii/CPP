/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 16:49:20 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );
		~Cure( void );
		Cure( const Cure &obj );
		Cure &operator=(const Cure &obj);
		void use(ICharacter& target) override;
		Ice* clone() const override;
};
