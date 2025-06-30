/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:42:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/06/30 10:13:22 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>

static bool isValid(const std::string &input) {
	if (input.length() == 3 && input.front() == '\'' && input.back() == '\'')
		return true; // It's a character literal like 'a'

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

	if (input.length() == 3 && input.front() == '\'' && input.back() == '\'') {
		std::cout << "Input is a character literal." << std::endl;
		char c = input[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	double outputDouble;
	if (input.back() == 'f') {
		outputDouble = std::stod(input.substr(0, input.length() - 1));
	}
	else {
		outputDouble = std::stod(input);
	}

	// Now we can convert the double to char and int
	char outputChar;
	if (outputDouble < std::numeric_limits<char>::min() || outputDouble > std::numeric_limits<char>::max() || !std::isprint(static_cast<char>(outputDouble))) {	
		std::cout << "char: impossible" << std::endl;
	} else {
		outputChar = static_cast<char>(outputDouble);
		std::cout << "char: '" << outputChar << "'" << std::endl;
	}
	int outputInt;
	if (outputDouble < std::numeric_limits<int>::min() || outputDouble > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		outputInt = static_cast<int>(outputDouble);
		std::cout << "int: " << outputInt << std::endl;
	}
	float outputFloat;
	if (outputDouble < std::numeric_limits<float>::lowest() || outputDouble > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		outputFloat = static_cast<float>(outputDouble);
		std::cout << "float: " << /* std::fixed << std::setprecision(1) << */ outputFloat << "f" << std::endl;
	}
	
	std::cout << "double: " /* << std::fixed << std::setprecision(1) */ << outputDouble << std::endl;
	
	// Here we implement the logic to convert the input string to float and double
}	
