/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:47 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:34:46 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph :: Polymorph() : AMagic("Polymorph", "turned into a critter") {}

Polymorph :: ~Polymorph() {}

AMagic * Polymorph ::clone() const {
	return new Polymorph();
}