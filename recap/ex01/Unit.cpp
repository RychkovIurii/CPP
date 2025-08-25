/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:08 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 16:53:00 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.hpp"
#include "AMagic.hpp"
#include "ATarget.hpp"
#include <iostream>

Unit :: Unit(const std::string &nameInput, const std::string &titleInput) {
	_name = nameInput;
	_title = titleInput;
	std::cout << getName() << ": Constructor." << std::endl;
}

Unit :: ~Unit( void ) {
	std::cout << getName() << ": Destructor." << std::endl;
}
const std::string & Unit :: getName( void ) const {
	return _name;
}

const std::string & Unit :: getTitle( void ) const {
	return _title;
}

void Unit :: setTitle(const std::string &titleInput) {
	_title = titleInput;
}

void Unit :: introduce() const {
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << std::endl;
}

void Unit :: learnSpell(AMagic *obj) {
	if (obj != nullptr) {
		std::map<std::string, AMagic *>::iterator it = _spells.find(obj->getName());
		if (it == _spells.end())
			_spells[obj->getName()] = obj->clone();
	}
}

void Unit :: forgetSpell(const std::string &spellName) {
	std::map<std::string, AMagic *>::iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		delete it->second;
		_spells.erase(spellName);
	}
}

void Unit :: launchSpell(const std::string &spellName, ATarget &obj) {
	std::map<std::string, AMagic *>::iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		it->second->launch(obj);
	}
}
