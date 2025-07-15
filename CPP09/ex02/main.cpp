/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/15 11:46:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <cctype>

bool isValidNumber(const std::string &arg, int &num) {
	if (arg.empty()) {
		std::cerr << "Error: Empty argument is not a valid number." << std::endl;
		return false;
	}
	size_t start = 0;
	if (arg[0] == '+' || arg[0] == '-') {
		start = 1;
		if (arg.length() == 1) {
			std::cerr << "Error: Invalid number format: " << arg << std::endl;
			return false;
		}
	}
	for (size_t i = start; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i])) {
			std::cerr << "Error: Invalid number format: " << arg << std::endl;
			return false;
		}
	}
	try {
		num = std::stoi(arg);
		if (num < 0) {
			std::cerr << "Error: Negative numbers are not allowed: " << arg << std::endl;
			return false;
		}
	} catch (const std::out_of_range &) {
		std::cerr << "Error: Number out of range: " << arg << std::endl;
		return false; // Number is too large
	} catch (const std::invalid_argument &) {
		std::cerr << "Error: Invalid number format: " << arg << std::endl;
		return false; // Invalid number format
	}
	return true; // Valid number
}
	

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return 0;
	}
	try
	{
		// Main logic to process the input numbers
		std::vector<int> input;
		for (int i = 1; i < argc; ++i) {
			std::string arg = argv[i];
			int num;
			// Validate the number format
			if (!isValidNumber(arg, num)) {
				return 1; // Exit if invalid number
			}
			input.push_back(num);
		}

		std::cout << "Before: ";
		for (size_t i = 0; i < input.size(); ++i) {
			if (i != 0)
				std::cout << " ";
			std::cout << input[i];
		}
		std::cout << std::endl;

		/* The indication of the time is deliberately strange in this example.
		Of course you have to indicate the time used to perform all your
		operations, both the sorting part and the data management part.
		*/
		auto startTimeForVector = std::chrono::high_resolution_clock::now();
		std::vector<int> vec(input);
		PmergeMe::sortVector(vec);
		auto endTimeForVector = std::chrono::high_resolution_clock::now();

		auto startTimeForDeque = std::chrono::high_resolution_clock::now();
		std::deque<int> deq(input.begin(), input.end());
		PmergeMe::sortDeque(deq);
		auto endTimeForDeque = std::chrono::high_resolution_clock::now();
		
		std::cout << "After: ";
		for (size_t i = 0; i < vec.size(); ++i) {
			if (i != 0)
				std::cout << " ";
			std::cout << vec[i];
		}
		std::cout << std::endl;

		std::chrono::duration<double, std::micro> durationForVector = endTimeForVector - startTimeForVector;
		std::chrono::duration<double, std::micro> durationForDeque = endTimeForDeque - startTimeForDeque;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << vec.size()
				<< " elements with std::vector : " << durationForVector.count() << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size()
				<< " elements with std::deque  : " << durationForDeque.count() << " us" << std::endl;
			
	} catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
