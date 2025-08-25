/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSpell.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:13:39 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:24:48 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSpell.hpp"

NewSpell :: NewSpell() : AMagic("someName", "someEffect") {}

NewSpell :: ~NewSpell() {}

AMagic * NewSpell ::clone() const {
	return new NewSpell();
}
