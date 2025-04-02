/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:27:50 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 15:34:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0) { }

Point::Point( const Fixed x, const Fixed y ) : x(x), y(y) { }

Point::~Point( void ) { }

Point :: Point( const Point &obj ) : x(obj.getX()), y(obj.getY()) { }

Fixed Point :: getX( void ) const {
	return (x);
}

Fixed Point :: getY( void ) const {
	return (y);
}
