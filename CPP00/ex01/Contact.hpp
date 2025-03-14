/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:18 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 17:21:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Contact
{
	private:
		string first_name_;
		string last_name_;
		string nick_name_;
		string phone_number_;
		string darkest_secret_;
	public:
		Contact();
		~Contact();
		void set_contact();
		void display_short(int index);
		void display_contact(int index);
};

#endif
