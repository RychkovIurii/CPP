/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:44 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:39:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMagic.hpp"

class Polymorph : public AMagic {
	public:
		Polymorph();
		virtual ~Polymorph();
		virtual AMagic * clone() const override;
};