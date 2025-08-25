/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMagic.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:33:50 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 16:53:41 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ATarget;

class AMagic {
	protected:
		std::string _name;
		std::string _effects;
		AMagic( void ) = delete;
		AMagic(AMagic &obj) = delete;
		AMagic &operator=(AMagic &obj) = delete;
	public:
		AMagic(const std::string &nameInput, const std::string &effectsInput);
		virtual ~AMagic( void );
		std::string getName( void ) const;
		std::string getEffects( void ) const;
		virtual AMagic * clone() const = 0;
		void launch(ATarget const &obj) const;
};