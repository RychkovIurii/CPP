/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:31:47 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/20 10:50:13 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account :: _nbAccounts = 0;
int	Account :: _totalAmount = 0;
int	Account :: _totalNbDeposits = 0;
int	Account :: _totalNbWithdrawals = 0;

int	Account :: getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account :: getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account :: getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account :: getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account :: _displayTimestamp( void )
{
	time_t timestamp;
	time(&timestamp); 
	char buffer [16];
	strftime(buffer, 80, "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << buffer << "]";
}

void	Account :: displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account :: displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account :: Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account :: ~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account :: makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account :: makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account :: checkAmount( void ) const
{
	return (_amount); // for now
}

Account :: Account( void ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
}
