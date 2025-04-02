/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:26:03 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 15:47:17 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point( void );
		Point( const Fixed x, const Fixed y );
		Point( const Point &obj );
		~Point( void );
		Point &operator=( const Point &obj ) = delete; // Think about it
		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
