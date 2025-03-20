/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:32:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts_[8];
		int		contacts_count_;
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void		add_contact( void );
		void		search_contact( void );
		Contact&	get_contact( int index );
		int			get_contact_count( void );
};

#endif
