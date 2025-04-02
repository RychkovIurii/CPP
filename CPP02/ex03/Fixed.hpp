/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:23:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 15:30:20 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
	public:
		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed( const Fixed &obj );
		~Fixed( void );
		Fixed &operator=( const Fixed &obj );
		bool operator>( const Fixed &obj ) const;
		bool operator<( const Fixed &obj ) const;
		bool operator>=( const Fixed &obj ) const;
		bool operator<=( const Fixed &obj ) const;
		bool operator==( const Fixed &obj ) const;
		bool operator!=( const Fixed &obj ) const;
		Fixed operator+( const Fixed &obj );
		Fixed operator-( const Fixed &obj );
		Fixed operator*( const Fixed &obj );
		Fixed operator/( const Fixed &obj );
		Fixed operator++( void );
		Fixed operator--( void );
		Fixed operator++( int );
		Fixed operator--( int );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);
