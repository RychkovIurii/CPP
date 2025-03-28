/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/28 10:35:51 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <climits>

Fixed :: Fixed( void ) : _fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed ( const int value ) {
	std::cout << "Int constructor called" << std::endl;
	if (value > (INT_MAX >> _fractional_bits)
		|| value < (INT_MIN >> _fractional_bits))
	{
		std::cerr << "Error: value " << value << " is out of range" << std::endl;
		std::exit(1);
	}
	else
		_fixed_point_value = value << _fractional_bits;
}

Fixed :: Fixed ( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	if (value > INT_MAX / (1 << _fractional_bits)
		|| value < INT_MIN / (1 << _fractional_bits))
	{
		std::cerr << "Error: value " << value << " is out of range" << std::endl;
		std::exit(1);
	}
	else
	_fixed_point_value = roundf(value * (1 << _fractional_bits));
}

Fixed :: Fixed( const Fixed &obj ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed :: ~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const {
	return (_fixed_point_value);
}

void Fixed :: setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_value = raw;
}

Fixed &Fixed :: operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point_value = obj.getRawBits();
	return (*this);
}

float Fixed :: toFloat( void ) const {
	return ((float)_fixed_point_value / (1 << _fractional_bits));
}

int Fixed :: toInt( void ) const {
	return (_fixed_point_value >> _fractional_bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &obj) {
	out << obj.toFloat();
	return (out);
}

bool Fixed :: operator>( const Fixed &obj ) {
	return (_fixed_point_value > obj.getRawBits());
}

bool Fixed :: operator<( const Fixed &obj ) {
	return (_fixed_point_value < obj.getRawBits());
}

bool Fixed :: operator>=( const Fixed &obj ) {
	return (_fixed_point_value >= obj.getRawBits());
}
