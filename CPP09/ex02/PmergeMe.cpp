/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/15 11:16:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>

static std::vector<size_t> createJacobsthalOrder(size_t n) {
	std::vector<size_t> order;
	if (n <= 1)
		return order;

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

	std::vector<bool> used(n, false);
	used[0] = true;
	for (size_t i = 1; i < jacob.size(); ++i) {
		size_t idx = jacob[i] - 1;
		if (idx < n) {
			order.push_back(idx);
			used[idx] = true;
		}
	}
	for (size_t i = 1; i < n; ++i) {
		if (!used[i])
				order.push_back(i);
	}
	return order;
}

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
	
	std::vector<size_t> jacob = createJacobsthalOrder(smalls.size());
	std::vector<bool> inserted(smalls.size(), false);

	for (size_t idx : jacob) {
		if (idx-1 >= smalls.size())
			break;
		int val = smalls[idx-1];
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
		inserted[idx-1] = true;
	}

	for (size_t j = 0; j < smalls.size(); ++j) {
		if (!inserted[j]) {
			int val = smalls[j];
			auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
			bigs.insert(pos, val);
		}
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
	std::vector<size_t> jacob = createJacobsthalOrder(smalls.size());
	std::vector<bool> inserted(smalls.size(), false);
	for (size_t idx : jacob) {
		if (idx-1 >= smalls.size())
			break;
		int val = smalls[idx-1];
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
		bigs.insert(pos, val);
		inserted[idx-1] = true;
	}

	for (size_t j = 0; j < smalls.size(); ++j) {
		if (!inserted[j]) {
			int val = smalls[j];
			auto pos = std::lower_bound(bigs.begin(), bigs.end(), val);
			bigs.insert(pos, val);
		}
	}
	deq.swap(bigs);
}
