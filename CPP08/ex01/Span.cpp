/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:36 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 11:07:13 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : _size(N) {
	if (N == 0) {
		throw std::invalid_argument("Size must be greater than zero");
	}
	_array = new int[N]();
	_count = 0;
}

Span::~Span() {
	delete[] _array;
}

void Span::addNumber(int number) {
	if (_count >= _size) {
		throw std::overflow_error("Span is full");
	}
	_array[_count++] = number;
}

unsigned int Span::shortestSpan() const {
	if (_count < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	std::vector<int> sorted(_array, _array + _count);
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < _count; ++i) {
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_count < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	int minElement = *std::min_element(_array, _array + _count);
	int maxElement = *std::max_element(_array, _array + _count);
	return static_cast<unsigned int>(maxElement - minElement);
}
