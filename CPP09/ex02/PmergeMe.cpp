/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/15 12:20:14 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
/**
 * Verifies if the sorting of a vector and a deque is correct.
 * 
 * This function checks if both the vector and deque are of the same size,
 * if they are sorted in ascending order, and if their elements match at
 * corresponding indices.
 * 
 * @param vec The vector to verify
 * @param deq The deque to verify
 * @return void
 */
void PmergeMe::verifySorting(const std::vector<int> &vec,
		const std::deque<int> &deq) {
	if (vec.size() != deq.size()) {
		std::cout << "WARNING: Vector and deque sizes do not match." << std::endl;
		return;
	}
	if (!std::is_sorted(vec.begin(), vec.end())) {
		std::cout << "WARNING: Vector is not sorted." << std::endl;
		return;
	}
	if (!std::is_sorted(deq.begin(), deq.end())) {
		std::cout << "WARNING: Deque is not sorted." << std::endl;
		return;
	}
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i] != deq[i]) {
			std::cout << "WARNING: Vector and deque elements do not match at index "
				<< i << ": " << vec[i] << " != " << deq[i] << std::endl;
			return;
		}
	}
	std::cout << "Both vector and deque are sorted and match." << std::endl;
}

/**
 * Creates the Jacobsthal insertion order for the Ford-Johnson algorithm.
 * The Jacobsthal sequence minimizes the number of comparisons needed
 * when inserting elements using binary search.
 * 
 * @param n The number of elements to order
 * @return Vector containing the optimal insertion order indices
 */
static std::vector<size_t> createJacobsthalOrder(size_t n) {
	std::vector<size_t> order;
	if (n <= 1)
		return order;

	// Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2)
	// The sequence is: 1, 3, 5, 11, 21, 43, 85, 171, ...
	std::vector<size_t> jacob;
	jacob.push_back(1);
	size_t j1 = 1;
	size_t j2 = 3;
	while (j2 <= n) {
		jacob.push_back(j2);
		size_t tmp = j2;
		j2 = j2 + 2 * j1;
		j1 = tmp;
	}

	// Create insertion order based on Jacobsthal numbers
	// This order minimizes the maximum number of comparisons
	std::vector<bool> used(n, false);
	used[0] = true; // First element is already positioned
	for (size_t i = 1; i < jacob.size(); ++i) {
		size_t idx = jacob[i] - 1; // Convert to 0-based index
		if (idx < n) {
			order.push_back(idx);
			used[idx] = true;
		}
	}
	// Add any remaining elements that weren't covered by Jacobsthal numbers
	for (size_t i = 1; i < n; ++i) {
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

/**
 * Sorts a vector using the Ford-Johnson merge-insertion algorithm.
 * This algorithm is optimal in terms of worst-case comparisons.
 * 
 * Algorithm steps:
 * 1. Pair elements and ensure the larger is in 'bigs', smaller in 'smalls'
 * 2. Recursively sort the 'bigs' array
 * 3. Insert elements from 'smalls' using Jacobsthal order for optimal comparisons
 * 
 * @param vec Reference to the vector to be sorted
 */
void PmergeMe::sortVector(std::vector<int> &vec) {
	// Base case: arrays with 0 or 1 element are already sorted
	if (vec.size() <= 1)
		return;
	
	// Initialize containers for larger and smaller elements from pairs
	std::vector<int> bigs;
	std::vector<int> smalls;
	bigs.reserve((vec.size() + 1) / 2);    // Reserve space for efficiency
	smalls.reserve(vec.size() / 2);
	
	// Step 1: Pair elements and separate into bigs (larger) and smalls (smaller)
	size_t i = 0;
	for (; i + 1 < vec.size(); i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b) {
			bigs.push_back(a);     // a is larger
			smalls.push_back(b);   // b is smaller
		} else {
			bigs.push_back(b);     // b is larger
			smalls.push_back(a);   // a is smaller
		}
	}
	// Handle odd-sized arrays: add the last unpaired element to bigs
	if (vec.size() % 2 == 1)
		bigs.push_back(vec.back());

	// Step 2: Recursively sort the bigs array
	// After this, bigs is sorted and each element in smalls[i] < bigs[i]
	sortVector(bigs);
	
	// Step 3: Insert smalls elements using Jacobsthal order
	// This order minimizes the worst-case number of comparisons
	std::vector<size_t> jacob = createJacobsthalOrder(smalls.size());
	std::vector<bool> inserted(smalls.size(), false);

	// Insert elements according to Jacobsthal order
	for (size_t idx : jacob) {
		if (idx-1 >= smalls.size())  // Safety check for index bounds
			break;
		int val = smalls[idx-1];
		// Use binary search to find optimal insertion position
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
		inserted[idx-1] = true;  // Mark as inserted
	}

	// Insert any remaining elements that weren't covered by Jacobsthal order
	for (size_t j = 0; j < smalls.size(); ++j) {
		if (!inserted[j]) {
			int val = smalls[j];
			auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
			bigs.insert(pos, val);
		}
	}
	
	// Replace original vector with sorted result
	vec.swap(bigs);
}

/**
 * Sorts a deque using the Ford-Johnson merge-insertion algorithm.
 * This is essentially the same algorithm as sortVector, but adapted for std::deque.
 * The deque version maintains the same O(n log n) time complexity and optimal
 * comparison count characteristics of the Ford-Johnson algorithm.
 * 
 * @param deq Reference to the deque to be sorted
 */
void PmergeMe::sortDeque(std::deque<int> &deq) {
	// Base case: arrays with 0 or 1 element are already sorted
	if (deq.size() <= 1)
		return;
	
	// Initialize containers for larger and smaller elements from pairs
	std::deque<int> bigs;
	std::deque<int> smalls;
	
	// Step 1: Pair elements and separate into bigs (larger) and smalls (smaller)
	size_t i = 0;
	for (; i + 1 < deq.size(); i += 2) {
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b) {
			bigs.push_back(a);     // a is larger
			smalls.push_back(b);   // b is smaller
		} else {
			bigs.push_back(b);     // b is larger
			smalls.push_back(a);   // a is smaller
		}
	}
	// Handle odd-sized arrays: add the last unpaired element to bigs
	if (deq.size() % 2 == 1)
		bigs.push_back(deq.back());
	
	// Step 2: Recursively sort the bigs array
	// After this, bigs is sorted and each element in smalls[i] < bigs[i]
	sortDeque(bigs);
	
	// Step 3: Insert smalls elements using Jacobsthal order
	// This order minimizes the worst-case number of comparisons
	std::vector<size_t> jacob = createJacobsthalOrder(smalls.size());
	std::vector<bool> inserted(smalls.size(), false);
	
	// Insert elements according to Jacobsthal order
	for (size_t idx : jacob) {
		if (idx-1 >= smalls.size())  // Safety check for index bounds
			break;
		int val = smalls[idx-1];
		// Use binary search to find optimal insertion position
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
		inserted[idx-1] = true;  // Mark as inserted
	}

	// Insert any remaining elements that weren't covered by Jacobsthal order
	for (size_t j = 0; j < smalls.size(); ++j) {
		if (!inserted[j]) {
			int val = smalls[j];
			auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
			bigs.insert(pos, val);
		}
	}
	
	// Replace original deque with sorted result
	deq.swap(bigs);
}
