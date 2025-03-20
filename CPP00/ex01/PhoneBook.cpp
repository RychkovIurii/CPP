/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:31:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook :: PhoneBook( void )
{
	contacts_count_ = 0;
}

PhoneBook :: ~PhoneBook( void ) { }

void	PhoneBook :: add_contact( void )
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

void	PhoneBook :: search_contact( void )
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < contacts_count_; i++)
	{
		contacts_[i].display_short(i + 1);
		std::cout << "---------------------------------------------" << std::endl;
	}
}

int	PhoneBook :: get_contact_count( void )
{
	return (contacts_count_);
}

Contact&	PhoneBook :: get_contact( int index )
{
	return (contacts_[index]);
}
