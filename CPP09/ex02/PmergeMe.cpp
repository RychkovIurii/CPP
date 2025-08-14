/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/14 20:56:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <cstddef>

// Global counter for element comparisons
std::size_t g_comparisonCount = 0;

// Comparator that increments the global counter on each comparison
struct CountingLess {
		bool operator()(int a, int b) const {
				++g_comparisonCount;
				return a < b;
		}
};

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
	// === Phase 1: pairwise block swapping ===
	auto mergeSortVec = [&](auto& self, size_t pairsize, bool insert) -> void {
		if (insert == false) {
			for (size_t i = 0; i < vec.size(); i += pairsize * 2) {
				size_t mid = i + pairsize;
				size_t end = std::min(i + pairsize * 2, vec.size());
				if (vec.size() / 2 < pairsize) { // switch to insertion phase
					insert = true;
					return;
				}
				if (i + pairsize * 2 > vec.size()) break;

				// Compare tails and swap whole blocks if needed
				if (mid - 1 < vec.size() && end - 1 < vec.size() &&
					CountingLess()(vec[end - 1], vec[mid - 1])) {
					for (size_t k = 0; k < pairsize && mid + k < end; ++k)
						std::swap(vec[i + k], vec[mid + k]);
				}
			}
			self(self, pairsize * 2, insert);
		}

		// === Phase 2: build 2D chunks ===
		struct VChunk { std::vector<int> data; size_t id; };
		std::vector<VChunk> temp;
		{
			size_t nextId = 0;
			for (size_t i = 0; i < vec.size(); i += pairsize) {
				std::vector<int> chunk;
				for (size_t j = i; j < i + pairsize && j < vec.size() && i + pairsize <= vec.size(); ++j)
					chunk.push_back(vec[j]);
				if (!chunk.empty())
					temp.push_back(VChunk{chunk, nextId++});
			}
		}

		// main = b1, a1, a2, ...
		// pend = b2, b3, ...
		std::vector<VChunk> pend;
		std::vector<VChunk> main;
		for (size_t i = 0; i < temp.size(); ++i) {
			if (i == 0)            main.push_back(temp[i]);   // b1
			else if (i % 2 == 0)   pend.push_back(temp[i]);   // b2, b3, ...
			else                   main.push_back(temp[i]);   // a1, a2, ...
		}

		// === Phase 3: Jacobsthal batches with bounds (anchor a_j) ===
		size_t jacob = 3;      // J(2)
		size_t jacob_prev = 1;  // J(1)

		while (!pend.empty()) {
			size_t batch = jacob - jacob_prev;
			for (size_t i = 0; i < batch; ++i) {
				// pick chunk from the current Jacobsthal window
				VChunk num_to_insert;
				if (pend.size() >= 1) {
					if (pend.size() - 1 > batch - 1 - i)
						num_to_insert = pend[batch - 1 - i];
					else
						num_to_insert = pend[pend.size() - 1];
				} else {
					num_to_insert = pend[0]; // unreachable
				}

				// find its original position j in temp by ID (not by value!)
				size_t jIndex = 0;
				for (; jIndex < temp.size(); ++jIndex)
					if (temp[jIndex].id == num_to_insert.id) break;

				// boundElement is position of a_j (temp[j+1]) in main, by ID
				size_t boundElement = 0;
				if (jIndex + 1 < temp.size()) {
					size_t anchorId = temp[jIndex + 1].id; // a_j’s ID
					bool found = false;
					for (size_t k = 0; k < main.size(); ++k) {
						if (main[k].id == anchorId) { boundElement = k; found = true; break; }
					}
					if (!found) boundElement = 0; // fallback
				} else {
					boundElement = 0; // no a_j → unbounded
				}

				size_t bound = (boundElement == 0) ? main.size() : boundElement;

				// lower_bound on main[0..bound) by last element of the chunk
				auto it = std::lower_bound(
					main.begin(),
					main.begin() + std::min(bound, main.size()),
					num_to_insert,
					[&](const VChunk& A, const VChunk& B) {
						return CountingLess()(A.data[pairsize - 1], B.data[pairsize - 1]);
					}
				);

				// erase from pend by ID (not by content!)
				auto it2 = std::find_if(pend.begin(), pend.end(),
					[&](const VChunk& c){ return c.id == num_to_insert.id; });

				if (it2 == pend.end()) {
					if (it != main.begin() + std::min(bound, main.size()))
						main.insert(it, num_to_insert);
					else
						main.push_back(num_to_insert);
				} else {
					if (it != main.begin() + std::min(bound, main.size()))
						main.insert(it, num_to_insert);
					else
						main.insert(main.begin() + std::min(bound, main.size()), num_to_insert);
					pend.erase(it2);
				}

				if (pend.empty()) {
					// flatten main back to vec
					size_t k = 0;
					for (size_t j = 0; j < main.size(); ++j)
						for (size_t l = 0; l < main[j].data.size(); ++l)
							vec[k++] = main[j].data[l];
					jacob = 3; jacob_prev = 1;
					return;
				}
			}
			size_t tmp = jacob;
			jacob = jacob + 2 * jacob_prev; // J_next = J + 2*J_prev
			jacob_prev = tmp;
		}
	};

	mergeSortVec(mergeSortVec, /*pairsize*/1, /*insert*/false);
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
	// === Phase 1: pairwise block swapping ===
	auto mergeSortDeq = [&](auto& self, size_t pairsize, bool insert) -> void {
		if (insert == false) {
			for (size_t i = 0; i < deq.size(); i += pairsize * 2) {
				size_t mid = i + pairsize;
				size_t end = std::min(i + pairsize * 2, deq.size());
				if (deq.size() / 2 < pairsize) {
					insert = true;
					return;
				}
				if (i + pairsize * 2 > deq.size()) break;

				if (mid - 1 < deq.size() && end - 1 < deq.size() &&
					CountingLess()(deq[end - 1], deq[mid - 1])) {
					for (size_t k = 0; k < pairsize && mid + k < end; ++k)
						std::swap(deq[i + k], deq[mid + k]);
				}
			}
			self(self, pairsize * 2, insert);
		}

		// === Phase 2: build 2D chunks ===
		struct DChunk { std::deque<int> data; size_t id; };
		std::deque<DChunk> temp;
		{
			size_t nextId = 0;
			for (size_t i = 0; i < deq.size(); i += pairsize) {
				std::deque<int> chunk;
				for (size_t j = i; j < i + pairsize && j < deq.size() && i + pairsize <= deq.size(); ++j)
					chunk.push_back(deq[j]);
				if (!chunk.empty())
					temp.push_back(DChunk{chunk, nextId++});
			}
		}

		std::deque<DChunk> pend;
		std::deque<DChunk> main;
		for (size_t i = 0; i < temp.size(); ++i) {
			if (i == 0)          main.push_back(temp[i]); // b1
			else if (i % 2 == 0) pend.push_back(temp[i]); // b2, b3, ...
			else                 main.push_back(temp[i]); // a1, a2, ...
		}

		// === Phase 3: Jacobsthal batches with bounds (anchor a_j) ===
		size_t jacob = 3;      // J(2)
		size_t jacob_prev = 1;  // J(1)

		while (!pend.empty()) {
			size_t batch = jacob - jacob_prev;
			for (size_t i = 0; i < batch; ++i) {
				DChunk num_to_insert;
				if (pend.size() >= 1) {
					if (pend.size() - 1 > batch - 1 - i)
						num_to_insert = pend[batch - 1 - i];
					else
						num_to_insert = pend[pend.size() - 1];
				} else {
					num_to_insert = pend[0]; // unreachable
				}

				// find original index j in temp by ID
				size_t jIndex = 0;
				for (; jIndex < temp.size(); ++jIndex)
					if (temp[jIndex].id == num_to_insert.id) break;

				// bound is a_j (temp[j+1]) located in main by ID
				size_t boundElement = 0;
				if (jIndex + 1 < temp.size()) {
					size_t anchorId = temp[jIndex + 1].id;
					bool found = false;
					for (size_t k = 0; k < main.size(); ++k) {
						if (main[k].id == anchorId) { boundElement = k; found = true; break; }
					}
					if (!found) boundElement = 0;
				} else {
					boundElement = 0;
				}

				size_t bound = (boundElement == 0) ? main.size() : boundElement;

				auto it = std::lower_bound(
					main.begin(),
					main.begin() + std::min(bound, main.size()),
					num_to_insert,
					[&](const DChunk& A, const DChunk& B) {
						return CountingLess()(A.data[pairsize - 1], B.data[pairsize - 1]);
					}
				);

				// erase from pend by ID
				auto it2 = std::find_if(pend.begin(), pend.end(),
					[&](const DChunk& c){ return c.id == num_to_insert.id; });

				if (it2 == pend.end()) {
					if (it != main.begin() + std::min(bound, main.size()))
						main.insert(it, num_to_insert);
					else
						main.push_back(num_to_insert);
				} else {
					if (it != main.begin() + std::min(bound, main.size()))
						main.insert(it, num_to_insert);
					else
						main.insert(main.begin() + std::min(bound, main.size()), num_to_insert);
					pend.erase(it2);
				}

				if (pend.empty()) {
					// flatten main back to deq
					size_t k = 0;
					for (size_t j = 0; j < main.size(); ++j)
						for (size_t l = 0; l < main[j].data.size(); ++l)
							deq[k++] = main[j].data[l];
					jacob = 3; jacob_prev = 1;
					return;
				}
			}
			size_t tmp = jacob;
			jacob = jacob + 2 * jacob_prev;
			jacob_prev = tmp;
		}
	};

	mergeSortDeq(mergeSortDeq, /*pairsize*/1, /*insert*/false);
}
