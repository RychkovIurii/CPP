/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:06:02 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/08 14:02:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include <limits>

BitcoinExchange::BitcoinExchange(const std::string &dbFilename) {
	loadDB(dbFilename);
}

static bool isValidDate(int year, int month, int day) {
	if (month < 1 || month > 12)
		return false;

	static const int daysInMonth[] = {
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	int maxDay = daysInMonth[month - 1];

	if (month == 2 &&
		((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		maxDay = 29;
	}

	return day >= 1 && day <= maxDay;
}

static std::string getTodayDate() {
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d");
	return oss.str();
}

void BitcoinExchange::loadDB(const std::string &dbFilename) {
	std::ifstream dbFile(dbFilename);
	if (!dbFile.is_open()) {
		throw std::runtime_error("Could not open database file: " + dbFilename);
	}
	std::string line;
	std::getline(dbFile, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Invalid database headers: " + dbFilename);
	}
	std::regex pattern(R"(^(\d{4})-(\d{2})-(\d{2}),(\d+(\.\d{1,2})?)$)");
	std::smatch match;
	size_t lineNum = 1;
	while (std::getline(dbFile, line)) {
		lineNum++;
		if (std::regex_match(line, match, pattern)) {
			int year = std::stoi(match[1]);
			int month = std::stoi(match[2]);
			int day = std::stoi(match[3]);
			if (!isValidDate(year, month, day)) {
				std::cerr << "Invalid date in database: " << line << std::endl;
			}
			std::string date = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
			try {
				float rate = std::stof(match[4]);
				if (exchangeRates.find(date) != exchangeRates.end()) {
					throw std::runtime_error("Duplicate date found in DB: " + date);
				}
				exchangeRates[date] = rate;
			} catch (const std::out_of_range&) {
				throw std::runtime_error("Exchange rate value is out of range: " + match[4].str());
			} catch (const std::invalid_argument&) {
				throw std::runtime_error("Invalid exchange rate value: " + match[4].str());
			}
		} else {
			throw std::runtime_error("Invalid line at " + std::to_string(lineNum) + ": " + line);
		}
	}
	dbFile.close();
	if (exchangeRates.empty()) {
		throw std::runtime_error("Database is empty or no valid exchange rates found.");
	}
	if (exchangeRates.begin()->first < "2009-01-01") {
		throw std::runtime_error("Bitcoin was created on 2009, database contains earlier dates: " + exchangeRates.begin()->first);
	}
	std::string today = getTodayDate();
	if (exchangeRates.rbegin()->first > today) {
		throw std::runtime_error("Database contains future dates: " + exchangeRates.rbegin()->first);
	}
	//std::cout << "Database loaded successfully with " << exchangeRates.size() << " entries." << std::endl;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
	auto it = exchangeRates.lower_bound(date);
	if (it != exchangeRates.end() && it->first == date) {
		return it->second;
	}
	if (it == exchangeRates.begin()) {
		throw std::out_of_range("no exchange rate available");
	}
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputFilename) const {
	std::ifstream inputFile(inputFilename);
	if (!inputFile.is_open()) {
		throw std::runtime_error("could not open file.");
	}
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value") {
		throw std::runtime_error("Invalid headers: " + inputFilename);
	}
	std::regex pattern(R"(^(\d{4})-(\d{2})-(\d{2}) \| (-?\d+(\.\d+)?)$)");
	std::smatch match;

	while (std::getline(inputFile, line)) {
		if (std::regex_match(line, match, pattern)) {
			int year = std::stoi(match[1]);
			int month = std::stoi(match[2]);
			int day = std::stoi(match[3]);
			if (!isValidDate(year, month, day)) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			std::string date = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
			std::string today = getTodayDate();
			if (date > today) {
				std::cout << "Error: date is in the future => " << date << std::endl;
				continue;
			}
			if (date < "2009-01-01") {
				std::cout << "Error: date is before Bitcoin creation => " << date << std::endl;
				continue;
			}
			try {
				double value;
				try {
				value = std::stod(match[4]);
				} catch (const std::exception &e) {
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
				}
				if (value < 0.0) {
					std::cout << "Error: not a positive number." << std::endl;
					continue;
				}
				if (value > 1000.0) {
					std::cout << "Error: too large a number." << std::endl;
					continue;
				}
				float rate = getExchangeRate(date);
				double result = value * static_cast<double>(rate);
				if (result > std::numeric_limits<float>::max()) {
					std::cout << "Result exceeds maximum float value: " + std::to_string(result) << "for date: " << date << std::endl;
					continue;
				}
				std::cout << date << " => " << value << " = " << result << std::endl;
			} catch (const std::exception &e) {
				std::cout << "Error: " << e.what() << " for date: " << date << std::endl;
			}
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	inputFile.close();
}
