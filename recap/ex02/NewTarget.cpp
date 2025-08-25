/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewTarget.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:13:44 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:21:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewTarget.hpp"

NewTarget :: NewTarget() : ATarget("someType") {}

NewTarget :: ~NewTarget() {}

ATarget * NewTarget ::clone() const {
	return new NewTarget();
}
