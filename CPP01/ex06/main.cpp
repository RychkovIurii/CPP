/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:38:29 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/26 13:58:34 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter LEVEL" << std::endl;
		return (0);
	}
	std::string level = argv[1];
	Harl harl;
	harl.complain(level);
	return (0);
}
