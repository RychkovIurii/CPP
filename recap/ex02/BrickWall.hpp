/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:57 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:38:47 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget {
	public:
		BrickWall();
		virtual ~BrickWall();
		virtual ATarget * clone() const override;
};
