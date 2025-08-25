/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:29:04 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:31:09 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball :: Fireball() : AMagic("Fireball", "burnt to a crisp") {}

Fireball :: ~Fireball() {}

AMagic * Fireball ::clone() const {
	return new Fireball();
}