/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:42:16 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 12:35:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cmath>

static void	printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	handlePseudoLiteral(const std::string &input) {
	if (input == "nan" || input == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	if (input == "-inf" || input == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	if (input == "+inf" || input == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	return (false);
}

static bool	isValid(const std::string &input) {
	if (input.length() == 1)
		return (true);
	if (input.length() == 3 && input.front() == '\''
		&& input.back() == '\'')
		return (true);

	size_t dotCount = 0;
	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '-' || input[i] == '+') {
			if (i != 0) {
				return (false);
			}
		} else if (!std::isdigit(input[i]) && input[i] != '.'
			&& input[i] != 'f') {
			return (false);
		} else if (input[i] == 'f' && i != input.length() - 1) {
			return (false);
		} else if (input[i] == '.') {
			dotCount++;
			if (dotCount > 1) {
				return (false);
			}
		}
	}
	return (true);
}

static int	getPrecision(const std::string &input) {
	size_t precision;
	size_t dotPos = input.find('.');
	if (dotPos == std::string::npos) {
		return (1);
	}
	size_t endPos = input.find('f', dotPos);
	if (endPos == std::string::npos) {
		endPos = input.length();
	}
	precision = endPos - dotPos - 1;
	if (precision > static_cast<size_t>(std::numeric_limits<int>::max())
		|| precision == 0) {
		return (1);
	}
	return (static_cast<int>(precision));
}

static bool	handleCharLiteral(const std::string& input, int precision) {
	char c;
	// Case 1: single printable non-digit char
	if (input.length() == 1) {
		c = input[0];
		if (std::isprint(c) && !std::isdigit(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} 
	// Case 2: character literal in form of `'a'`
	else if (input.length() == 3 && input.front() == '\''
		&& input.back() == '\'') {
		c = input[1];
		if (std::isprint(c) && !std::isdigit(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} 
	else {
		return (false);
	}

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(precision)
	          << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	return (true);
}

static bool parseToDoubleFromInput(const std::string& input, double& outputDouble) {
	try {
		size_t pos = 0;
		if (input.back() == 'f') {
			outputDouble = std::stod(input.substr(0, input.length() - 1));
			if (outputDouble < std::numeric_limits<float>::lowest()
				|| outputDouble > std::numeric_limits<float>::max()) {
				throw std::invalid_argument("Value out of range for float.");
			}
		}
		else {
			outputDouble = std::stod(input, &pos);
			if (pos != input.length()) {
				throw std::invalid_argument("We have leftover characters.");
			}
		}
	} catch (const std::exception &e) {
		printImpossible();
		return false;
	}
	return true;
}

void	ScalarConverter::convert(const std::string &input) {

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
	if (handleCharLiteral(input, precision))
		return;

	double outputDouble;
	if (!parseToDoubleFromInput(input, outputDouble))
		return;

	// Now we can convert the double to char, int, and float types safely
	char outputChar;
	if (outputDouble < std::numeric_limits<char>::min()
		|| outputDouble > std::numeric_limits<char>::max()) {	
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(outputDouble))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		outputChar = static_cast<char>(outputDouble);
		std::cout << "char: '" << outputChar << "'" << std::endl;
	}
	int outputInt;
	if (outputDouble < std::numeric_limits<int>::min()
		|| outputDouble > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		outputInt = static_cast<int>(outputDouble);
		std::cout << "int: " << outputInt << std::endl;
	}
	float outputFloat;
	if (outputDouble < std::numeric_limits<float>::lowest()
		|| outputDouble > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		outputFloat = static_cast<float>(outputDouble);
		if (std::isinf(outputFloat) || std::isnan(outputFloat)) {
			std::cout << "float: impossible" << std::endl;
		}
		else {
			std::cout << "float: " << std::fixed << std::setprecision(precision)
				<< outputFloat << "f" << std::endl;
		}
	}
	std::cout << "double: " << std::fixed << std::setprecision(precision)
		<< outputDouble << std::endl;
}	
