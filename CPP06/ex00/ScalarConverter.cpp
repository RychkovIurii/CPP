/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:42:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/06/30 12:01:05 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>

static void printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool handlePseudoLiteral(const std::string &input) {
	if (input == "nan" || input == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	if (input == "-inf" || input == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	if (input == "+inf" || input == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	return false;
}

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

static int getPrecision(const std::string &input) {
	size_t precision;
	size_t dotPos = input.find('.');
	if (dotPos == std::string::npos) {
		return 1; // Default precision if no dot is found
	}
	size_t endPos = input.find('f', dotPos);
	if (endPos == std::string::npos) {
		endPos = input.length(); // If no 'f', consider the end of the string
	}
	precision = endPos - dotPos - 1; // Precision is the number of digits after the dot
	if (precision > static_cast<size_t>(std::numeric_limits<int>::max()) || precision == 0) {
		return 1; // Ensure at least one digit after the dot
	}
	return static_cast<int>(precision);
}

void ScalarConverter::convert(const std::string &input) {

	if (input.empty()) {
		printImpossible();
		return;
	}

	if (handlePseudoLiteral(input))
		return;

	if (!isValid(input)) {
		printImpossible();
		return;
	}

	int precision = getPrecision(input);
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	if (input.length() == 3 && input.front() == '\'' && input.back() == '\'') {
		std::cout << "Input is a character literal." << std::endl;
		char c = input[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	double outputDouble;
	try {
		size_t pos = 0;
		if (input.back() == 'f') {
			outputDouble = std::stod(input.substr(0, input.length() - 1));
			if (outputDouble < std::numeric_limits<float>::lowest() || outputDouble > std::numeric_limits<float>::max()) {
				throw std::invalid_argument("Value out of range for float.");
			}
		}
		else {
			outputDouble = std::stod(input, &pos);
			if (pos != input.length()) {
				throw std::invalid_argument("We have leftover characters after conversion.");
			}
		}
	} catch (const std::invalid_argument &e) {
		printImpossible();
		return;
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
		std::cout << "float: " << std::fixed << std::setprecision(precision) << outputFloat << "f" << std::endl;
	}
	
	std::cout << "double: " << std::fixed << std::setprecision(precision) << outputDouble << std::endl;
}	
