/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/03 17:38:24 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implement the following function templates:
• swap: Swaps the values of two given parameters. Does not return anything.
• min: Compares the two values passed as parameters and returns the smallest one.
If they are equal, it returns the second one.
• max: Compares the two values passed as parameters and returns the greatest one.
If they are equal, it returns the second one.
These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators. */

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
