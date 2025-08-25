/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:38 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:04:54 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>

class AMagic;

class SpellBook {
	private:
		std::map<std::string, AMagic *> _spells;
		SpellBook(SpellBook &obj) = delete;
		SpellBook &operator=(SpellBook &obj) = delete;
	public:
		SpellBook( void );
		~SpellBook( void );
		void learnSpell(AMagic*);
		void forgetSpell(std::string const &);
		AMagic* createSpell(std::string const &);
};