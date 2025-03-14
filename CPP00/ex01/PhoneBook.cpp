/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:27 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 12:32:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook :: PhoneBook()
{
	contacts_count_ = 0;
	Contact contacts_[8];
	std::cout << "Constractor for PhoneBook" << std::endl;
}

PhoneBook :: ~PhoneBook()
{
	
}

void PhoneBook :: add_contact()
{

}

void PhoneBook :: search_contact()
{

}