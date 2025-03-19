/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:31:47 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 20:33:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

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
	// here we need to implement the function that will display the current time
	// for now we will just print the string "timestamp"
	std::cout << "timestamp";
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

}

bool	Account :: makeWithdrawal( int withdrawal )
{
	return (true); // for now
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
