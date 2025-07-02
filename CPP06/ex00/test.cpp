/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:44:41 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 12:30:36 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

void runTest(const std::string& input) {
	std::cout << "============================" << std::endl;
	std::cout << "Testing input: \"" << input << "\"" << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

int main() {
	// Povided test cases
	runTest("0");
	runTest("nan");
	runTest("42.0f");

	// Valid cases
	runTest("a");
	runTest("'z'");
	runTest("42");
	runTest("42.f");
	runTest(".42f");
	runTest("123.456");

	// Pseudo-literals
	runTest("nan");
	runTest("nanf");
	runTest("+inf");
	runTest("+inff");
	runTest("-inf");
	runTest("-inff");

	// Edge integer boundaries
	runTest("2147483647");       // INT_MAX
	runTest("2147483648");       // Just above INT_MAX
	runTest("-2147483648");      // INT_MIN

	// Overflows
	runTest("999999999999999999999999999999999999999999999999999999999999999f");
	runTest("999999999999999999999999999999999999999999999999999999999999999.0");

	// Invalid cases
	runTest("");
	runTest("f.");
	runTest("--42");
	runTest("42ff");
	runTest(".f");
	runTest("-.f");

	// Printable / non-printable edge
	runTest("~");
	runTest("\n");

	return 0;
}
