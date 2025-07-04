/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:42:56 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 13:59:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"
#include <stdexcept>

template <class T>
Array<T>::Array() : array(nullptr), length(0) {}

template <class T>
Array<T>::Array(unsigned int n) : length(n) {
	if (n > 0) {
		array = new T[n](); // () initializes primitive types to zero
	} else {
		array = nullptr;
	}
}

template <class T>
Array<T>::Array(const Array &other) : length(other.length) {
	if (length > 0) {
		array = new T[length];
		for (unsigned int i = 0; i < length; ++i) {
			array[i] = other.array[i];
		}
	} else {
		array = nullptr;
	}
}

template <class T>
Array<T>::~Array() {
	if (array) {
		delete[] array;
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		if (array) {
			delete[] array;
		}
		length = other.length;
		if (length > 0) {
			array = new T[length];
			for (unsigned int i = 0; i < length; ++i) {
				array[i] = other.array[i];
			}
		} else {
			array = nullptr;
		}
	}
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= length) {
		throw std::out_of_range("Index is out of bounds");
	}
	return array[index];
}

template <class T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= length) {
		throw std::out_of_range("Index is out of bounds");
	}
	return array[index];
}

template <class T>
unsigned int Array<T>::size() const {
	return length;
}
