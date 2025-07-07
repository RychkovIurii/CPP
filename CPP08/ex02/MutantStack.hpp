/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:45:20 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/07 14:36:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	MutantStack& operator=(const MutantStack& other) = default;
	~MutantStack() = default;
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
};

#include "MutantStack.tpp"
