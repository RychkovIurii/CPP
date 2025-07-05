/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:34:07 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/05 09:36:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#define MAX_VAL 750

/* Notes
For primitives, new T[n] does nothing — leaves memory uninitialized.
For primitives, new T[n]() explicitly value-initializes each element → zeros.
For classes, the default constructor is called anyway in both cases — so () has no effect.
*/

int main( void ) {
	// My tests
	try {
		Array<int> testInt;
		Array<std::string> testString;
		Array<int> intArray(5);
		Array<std::string> stringArray(3);
		//Array<int> negativeArray(-5); // Comments out to avoid undefined behavior

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
		
		std::cout << "==== Test out of bounds access ====" << std::endl;
		try {
			std::cout << "Accessing out of bounds index in intArray: " << intArray[10] << std::endl;
		} catch (const std::out_of_range &e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "==== Test uninitialized array ====" << std::endl;
		Array<int> uninitialized(3);
		for (unsigned int i = 0; i < uninitialized.size(); ++i) {
			std::cout << "Uninitialized[" << i << "]: " << uninitialized[i] << std::endl;
		}

		std::cout << "==== Test self-assignment ====" << std::endl;
		Array<int> selfAssignedArray(5);
		assignedIntArray = selfAssignedArray;
		std::cout << "Self-assigned array size: " << selfAssignedArray.size() << std::endl;

		std::cout << "==== Test const array ====" << std::endl;
		const Array<int> constArray(3);
		std::cout << "Const array[0]: " << constArray[0] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}

	// Original tests
	try {
		std::cout << "==== Test provided main ====" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
	