/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 17:20:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook :: PhoneBook()
{
	contacts_count_ = 0;
	Contact contacts_[8];
	cout << "Constractor for PhoneBook" << endl;
}

PhoneBook :: ~PhoneBook()
{
	
}

void PhoneBook :: add_contact()
{
	/* string input;
	while (std::getline(cin, input)) */

}

void PhoneBook :: search_contact()
{

}