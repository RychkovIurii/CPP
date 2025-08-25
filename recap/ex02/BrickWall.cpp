/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:54 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:36:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall :: BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall :: ~BrickWall() {}

ATarget * BrickWall ::clone() const {
	return new BrickWall();
}