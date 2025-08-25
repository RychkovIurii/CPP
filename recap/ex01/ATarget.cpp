/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:33:46 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 16:55:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "AMagic.hpp"
#include <iostream>

ATarget :: ATarget(const std::string &typeInput) {
	_type = typeInput;
}

ATarget :: ~ATarget( void ) {}

const std::string &ATarget :: getType( void ) const {
	return _type;
}

void ATarget :: getHitBySpell( AMagic const &obj ) const{
	std::cout << getType() << " has been " << obj.getEffects() << "!" << std::endl;
}
