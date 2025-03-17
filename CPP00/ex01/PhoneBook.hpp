/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/17 17:52:04 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts_[8];
		int contacts_count_;
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact();
		void search_contact();
		Contact& get_contact(int index);
		int get_contact_count();
};

#endif
