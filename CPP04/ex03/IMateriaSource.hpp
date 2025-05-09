/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:09:47 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/22 10:58:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource( void ) = default;
		IMateriaSource( const IMateriaSource &obj ) = default;
		IMateriaSource &operator=( const IMateriaSource &obj ) = default;
		virtual ~IMateriaSource( void ) = default;
		virtual void learnMateria( AMateria* ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;
};
