/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:06:02 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/08 09:22:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string &dbFilename) {
	loadDB(dbFilename);
}

void BitcoinExchange::loadDB(const std::string &dbFilename) {
	std::ifstream dbFile(dbFilename);
	if (!dbFile.is_open()) {
		throw std::runtime_error("Could not open database file: " + dbFilename);
	}
	// Read db and populate exchangeRates
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
	auto it = exchangeRates.lower_bound(date);
	if (it != exchangeRates.end() && it->first == date) {
		return it->second;
	}
	if (it == exchangeRates.begin()) {
		throw std::out_of_range("No exchange rate available for date: " + date);
	}
	--it;
	return it->second;
}
