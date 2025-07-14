/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/14 11:46:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

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
		std::vector<int> vec(input);
		std::deque<int> deq(input.begin(), input.end());

		std::cout << "Before: ";
		for (size_t i = 0; i < input.size(); ++i) {
			if (i != 0)
				std::cout << " ";
			std::cout << input[i];
		}
		std::cout << std::endl;
	} catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
