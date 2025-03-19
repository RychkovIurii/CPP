/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:28:17 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 19:52:10 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account  ::  getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account  ::  getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account  ::  getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account  ::  getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account  ::  _displayTimestamp( void )
{
	// here we need to implement the function that will display the current time
	// for now we will just print the string "timestamp"
	std::cout << "timestamp";
}

void	Account  ::  displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account  ::  displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
