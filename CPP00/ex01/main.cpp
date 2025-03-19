/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 18:47:23 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void process_search(PhoneBook &phonebook)
{
	if (phonebook.get_contact_count() == 0)
	{
		cout << "No contacts available. Please add contacts first." << endl;
		return ;
	}
	phonebook.search_contact();
	cout << "Enter index. The program only accepts index from 1 to " << phonebook.get_contact_count() << " or EXIT to main menu" << endl;
	string input;
	while (std::getline(cin, input))
	{
		if (input == "EXIT")
		{
			cout << "We exiting to main menu..." << endl;
			break;
		}
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
		{
			int index = stoi(input);
			if (index > 0 && index <= phonebook.get_contact_count())
				phonebook.get_contact(index - 1).display_contact();
		}
		if (!cin.eof())
		{
			//phonebook.search_contact();
			cout << "Enter index. The program only accepts numbers from 1 to " << phonebook.get_contact_count() << " or EXIT to main menu" << endl;
		}
	}
}

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
		if (input == "EXIT")
		{
			cout << "Exiting..." << endl;
			break;
		}
		if (input == "ADD")
			phonebook.add_contact();
		if (input == "SEARCH")
			process_search(phonebook);
		if (!cin.eof())
			cout << "Enter one of three commands. The program only accepts ADD, SEARCH and EXIT." << endl;
	}
	if (!cin.eof())
		cout << "Thanks! See you!" << endl;
	else
		cout << "\n\nAt least you've tried! See you! xD" << endl;
	return (0);
}
