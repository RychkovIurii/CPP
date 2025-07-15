/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/15 10:23:44 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>

void PmergeMe::sortVector(std::vector<int> &vec) {
	if (vec.size() <= 1)
		return;
	std::vector<int> bigs;
	std::vector<int> smalls;
	bigs.reserve((vec.size() + 1) / 2);
	smalls.reserve(vec.size() / 2);
	size_t i = 0;
	for (; i + 1 < vec.size(); i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b) {
			bigs.push_back(a);
			smalls.push_back(b);
		} else {
			bigs.push_back(b);
			smalls.push_back(a);
		}
	}
	if (vec.size() % 2 == 1)
		bigs.push_back(vec.back());
	sortVector(bigs);
	for (size_t j = 0; j < smalls.size(); ++j) {
		int val = smalls[j];
		std::vector<int>::iterator pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
	}
	vec.swap(bigs);
}

void PmergeMe::sortDeque(std::deque<int> &deq) {
	if (deq.size() <= 1)
		return;
	std::deque<int> bigs;
	std::deque<int> smalls;
	size_t i = 0;
	for (; i + 1 < deq.size(); i += 2) {
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b) {
			bigs.push_back(a);
			smalls.push_back(b);
		} else {
			bigs.push_back(b);
			smalls.push_back(a);
		}
	}
	if (deq.size() % 2 == 1)
		bigs.push_back(deq.back());
	sortDeque(bigs);
	for (size_t j = 0; j < smalls.size(); ++j) {
		int val = smalls[j];
		std::deque<int>::iterator pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
	}
	deq.swap(bigs);
}
