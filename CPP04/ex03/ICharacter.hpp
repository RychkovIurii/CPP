/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:09:42 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/21 13:44:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		ICharacter( void ) = default;
		ICharacter(const ICharacter &obj) = default;
		ICharacter &operator=(const ICharacter &obj) = default;
		virtual ~ICharacter() = default;

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
