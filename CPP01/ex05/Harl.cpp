/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:31:40 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/26 13:51:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <bits/stdc++.h>

Harl :: Harl()
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

Harl :: ~Harl() { }

void Harl :: debug( void )
{
	std::cout << "Debug" << std::endl;
}

void Harl :: info( void )
{
	std::cout << "Info" << std::endl;
}

void Harl :: warning( void )
{
	std::cout << "Warning" << std::endl;
}

void Harl :: error( void )
{
	std::cout << "Error" << std::endl;
}



void Harl :: complain ( std::string level )
{
	int index = 0;
	while (index < 4 && levels[index] != level)
		index++;
	(this->*functions[index])();
	/* switch (index)
	{
		case 0:
			(this->*functions[0])();
			break;
		case 1:
			(this->*functions[1])();
			break;
		case 2:
			(this->*functions[2])();
			break;
		case 3:
			(this->*functions[3])();
			break;
		default:
			std::cout << "Nothing" << std::endl;
			break;
	} */
}
