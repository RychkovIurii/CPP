/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:49:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact :: Contact( void ) { }

Contact :: ~Contact( void ) { }

std::string	Contact :: formatField( std::string &field )
{
	if (field.length() > 10) {
		return (field.substr(0, 9) + ".");
	}
	return (field);
}

void	Contact :: take_input( std::string output, std::string &element )
{
	if (!std::cin.eof())
		std::cout << output;
	std::getline(std::cin, element);
	if (std::cin.eof())
		return ;
	while (element.compare("") == 0)
	{
		std::cout << output;
		std::getline(std::cin, element);
		if (std::cin.eof())
			return ;
	}
	
}

void	Contact :: set_contact( void )
{
	take_input("Enter first name: ", first_name_);
	take_input("Enter last name: ", last_name_);
	take_input("Enter nickname: ", nick_name_);
	take_input("Enter phone number: ", phone_number_);
	take_input("Enter darkest secret: ", darkest_secret_);
	if (!std::cin.eof())
		std::cout << "Contact added." << std::endl;
}

void	Contact :: display_short( int index )
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << formatField(first_name_);
	std::cout << "|" << std::setw(10) << formatField(last_name_);
	std::cout << "|" << std::setw(10)
		<< formatField(nick_name_) << "|" << std::endl;
}

void	Contact :: display_contact( void )
{
	std::cout << "First name:     " << first_name_ << std::endl;
	std::cout << "Last name:      " << last_name_ << std::endl;
	std::cout << "Nickname:       " << nick_name_ << std::endl;
	std::cout << "Phone number:   " << phone_number_ << std::endl;
	std::cout << "Darkest secret: " << darkest_secret_ << std::endl;
}
