/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 12:48:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook :: PhoneBook()
{
	contacts_count_ = 0;
}

PhoneBook :: ~PhoneBook()
{
	
}

void PhoneBook :: add_contact()
{
	if (contacts_count_ < 8)
	{
		contacts_[contacts_count_].set_contact();
		contacts_count_++;
	}
	else
	{
		for (int i = 1; i < 8; i++)
		{
			contacts_[i - 1] = contacts_[i];
		}
		contacts_[7].set_contact();
	}
}

void PhoneBook :: search_contact()
{
	cout << "_____________________________________________" << endl;
	cout << "|     Index|First Name| Last Name|  Nickname|" << endl;
	for (int i = 0; i < contacts_count_; i++)
	{
		contacts_[i].display_short(i + 1);
	}
	cout << "_____________________________________________" << endl;
}

int PhoneBook :: get_contact_count()
{
	return (contacts_count_);
}

Contact& PhoneBook :: get_contact(int index)
{
	return (contacts_[index]);
}
