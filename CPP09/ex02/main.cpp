/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/11 11:14:05 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return 0;
	}
	try
	{
		// Main logic to process the input numbers
	} catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
