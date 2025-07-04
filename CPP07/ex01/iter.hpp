/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:51:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 11:08:13 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <class T, class F>
void iter(T *array, size_t length, F func) {
	if (!array || length == 0) {
		return;
	}
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}
