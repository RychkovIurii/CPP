/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:23:14 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/02 15:46:48 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void ) {
	// Define the vertices of the triangle
	Point a(Fixed(0), Fixed(0));   // Vertex A
	Point b(Fixed(10), Fixed(0));  // Vertex B
	Point c(Fixed(5), Fixed(10));  // Vertex C

	// Define test points
	Point p1(Fixed(5), Fixed(5));   // Inside the triangle
	Point p2(Fixed(0), Fixed(0));   // On vertex A
	Point p3(Fixed(10), Fixed(0));  // On vertex B
	Point p4(Fixed(5), Fixed(10));  // On vertex C
	Point p5(Fixed(7), Fixed(5));   // Inside the triangle
	Point p6(Fixed(10), Fixed(5));  // Outside the triangle

	// Run tests and print results
	std::cout << "Point (5,5): ";
	if (bsp(a, b, c, p1))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	std::cout << "Point (0,0): ";
	if (bsp(a, b, c, p2))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	std::cout << "Point (10,0): ";
	if (bsp(a, b, c, p3))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	std::cout << "Point (5,10): ";
	if (bsp(a, b, c, p4))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	std::cout << "Point (7,5): ";
	if (bsp(a, b, c, p5))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	std::cout << "Point (10,5): ";
	if (bsp(a, b, c, p6))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	return (0);
}

// Test copy constructor and assignment operator!
