/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:29:00 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:30:58 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMagic.hpp"

class Fireball : public AMagic {
	public:
		Fireball();
		virtual ~Fireball();
		virtual AMagic * clone() const override;
};
