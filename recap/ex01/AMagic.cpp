/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMagic.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:33:56 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 16:29:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMagic.hpp"
#include "ATarget.hpp"
#include <iostream>

class ATarget;

AMagic :: AMagic(const std::string &nameInput, const std::string &effectsInput) {
	_name = nameInput;
	_effects = effectsInput;
	//std::cout << getName() << ": Constructor." << std::endl;
}

AMagic :: ~AMagic( void ) {
	//std::cout << getName() << ": Destructor." << std::endl;
}

std::string AMagic :: getName( void ) const {
	return _name;
}

std::string AMagic :: getEffects( void ) const {
	return _effects;
}

void AMagic :: launch(ATarget const &obj) const {
	obj.getHitBySpell(*this);
}