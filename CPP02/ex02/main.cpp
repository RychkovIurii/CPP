/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:58:14 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/28 16:36:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Our program handle input use 8 bits for fractional part.
Min value is -8388608, max value is 8388607.
*/
int main( void )
{
	/* Fixed a(1);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl; */
	//std::cout << "result" << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	Fixed a (4.1f);
	Fixed b (0);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a / b) << std::endl;


	return 0;
}
