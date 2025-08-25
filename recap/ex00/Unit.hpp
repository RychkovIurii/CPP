/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:05 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 15:26:48 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Unit {
	private:
		std::string _name;
		std::string _title;
		Unit( void ) = delete;
		Unit(Unit &obj) = delete;
		Unit &operator=(Unit &obj) = delete;
	public:
		Unit(const std::string &nameInput, const std::string &titleInput);
		~Unit( void );
		const std::string &getName( void ) const;
		const std::string &getTitle( void ) const;
		void setTitle(const std::string &titleInput);
		void introduce() const;
};
