/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:14 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 12:53:10 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Our program handle input use 8 bits for fractional part.
Min value is around -8388608, max value is around 8388607.
*/

/*Overflow tests*/
/* static void test_overflow( void ) {
	Fixed z(8388608);

	std::cout << "z: " << z << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */
/* static void test_overflow2 ( void ) {
	Fixed z(-8388609);

	std::cout << "z: " << z << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */
/* static void test_overflow3 ( void ) {
	Fixed z(8388607);
	Fixed x(1);

	std::cout << "z+x: " << z+x << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */
/* static void test_overflow4 ( void ) {
	Fixed z(-8388608);
	Fixed x(1);

	std::cout << "z-x: " << z-x << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */
/* static void test_overflow5 ( void ) {
	Fixed z(8388607);
	Fixed x(8388607);

	std::cout << "z*x: " << z*x << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */
/* static void test_zero_division ( void ) {
	Fixed z(1);
	Fixed x(0);

	std::cout << "z/x: " << z/x << std::endl;
	std::cout << "We will not see this message" << std::endl;
} */

int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
