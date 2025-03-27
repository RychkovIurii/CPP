/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:06:23 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/27 14:23:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address in memory of the string: " << &str << std::endl;
	std::cout << "Address in memory of the string by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in memory of the string by stringREF: " << &stringREF << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
	return (0);
}
