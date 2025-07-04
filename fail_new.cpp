/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_new.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:17 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/04 14:40:11 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <new>

// Static variable to count allocations
static int allocation_count = 0;
static const int fail_after = 1; // Fail after NUM successful allocations

// Custom new operator
void* operator new(size_t size)
{
	allocation_count++;
	
	// Simulate failure after a certain number of allocations
	if (allocation_count > fail_after) {
		std::cerr << "Custom new: Allocation failed after " << fail_after << " allocations." << std::endl;
		
		// Throwing std::bad_alloc to simulate allocation failure
		allocation_count = 0; // Reset count after failure
		throw std::bad_alloc(); // Throws an exception on allocation failure
	}
	
	return malloc(size); // Calls the default operator new
}

/*
	Custom new fails after NUM successful allocation.
	We can use this to test how our program behaves when new fails.
	To use this, compile this file as a shared library and run your program.
	g++ -shared -fPIC -o libfailnew.so fail_new.cpp
	LD_PRELOAD=./libfailnew.so ./your_program
 */
