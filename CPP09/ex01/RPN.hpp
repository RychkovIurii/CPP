/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:28:30 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/10 11:36:26 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class RPN {
public:
	RPN() = delete;
	RPN(const RPN &other) = delete;
	RPN &operator=(const RPN &other) = delete;
	~RPN() = default;

	static void processInput(const std::string &expression);
};
