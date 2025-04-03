/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:26:03 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/03 10:11:10 by irychkov         ###   ########.fr       */
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
		Point( const float x, const float y );
		Point( const Point &obj );
		~Point( void );
		Point &operator=( const Point &obj ) = delete;
		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
