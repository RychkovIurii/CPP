/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:23:08 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <climits>

Fixed :: Fixed( void ) : _fixed_point_value(0) { }

Fixed :: Fixed ( const int value ) {
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
	*this = obj;
}

Fixed :: ~Fixed( void ) { }

int Fixed :: getRawBits(void) const {
	return (_fixed_point_value);
}

void Fixed :: setRawBits(int const raw) {
	_fixed_point_value = raw;
}

Fixed &Fixed :: operator=(const Fixed &obj) {
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

bool Fixed :: operator>( const Fixed &obj ) const {
	return (_fixed_point_value > obj.getRawBits());
}

bool Fixed :: operator<( const Fixed &obj ) const {
	return (_fixed_point_value < obj.getRawBits());
}

bool Fixed :: operator>=( const Fixed &obj ) const {
	return (_fixed_point_value >= obj.getRawBits());
}

bool Fixed :: operator<=( const Fixed &obj ) const {
	return (_fixed_point_value <= obj.getRawBits());
}

bool Fixed :: operator==( const Fixed &obj ) const {
	return (_fixed_point_value == obj.getRawBits());
}

bool Fixed :: operator!=( const Fixed &obj ) const {
	return (_fixed_point_value != obj.getRawBits());
}

Fixed Fixed :: operator+( const Fixed &obj ) {
	Fixed result;
	long long sum = static_cast<long long>(_fixed_point_value) + static_cast<long long>(obj.getRawBits());

	if ((sum > INT_MAX || sum < INT_MIN))
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(sum));
	return (result);
}

Fixed Fixed :: operator-( const Fixed &obj ) {
	Fixed result;
	long long diff = static_cast<long long>(_fixed_point_value) - static_cast<long long>(obj.getRawBits());
	if ((diff > INT_MAX || diff < INT_MIN))
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(diff));
	return (result);
}

Fixed Fixed :: operator*( const Fixed &obj ) {
	Fixed result;
	long long product = (static_cast<long long>(_fixed_point_value) * static_cast<long long>(obj.getRawBits()));
	product = product >> _fractional_bits;
	if ((product > INT_MAX || product < INT_MIN))
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(product));
	return (result);
}

Fixed Fixed :: operator/( const Fixed &obj ) {
	Fixed result;
	int second_raw = obj.getRawBits();
	if (second_raw == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		std::exit(1);
	}
	long long quotient = (static_cast<long long>(_fixed_point_value << _fractional_bits) / static_cast<long long>(second_raw));
	if ((quotient > INT_MAX || quotient < INT_MIN))
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(quotient));
	return (result);
}

Fixed Fixed :: operator++( void ) {
	if (_fixed_point_value == INT_MAX)
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	++_fixed_point_value;
	return (*this);
}

Fixed Fixed :: operator--( void ) {
	if (_fixed_point_value == INT_MIN)
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	--_fixed_point_value;
	return (*this);
}

Fixed Fixed :: operator--( int ) {
	if (_fixed_point_value == INT_MIN)
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	Fixed tmp(*this);
	_fixed_point_value--;
	return (tmp);
}

Fixed Fixed :: operator++( int ) {
	if (_fixed_point_value == INT_MAX)
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
	Fixed tmp(*this);
	_fixed_point_value++;
	return (tmp);
}

Fixed &Fixed :: min(Fixed &a, Fixed &b)
{
	if ( a < b )
		return (a);
	return (b);
}

Fixed &Fixed :: max(Fixed &a, Fixed &b)
{
	if ( a > b )
		return (a);
	return (b);
}

const Fixed &Fixed :: min(const Fixed &a, const Fixed &b)
{
	if ( a < b )
		return (a);
	return (b);
}

const Fixed &Fixed :: max(const Fixed &a, const Fixed &b)
{
	if ( a > b )
		return (a);
	return (b);
}
