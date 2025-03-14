/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:18 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/14 12:30:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		Contact();
		~Contact();
		void set_contact();
		void display_contact(int index);
};

#endif
