/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:28:26 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/10 11:38:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>

void RPN::processInput(const std::string &expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token) {
		if (token.size() == 1 && isdigit(token[0])) {
			stack.push(token[0] - '0');
		} else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			if (stack.size() < 2) {
				throw std::runtime_error("not enough operands for operation");
			}
			int x = stack.top();
			stack.pop();
			int y = stack.top();
			stack.pop();
			int result;

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
