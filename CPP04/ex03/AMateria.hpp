/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:20:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 12:12:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

	protected:
		std::string _type;

	public:
		AMateria( void );
		virtual ~AMateria( void );
		AMateria( const AMateria &obj );
		AMateria &operator=(const AMateria &obj) = delete;

		AMateria( std::string const & type );
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
