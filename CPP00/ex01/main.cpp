/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 14:35:02 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		cout << "The program doesn't handle arguments!" << endl;
		return (0);
	}

	string input;
	cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << endl;
	while (std::getline(cin, input))
	{
		if (input.compare("EXIT\0") == 0)
		{
			cout << "We exit" << endl;
			break;
		}
		if (input.compare("ADD\0") == 0)
		{
			cout << "We add" << endl;
		}
		if (input.compare("SEARCH\0") == 0)
		{
			cout << "We search. Here we have to show phonebook" << endl;
			//Show short here!
			cout << "Enter index. The program only accepts numbers from 1 to 8 or EXIT" << endl;
			while (std::getline(cin, input))
			{
				if (input.compare("EXIT\0") == 0)
				{
					cout << "We exit" << endl;
					break;
				}
				if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
				{
					int index = stoi(input);
					cout << "We entered and will show specific contact" << index << endl;
				}
				if (!cin.eof())
					cout << "Enter index. The program only accepts numbers from 1 to 8 or EXIT" << endl;
			}
		}
		if (!cin.eof())
			cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << endl;
	}
	cout << "Thanks! See you!" << endl;
	return (0);
}
