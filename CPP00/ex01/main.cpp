/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 12:05:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

using std::cout;



int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		cout << "The program doesn't handle arguments" << std::endl;
		return (0);
	}

	std::string input;
	while (1)
	{
		cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << std::endl;
		std::cin >> input;
		if (input.compare("EXIT\0") == 0)
		{
			cout << "We exit" << std::endl;
			break;
		}
	}
	cout << std::endl;
	return (0);
}
