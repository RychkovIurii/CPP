/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/15 12:16:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>

class PmergeMe {
	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe() = default;

		static void sortVector(std::vector<int> &vec);
		static void sortDeque(std::deque<int> &deq);
		static void verifySorting(const std::vector<int> &vec, const std::deque<int> &deq);
};
