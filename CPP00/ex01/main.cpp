/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:48:03 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	process_search(PhoneBook &phonebook)
{
	if (phonebook.get_contact_count() == 0)
	{
		std::cout << "No contacts available. Please add contacts first."
			<< std::endl;
		return ;
	}
	phonebook.search_contact();
	std::cout << "Enter index. The program only accepts index from 1 to " 
		<< phonebook.get_contact_count() << " or EXIT to main menu" << std::endl;
	std::string input;
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
		{
			std::cout << "We exiting to main menu..." << std::endl;
			break ;
		}
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
		{
			int index = stoi(input);
			if (index > 0 && index <= phonebook.get_contact_count())
				phonebook.get_contact(index - 1).display_contact();
		}
		if (!std::cin.eof())
		{
			//phonebook.search_contact();
			std::cout << "Enter index. The program only accepts numbers from 1 to "
				<< phonebook.get_contact_count() << " or EXIT to main menu" << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	(void)argv;

	if (argc != 1)
	{
		std::cout << "The program doesn't handle arguments!" << std::endl;
		return (0);
	}
	PhoneBook phonebook;
	std::string input;
	std::cout << "Enter one of three commands: ADD, SEARCH or EXIT."
		<< std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		if (input == "ADD")
			phonebook.add_contact();
		if (input == "SEARCH")
			process_search(phonebook);
		if (!std::cin.eof())
			std::cout << "Enter one of three commands: ADD, SEARCH or EXIT."<< std::endl;
	}
	if (!std::cin.eof())
		std::cout << "Thanks! See you!" << std::endl;
	else
		std::cout << "\n\nAt least you've tried! See you! xD" << std::endl;
	return (0);
}
