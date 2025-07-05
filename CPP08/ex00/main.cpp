/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:44:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 10:12:53 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

// Note: easyfind is not required to support associative containers
// (like std::set or std::map) because they have their own find() methods
// and do not use sequential access by index.

int main() {
	try {
		std::vector<int> vec = {1, 2, 3, 4, 5};
		std::list<int> lst = {10, 20, 30, 40, 50};
		std::deque<int> deq = {100, 200, 300, 400, 500};

		std::cout << "==== Finding 3 in vector: ";
		auto itVec = easyfind(vec, 3);
		std::cout << *itVec << std::endl;
		std::cout << "==== Finding 20 in list: ";
		auto itLst = easyfind(lst, 20);
		std::cout << *itLst << std::endl;
		std::cout << "==== Finding 300 in deque: ";
		auto itDeq = easyfind(deq, 300);
		std::cout << *itDeq << std::endl;
		try {
			std::cout << "==== Finding 1000 in vector: ";
			auto itNotFound = easyfind(vec, 1000);
			std::cout << *itNotFound << std::endl; // Throw an exception
		} catch (const std::runtime_error &e) {
			std::cout << "Exception caught: ";
			std::cout << e.what() << std::endl;
		}
		std::cout << "==== Testing const container: ";
		const std::vector<int> constVec = {1, 2, 3, 4, 5};
		auto itConst = easyfind(constVec, 2);
		std::cout << *itConst << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
