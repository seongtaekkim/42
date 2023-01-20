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

void Account::makeDeposit(int deposit) {
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

bool Account::makeWithdrawal(int withdrawal) {
	this->_nbWithdrawals = (withdrawal > 0 ? 1 : 0);
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

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp(void) {
	time_t	rawtime;
	char	buffer[20];

	time(&rawtime);
	strftime(buffer, 20, "[%Y%m%d_%I%M%S] ", localtime(&rawtime));
	std::cout << buffer;
}

int	Account::checkAmount(void) const {
	return (0);
}