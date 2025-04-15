/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:33 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/15 15:40:14 by irychkov         ###   ########.fr       */
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
	if (this != &obj)
		*this = obj;
	std::cout << "Copy constructor for Brain" << std::endl;
}

Brain &Brain :: operator=(const Brain &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Copy assignment operator for Brain" << std::endl;
	return *this;
}
