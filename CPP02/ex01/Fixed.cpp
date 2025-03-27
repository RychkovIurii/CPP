/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/27 09:39:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed( void ) : _fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed ( const int value ) {
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_value = value;
}

Fixed :: Fixed ( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	// What should be done here?
}

Fixed :: Fixed( const Fixed &obj ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed :: ~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_value;
}

void Fixed :: setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_value = raw;
}

Fixed &Fixed :: operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point_value = obj.getRawBits();
	return *this;
}
