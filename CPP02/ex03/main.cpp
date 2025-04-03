/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:23:14 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/03 10:14:51 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void ) {
	// Define the vertices of the triangle
	Point a(0.0f, 0.0f);   // Vertex A
	Point b(10.0f, 0.0f);  // Vertex B
	Point c(5.0f, 10.0f);  // Vertex C

	// Define test points
	Point p1(5.0f, 5.0f);   // Inside the triangle
	Point p2(0.0f, 0.0f);   // On vertex A
	Point p3(10.0f, 0.0f);  // On vertex B
	Point p4(5.0f, 10.0f);  // On vertex C
	Point p5(7.0f, 5.0f);   // Inside the triangle
	Point p6(10.0f, 5.0f);  // Outside the triangle
	Point p7 = p6;          // Outside the triangle

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

	std::cout << "Copy of last Point (10,5): ";
	if (bsp(a, b, c, p7))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	return (0);
}
