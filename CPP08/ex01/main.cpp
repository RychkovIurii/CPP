/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:30 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 11:17:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>

int main() {
	try {
		std::cout << "==== Valid Span Example:" << std::endl;
		Span span(5);
		span.addNumber(1);
		span.addNumber(5);
		span.addNumber(2);
		span.addNumber(10);
		span.addNumber(8);

		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

		std::cout << "==== Large Span Example:" << std::endl;
		std::srand(std::time(nullptr));
		Span sp(10000);

		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "==== Exception Handling Example:" << std::endl;
		try {
			span.addNumber(7); 
		} catch (const std::overflow_error& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span emptySpan(0);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span singleElementSpan(1);
			singleElementSpan.addNumber(42);
			singleElementSpan.shortestSpan();
		} catch (const std::logic_error& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span singleElementSpan(1);
			singleElementSpan.addNumber(42);
			singleElementSpan.longestSpan();
		} catch (const std::logic_error& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span singleElementSpan(1);
			singleElementSpan.addNumber(42);
			singleElementSpan.addNumber(42);
		} catch (const std::overflow_error& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
