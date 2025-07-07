/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:30 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/07 11:38:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <list>

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
		Span spLarge(10000);

		for (int i = 0; i < 10000; ++i) {
			spLarge.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << spLarge.shortestSpan() << std::endl;
		std::cout << "Longest span: " << spLarge.longestSpan() << std::endl;

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

		std::cout << "==== Adding Many Numbers Example:" << std::endl;
		Span manyNumbersSpan(10);
		int numbersToAdd[] = {1, 3, 5, 7, 9};
		manyNumbersSpan.addManyNumbers(numbersToAdd, numbersToAdd + 5);
		std::cout << "Shortest span after adding many numbers: " << manyNumbersSpan.shortestSpan() << std::endl;
		std::cout << "Longest span after adding many numbers: " << manyNumbersSpan.longestSpan() << std::endl;

		std::cout << "==== Adding Many Numbers with Valid Range:" << std::endl;
		std::vector<int> v(10000);
		for (int& n : v) n = std::rand();
		Span largeSpan(10000);
		try {
			largeSpan.addManyNumbers(v.begin(), v.end());
			std::cout << "Added 10000 numbers successfully." << std::endl;
			std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
			std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception while adding many numbers: " << e.what() << std::endl;
		}

		std::cout << "==== Adding Many Numbers with Invalid Range:" << std::endl;
		std::vector<int> v1(10);
		for (int& n : v1) n = std::rand();
		Span invalidSpan(10);
		try {
			invalidSpan.addManyNumbers(v1.begin(), v1.begin()); // Empty range
			std::cout << "Added numbers successfully." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception many numbers: " << e.what() << std::endl;
		}
		try {
			invalidSpan.addManyNumbers(v1.end(), v1.begin()); // Invalid range
			std::cout << "Added numbers successfully." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception many numbers: " << e.what() << std::endl;
		}

		std::cout << "==== Adding Many Numbers with Overflow:" << std::endl;
		std::list<int> l(10);
		Span overflowSpan(5);
		try {
			overflowSpan.addManyNumbers(l.begin(), l.end());
			std::cout << "Added numbers successfully." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		std::cout << "==== Tests provided by the subject:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
