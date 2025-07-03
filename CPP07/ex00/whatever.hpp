/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/03 17:42:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* template <typename T> vs template <class T>
- class is the original keyword from C++98.
- typename was introduced later to improve clarity: it makes more sense to say "a type parameter."
- class remained for backward compatibility. */

template <class T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
T min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

template <class T>
T max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}
