/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:51:36 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 11:19:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void tell_number(int n) {
	std::cout << "Number: " << n << std::endl;
}

void read_string(const std::string &str) {
	std::cout << "String: " << str << std::endl;
}

int main( void ) {

	std::cout << "==== Testing with integer and string arrays:" << std::endl;
	int numbers[] = {1, 2, 3, 4, 5};
	std::string strings[] = {"Hello", "World", "CPP", "Iterators"};
	iter(numbers, 5, tell_number);
	iter(strings, 4, read_string);

	std::cout << "==== Testing with empty array:" << std::endl;
	int empty_array[] = {};
	iter(empty_array, 0, tell_number);

	std::cout << "==== Testing with null pointer:" << std::endl;
	int *null_array = nullptr;
	iter(null_array, 5, tell_number);

	std::cout << "==== Testing with empty string array:" << std::endl;
	std::string empty_strings[] = {};
	iter(empty_strings, 0, read_string);

	std::cout << "==== Testing with null string pointer:" << std::endl;
	std::string *null_strings = nullptr;
	iter(null_strings, 5, read_string);

	std::cout << "==== Testing with single element arrays:" << std::endl;
	int single_number[] = {42};
	std::string single_string[] = {"Single"};
	iter(single_number, 1, tell_number);
	iter(single_string, 1, read_string);

	// User responsobility to ensure the array length matches the number of elements
	//iter(single_string, 3, read_string);
	//iter(single_number, 3, tell_number);

	return 0;
}
