/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 12:56:58 by irychkov         ###   ########.fr       */
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

	PhoneBook phonebook;
	string input;
	cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << endl;
	while (std::getline(cin, input))
	{
		if (input.compare("EXIT\0") == 0)
		{
			cout << "Exiting..." << endl;
			break;
		}
		if (input.compare("ADD\0") == 0)
		{
			phonebook.add_contact();
		}
		if (input.compare("SEARCH\0") == 0)
		{
			if (phonebook.get_contact_count() == 0)
			{
				cout << "No contacts available. Please add contacts first." << endl;
			}
			else
			{
				phonebook.search_contact();
				if (!cin.eof())
					cout << "Enter index. The program only accepts numbers from 1 to 8 or EXIT to main menu" << endl;
				while (std::getline(cin, input))
				{
					if (input.compare("EXIT\0") == 0)
					{
						cout << "We exiting to main menu..." << endl;
						break;
					}
					if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
					{
						int index = stoi(input);
						if (index > 0 && index <= phonebook.get_contact_count())
						{
							phonebook.get_contact(index - 1).display_contact(index);
						}
						else
						{
							cout << "Invalid index" << endl;
						}
					}
					if (!cin.eof())
					{
						phonebook.search_contact();
						cout << "Enter index. The program only accepts numbers from 1 to 8 or EXIT to main menu" << endl;
					}
				}
			}
		}
		if (!cin.eof())
			cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << endl;
	}
	if (!cin.eof())
		cout << "Thanks! See you!" << endl;
	else
		cout << "\n\nAt least you've tried! See you! xD" << endl;
	return (0);
}
