/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:20:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 13:58:17 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AMateria {

	protected:
		std::string _type;

	public:
		AMateria( void );
		virtual ~AMateria( void );
		AMateria( const AMateria &obj );
		AMateria &operator=(const AMateria &obj);

		AMateria( std::string const & type );
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
