/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:06 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/31 13:04:16 by irychkov         ###   ########.fr       */
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
	//std::cout << "value: " << _fixed_point_value << "\n";
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
	//std::cout << "value: " << _fixed_point_value << "\n";
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

bool Fixed :: operator<=( const Fixed &obj ) {
	return (_fixed_point_value <= obj.getRawBits());
}

bool Fixed :: operator==( const Fixed &obj ) {
	return (_fixed_point_value == obj.getRawBits());
}

bool Fixed :: operator!=( const Fixed &obj ) {
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
		std::cerr << "Error: division by zero" << std::endl; // throw std::runtime_error("Error: division by zero");
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
	--_fixed_point_value;
	if (_fixed_point_value == INT_MIN)
	{
		std::cerr << "Error: overflow" << std::endl;
		std::exit(1);
	}
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
