/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/14 12:01:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <cstddef>

extern std::size_t g_comparisonCount;

static std::size_t F(int n) {
		std::size_t sum = 0;
		for (int k = 1; k <= n; ++k) {
				double value = (3.0 / 4.0) * k;
				sum += static_cast<std::size_t>(std::ceil(std::log2(value)));
		}
		return sum;
}

/**
 * Validates if a string represents a valid positive integer.
 * 
 * @param arg The string to validate
 * @param num Reference to store the parsed number if valid
 * @return true if the string is a valid positive integer, false otherwise
 */
static bool isValidNumber(const std::string &arg, int &num) {
	// Check for empty string
	if (arg.empty()) {
		std::cerr << "Error: Empty argument is not a valid number." << std::endl;
		return false;
	}
	
	// Handle optional '+' sign (negative numbers will be rejected later)
	size_t start = 0;
	if (arg[0] == '+' || arg[0] == '-') {
		start = 1;
		if (arg.length() == 1) {
			std::cerr << "Error: Invalid number format: " << arg << std::endl;
			return false;
		}
	}
	
	// Validate that all characters after the optional sign are digits
	for (size_t i = start; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i])) {
			std::cerr << "Error: Invalid number format: " << arg << std::endl;
			return false;
		}
	}
	
	// Parse the number and validate range
	try {
		num = std::stoi(arg);
		if (num < 0) {
			std::cerr << "Error: Negative numbers are not allowed: " << arg << std::endl;
			return false;
		}
	} catch (const std::out_of_range &) {
		std::cerr << "Error: Number out of range: " << arg << std::endl;
		return false;
	} catch (const std::invalid_argument &) {
		std::cerr << "Error: Invalid number format: " << arg << std::endl;
		return false;
	}
	
	return true;
}

/**
 * Parses command line arguments into a vector of integers.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return Vector containing the parsed integers, or empty vector on error
 */
static std::vector<int> parseArguments(int argc, char **argv) {
	std::vector<int> input;
	
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		int num;
		
		if (!isValidNumber(arg, num)) {
			return std::vector<int>(); // Return empty vector on error
		}
		
		input.push_back(num);
	}
	
	return input;
}

/**
 * Prints a sequence of numbers with proper formatting.
 * 
 * @param label Label to print before the numbers (e.g., "Before:", "After:")
 * @param container Container holding the numbers to print
 */
template<typename Container>
static void printSequence(const std::string &label, const Container &container) {
	std::cout << label;
	for (size_t i = 0; i < container.size(); ++i) {
		if (i != 0)
			std::cout << " ";
		std::cout << container[i];
	}
	std::cout << std::endl;
}

/**
 * Measures and prints the execution time for sorting operations.
 * 
 * @param input The input vector to sort
 */
static void performSortingBenchmark(const std::vector<int> &input) {
	// Benchmark vector sorting
	g_comparisonCount = 0;
	auto startTimeForVector = std::chrono::high_resolution_clock::now();
	std::vector<int> vec(input);
	PmergeMe::sortVector(vec);
	auto endTimeForVector = std::chrono::high_resolution_clock::now();
	std::size_t vectorComparisons = g_comparisonCount;

	// Benchmark deque sorting
	g_comparisonCount = 0;
	auto startTimeForDeque = std::chrono::high_resolution_clock::now();
	std::deque<int> deq(input.begin(), input.end());
	PmergeMe::sortDeque(deq);
	auto endTimeForDeque = std::chrono::high_resolution_clock::now();
	std::size_t dequeComparisons = g_comparisonCount;
	
	// Verify sorting correctness
	PmergeMe::verifySorting(vec, deq);
	
	// Print results
	printSequence("After: ", vec);

	std::size_t maxComp = F(vec.size());
	std::cout << "Actual vector comparisons: " << vectorComparisons << std::endl;
	std::cout << "Actual deque comparisons: " << dequeComparisons << std::endl;
	std::cout << "Max comparisons F(n): " << maxComp << std::endl;


	// Calculate and display timing results
	std::chrono::duration<double, std::micro> durationForVector = endTimeForVector - startTimeForVector;
	std::chrono::duration<double, std::micro> durationForDeque = endTimeForDeque - startTimeForDeque;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::vector : " << durationForVector.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			<< " elements with std::deque  : " << durationForDeque.count() << " us" << std::endl;
}
	

/**
 * Main function - entry point of the program.
 * Implements the Ford-Johnson merge-insertion sort algorithm benchmark.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return 0 on success, 1 on error
 */
int main(int argc, char **argv) {
	// Check for minimum required arguments
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <positive_integers>" << std::endl;
		return 0;
	}
	
	try {
		// Parse and validate input arguments
		std::vector<int> input = parseArguments(argc, argv);
		if (input.empty()) {
			return 1; // Error occurred during parsing
		}
		
		// Display original sequence
		printSequence("Before: ", input);
		
		// Perform sorting benchmark and display results
		performSortingBenchmark(input);
		
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
