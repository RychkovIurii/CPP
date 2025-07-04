/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:34:07 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 14:12:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

/* Notes
For primitives, new T[n] does nothing — leaves memory uninitialized.
For primitives, new T[n]() explicitly value-initializes each element → zeros.
For classes, the default constructor is called anyway in both cases — so () has no effect.
*/

int main( void ) {
	Array<int> testInt;
	Array<std::string> testString;
	Array<int> intArray(5);
	Array<std::string> stringArray(3);
	//Array<int> negativeArray(-5); // Think!!!!!

	std::cout << "==== Test size() ====" << std::endl;
	std::cout << "Size of testInt: " << testInt.size() << std::endl;
	std::cout << "Size of testString: " << testString.size() << std::endl;
	std::cout << "Size of intArray: " << intArray.size() << std::endl;
	std::cout << "Size of stringArray: " << stringArray.size() << std::endl;
	//std::cout << "Size of negativeArray: " << negativeArray.size() << std::endl;
	
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	intArray[3] = 4;
	intArray[4] = 5;

	stringArray[0] = "Hello";
	stringArray[1] = "Hive";
	stringArray[2] = "World";

	std::cout << "==== Test copy constructor and assignment operator ====" << std::endl;
	Array<int> copyIntArray(intArray);
	Array<std::string> copyStringArray(stringArray);
	
	std::cout << "Copy of intArray: ";
	for (unsigned int i = 0; i < copyIntArray.size(); ++i) {
		std::cout << copyIntArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Copy of stringArray: ";
	for (unsigned int i = 0; i < copyStringArray.size(); ++i) {
		std::cout << copyStringArray[i] << " ";
	}
	std::cout << std::endl;

	Array<int> assignedIntArray;
	assignedIntArray = copyIntArray;
	Array<std::string> assignedStringArray;
	assignedStringArray = copyStringArray;

	std::cout << "Assigned intArray: ";
	for (unsigned int i = 0; i < assignedIntArray.size(); ++i) {
		std::cout << assignedIntArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Assigned stringArray: ";
	for (unsigned int i = 0; i < assignedStringArray.size(); ++i) {
		std::cout << assignedStringArray[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "==== Test deep copy ====" << std::endl;
	assignedIntArray[0] = 10;
	std::cout << "Modified assignedIntArray[0]: " << assignedIntArray[0] << std::endl;
	std::cout << "Original copyIntArray[0]: " << copyIntArray[0] << std::endl;
	std::cout << std::endl;
	return 0;
}
	