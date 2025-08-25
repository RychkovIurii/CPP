/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:34:00 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class AMagic;

class ATarget {
	protected:
		std::string _type;
		ATarget( void ) = delete;
		ATarget(ATarget &obj) = delete;
		ATarget &operator=(ATarget &obj) = delete;
	public:
		ATarget(const std::string &type);
		virtual ~ATarget( void );
		const std::string & getType( void ) const;
		void getHitBySpell(AMagic const &obj) const;
		virtual ATarget * clone() const = 0;
};