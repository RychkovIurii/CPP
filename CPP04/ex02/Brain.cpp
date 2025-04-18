/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:33 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 11:50:20 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain :: Brain( void )
{
	std::cout << "Constructor for Brain" << std::endl;
}

Brain :: ~Brain( void )
{
	std::cout << "Destructor for Brain" << std::endl;
}

Brain :: Brain ( const Brain &obj )
{
	std::cout << "Copy constructor for Brain" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
}

Brain &Brain :: operator=(const Brain &obj)
{
	std::cout << "Copy assignment operator for Brain" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
	return *this;
}
