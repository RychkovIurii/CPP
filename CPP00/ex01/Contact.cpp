/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 14:46:48 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact :: Contact()
{

}

Contact :: ~Contact()
{

}

void Contact::set_contact()
{

}

void Contact::display_contact(int index)
{
	cout << "First name:     " << first_name_ << endl;
	cout << "Last name:      " << last_name_ << endl;
	cout << "Nickname:       " << nick_name_ << endl;
	cout << "Phone number:   " << phone_number_ << endl;
	cout << "Darkest secret: " << darkest_secret_ << endl;
}