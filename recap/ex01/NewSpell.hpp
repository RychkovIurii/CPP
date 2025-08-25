/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSpell.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:13:29 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:22:23 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMagic.hpp"

class NewSpell : public AMagic {
	public:
		NewSpell();
		virtual ~NewSpell();
		virtual AMagic * clone() const override;
};
