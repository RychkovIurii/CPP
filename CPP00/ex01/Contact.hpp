/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:18 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:28:22 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{
	private:
		std::string	first_name_;
		std::string	last_name_;
		std::string	nick_name_;
		std::string	phone_number_;
		std::string	darkest_secret_;
		std::string	formatField( std::string &field);
		void		take_input( std::string output, std::string &element );
	public:
		Contact( void );
		~Contact( void );
		void	set_contact( void );
		void	display_short( int index );
		void	display_contact( void );
};

#endif
