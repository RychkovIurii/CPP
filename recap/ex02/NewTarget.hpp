/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewTarget.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:13:47 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:39:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ATarget.hpp"

class NewTarget : public ATarget {
	public:
		NewTarget();
		virtual ~NewTarget();
		virtual ATarget * clone() const override;
};
