/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:05:58 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/08 11:54:32 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange() = delete;
		BitcoinExchange(const std::string &dbFilename);
		BitcoinExchange(const BitcoinExchange &other) = delete;
		BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
		~BitcoinExchange() = default;
		void processInputFile(const std::string &inputFilename) const;
	private:
		std::map<std::string, float> exchangeRates;
		void loadDB(const std::string &dbFilename);
		float getExchangeRate(const std::string &date) const;
};
