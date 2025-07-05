/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 11:06:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
};
