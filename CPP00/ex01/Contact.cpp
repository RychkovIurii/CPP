/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 12:40:14 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact :: Contact()
{

}

Contact :: ~Contact()
{

}

string Contact :: formatField(string &field)
{
	if (field.length() > 10) {
		return (field.substr(0, 9) + ".");
	}
	return (field);
}

void Contact :: take_input(string output, string &element)
{
	if (!cin.eof())
		cout << output;
	std::getline(cin, element);
	if (cin.eof())
		return ;
	while (element.compare("") == 0)
	{
		cout << output;
		std::getline(cin, element);
		if (cin.eof())
			return ;
	}
	
}

void Contact :: set_contact()
{
	take_input("Enter first name: ", first_name_);
	take_input("Enter last name: ", last_name_);
	take_input("Enter nickname: ", nick_name_);
	take_input("Enter phone number: ", phone_number_);
	take_input("Enter darkest secret: ", darkest_secret_);
	if (!cin.eof())
		cout << "Contact added." << endl;
}

void Contact::display_short(int index)
{
	cout << "|" << std::setw(10) << index;
	cout << "|" << std::setw(10) << formatField(first_name_);
	cout << "|" << std::setw(10) << formatField(last_name_);
	cout << "|" << std::setw(10) << formatField(nick_name_) << "|" << endl;
}

void Contact::display_contact(int index)
{
	cout << "First name:     " << first_name_ << endl;
	cout << "Last name:      " << last_name_ << endl;
	cout << "Nickname:       " << nick_name_ << endl;
	cout << "Phone number:   " << phone_number_ << endl;
	cout << "Darkest secret: " << darkest_secret_ << endl;
}
