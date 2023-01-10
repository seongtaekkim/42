/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:46:53 by staek             #+#    #+#             */
/*   Updated: 2023/01/10 21:40:53 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}
int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}
/*
accounts:8;total:20049;deposits:0;withdrawals:0
*/
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposits:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << Account::_nbAccounts << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
	Account::_nbAccounts++;
}
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
					<< "amount:" << _amount << ";"
					<< "closed" << std::endl;
}
 //index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit) {
	this->_nbDeposits = (deposit > 0 ? 1 : 0);
	Account::_totalNbDeposits += this->_nbDeposits;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
					<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
					<< "amount:" << this->_amount << ";"
					<< "nb_deposits:" << this->_nbDeposits
					<< std::endl;
}
/*
index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
index:5;p_amount:23;withdrawal:refused
*/
bool	Account::makeWithdrawal(int withdrawal) {
	this->_nbWithdrawals = (withdrawal > 0 ? 1 : 0);
	///if (this->_amount < withdrawal)
		//return (false);
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:";
				if (this->_nbWithdrawals == 1 && this->_amount > withdrawal) {
					Account::_totalAmount -= withdrawal;
					Account::_totalNbWithdrawals += this->_nbWithdrawals;
					std::cout << withdrawal << ";";
				}
				else {
					std::cout << "refused" << std::endl;;
					this->_nbWithdrawals = 0;
					return (false);
				}
				this->_amount -= withdrawal;
				std::cout << "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}
int		Account::checkAmount(void) const {
	std::cout << "checkamount " << std::endl;
	return (0);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t	rawtime;
	char	buffer[30];

	time(&rawtime);
	strftime(buffer, 30, "[%Y%m%d_%I%M%S] ", localtime(&rawtime));
	std::cout << buffer;
}
