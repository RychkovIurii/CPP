/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:18 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 16:49:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		~Ice( void );
		Ice( const Ice &obj );
		Ice &operator=(const Ice &obj);
		void use(ICharacter& target) override;
		Ice* clone() const override;
};
