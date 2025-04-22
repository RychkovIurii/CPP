/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:33:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 12:16:51 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );
		virtual ~Cure( void );
		Cure( const Cure &obj );
		Cure &operator=(const Cure &obj) = delete;
		virtual void use(ICharacter& target) override;
		virtual AMateria* clone() const override;
};
