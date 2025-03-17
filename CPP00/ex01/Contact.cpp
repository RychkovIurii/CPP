/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/17 18:14:16 by irychkov         ###   ########.fr       */
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

void Contact::set_contact()
{
	cout << "Enter first name: ";
	std::getline(cin, first_name_); // check ctlr + d
	cout << "Enter last name: ";
	std::getline(cin, last_name_);
	cout << "Enter nickname: ";
	std::getline(cin, nick_name_);
	cout << "Enter phone number: ";
	std::getline(cin, phone_number_);
	cout << "Enter darkest secret: ";
	std::getline(cin, darkest_secret_);
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
