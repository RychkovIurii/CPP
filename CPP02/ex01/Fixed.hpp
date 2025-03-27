/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:11 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/27 09:48:17 by irychkov         ###   ########.fr       */
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
		Fixed &operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);
