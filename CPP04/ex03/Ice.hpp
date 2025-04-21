/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:18 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/21 10:32:54 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		virtual ~Ice( void );
		Ice( const Ice &obj );
		Ice &operator=(const Ice &obj);
		virtual void use(ICharacter& target) override;
		virtual AMateria* clone() const override;
};
