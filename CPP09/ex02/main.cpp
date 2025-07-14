/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/14 12:11:28 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <iomanip>

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
			int num = std::stoi(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative numbers are not allowed.");
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

		std::vector<int> vec(input);
		auto startTimeForVector = std::chrono::high_resolution_clock::now();
		PmergeMe::sortVector(vec);
		auto endTimeForVector = std::chrono::high_resolution_clock::now();

		std::deque<int> deq(input.begin(), input.end());
		auto startTimeForDeque = std::chrono::high_resolution_clock::now();
		PmergeMe::sortDeque(deq);
		auto endTimeForDeque = std::chrono::high_resolution_clock::now();
		
		std::cout << "After: ";
		for (size_t i = 0; i < input.size(); ++i) {
			if (i != 0)
				std::cout << " ";
			std::cout << input[i];
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
