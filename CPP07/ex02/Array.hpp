/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:35:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 11:42:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T> class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;
	private:
		T *array;
		unsigned int length;
};
