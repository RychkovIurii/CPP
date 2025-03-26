/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:37:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/26 16:49:09 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl :: Harl( void )
{
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
	this->functions[0] = &Harl::debug;
	this->functions[1] = &Harl::info;
	this->functions[2] = &Harl::warning;
	this->functions[3] = &Harl::error;
}

Harl :: ~Harl( void ) { }

void Harl :: debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Debug" << std::endl << std::endl;
}

void Harl :: info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Info" << std::endl << std::endl;
}

void Harl :: warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Warning" << std::endl << std::endl;
}

void Harl :: error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Error" << std::endl << std::endl;
}

void Harl :: complain ( std::string level )
{
	int index = 0;
	while (index < 4 && levels[index] != level)
		index++;
	switch (index)
	{
		case 0:
			(this->*functions[index])();
			index++;
		case 1:
			(this->*functions[index])();
			index++;
		case 2:
			(this->*functions[index])();
			index++;
		case 3:
			(this->*functions[index])();
			index++;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
			break;
	}
}
