/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:45:03 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 10:04:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("Value not found!");
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("Value not found!");
	}
	return it;
}
