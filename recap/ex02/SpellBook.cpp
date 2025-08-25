/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:41 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:51:03 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"
#include "AMagic.hpp"

SpellBook :: SpellBook() {}

SpellBook :: ~SpellBook() {
	for (std::map<std::string, AMagic *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
}

void SpellBook :: learnSpell(AMagic *spell) {
	if (spell != nullptr) {
		std::map<std::string, AMagic *>::iterator it = _spells.find(spell->getName());
		if (it == _spells.end())
			_spells[spell->getName()] = spell->clone();
	}
	//delete spell;
}

void SpellBook :: forgetSpell(std::string const &spellName) {
	std::map<std::string, AMagic *>::iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		delete it->second;
		_spells.erase(spellName);
	}
}

AMagic* SpellBook :: createSpell(std::string const &spellName) {
	std::map<std::string, AMagic *>::iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		return it->second->clone();
	}
	return nullptr;
}
