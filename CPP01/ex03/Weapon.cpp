/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:12:19 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/21 10:11:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: Weapon( std::string type ) : type(type) {}

Weapon :: ~Weapon( void ) {}

const std::string &Weapon :: getType( void ) const
{
	return (type);
}

void Weapon :: setType( std::string type )
{
	this->type = type;
}
