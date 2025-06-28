/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:42:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/06/28 17:46:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

static bool isValid(const std::string &input) {
	size_t dotCount = 0;
	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '-' || input[i] == '+') {
			if (i != 0) { // Sign must be at the beginning
				return false;
			}
		} else if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f') {
			// If it's not a digit, a dot, or 'f', it's invalid
			return false;
		} else if (input[i] == 'f' && i != input.length() - 1) {
			// 'f' must be at the end of the string
			return false;
		} else if (input[i] == '.') {
			// Count dots to ensure there's only one
			dotCount++;
			if (dotCount > 1) {
				return false; // More than one dot is invalid
			}
		}
	}
	return true; // If we passed all checks, it's valid
}

void ScalarConverter::convert(const std::string &input) {

	if (input.empty()) { // Check for empty input and we can check for other invalid inputs
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (input == "nan" || input == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	
	if (input == "-inf" || input == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	if (input == "+inf" || input == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}

	if (!isValid(input)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	// Check if the input is a character
	// If the input is a single character, we can convert it directly
	// How can we split logic to handle 0 as a number and as a character?
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	// Check if the input is a valid integer


	// Here we implement the logic to convert the input string to float and double
}	
