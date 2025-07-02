/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:34:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 15:51:46 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base* generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return;
	} catch (std::bad_cast&) { }
	
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return;
	} catch (std::bad_cast&) { }
		
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch (std::bad_cast&) {
		std::cout << "Unknown type" << std::endl;
	}
}

int main( void ) {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	try {
		for (int i = 0; i < 6; ++i) {
			Base* base = generate();

			std::cout << "==== Test " << i + 1 << " ====" << std::endl;
			std::cout << "Identifying via pointer:   ";
			identify(base);
			std::cout << "Identifying via reference: ";
			identify(*base);

			delete base;
			std::cout << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	std::cout << "All tests completed successfully!" << std::endl;
	return 0;
}
