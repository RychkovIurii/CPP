/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:05 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 19:52:49 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>
#include "SpellBook.hpp"

class AMagic;
class ATarget;

class Unit {
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellbook;
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
		void learnSpell(AMagic *obj);
		void forgetSpell(const std::string &spellName);
		void launchSpell(const std::string &spellName, ATarget &obj);
};
