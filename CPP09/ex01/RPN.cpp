/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:28:26 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/11 10:47:17 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <limits>

void RPN::processInput(const std::string &expression) {
	std::stack<long long> stack;
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token) {
		if (token.size() == 1 && isdigit(token[0])) {
			stack.push(token[0] - '0');
		} else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			if (stack.size() < 2) {
				throw std::runtime_error("not enough operands for operation");
			}
			long long x = stack.top();
			stack.pop();
			long long y = stack.top();
			stack.pop();
			long long result;

			if (token[0] == '+') {
				result = y + x;
			} else if (token[0] == '-') {
				result = y - x;
			} else if (token[0] == '*') {
				result = y * x;
			} else if (token[0] == '/') {
				if (x == 0) {
					throw std::runtime_error("division by zero");
				}
				result = y / x;
			}
			else {
				throw std::runtime_error("unknown operator: " + token);
			}
			if (result < std ::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
				throw std::runtime_error("result out of bounds. Expected int range.");
			}
			stack.push(result);
		} else {
			throw std::runtime_error("invalid token: " + token);
		}
	}
	
	if (stack.size() != 1) {
		throw std::runtime_error("invalid expression");
	}
	std::cout << stack.top() << std::endl;
}
