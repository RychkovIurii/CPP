/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/07 11:34:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iterator> 

class Span {
	private:
		int* _array;
		unsigned int _size;
		unsigned int _count;
	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span& other) = delete;
		Span& operator=(const Span& other) = delete;
		~Span();
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename Iterator>
		void addManyNumbers(Iterator begin, Iterator end) {
			auto dist = std::distance(begin, end);
			if (dist <= 0) {
				throw std::invalid_argument("Invalid iterator range: end is before or equal to begin");
			}
			unsigned int numbersToAdd = static_cast<unsigned int>(dist);
			if (std::numeric_limits<unsigned int>::max() - _count < numbersToAdd) {
				throw std::overflow_error("Too many numbers to add");
			}
			if (_count + numbersToAdd > _size) {
				throw std::overflow_error("Not enough space to add all numbers");
			}
			for (Iterator it = begin; it != end; ++it) {
				addNumber(*it);
			}
		}
};
