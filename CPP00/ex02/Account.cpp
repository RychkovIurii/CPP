/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:28:17 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/19 19:43:31 by irychkov         ###   ########.fr       */
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

void	Account  ::  displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
