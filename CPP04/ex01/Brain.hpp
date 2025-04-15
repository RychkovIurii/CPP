/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:32:51 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 16:17:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain {
	public:
		Brain( void );
		~Brain( void );
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		std::string ideas[100];
};
