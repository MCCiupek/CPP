#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	this->_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return;
}

Account::~Account() {

	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}

int	Account::getNbAccounts(void) {

	return _nbAccounts;
}

int	Account::getTotalAmount(void) {

	return _totalAmount;
}

int	Account::getNbDeposits(void) {

	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {

	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {

	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit ) {

	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amout:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	this->_amount += deposit;
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amout:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "nb_withdrawal:" << this->_nbWithdrawals << ";" << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {

	return (this->_amount > 0);
}

void	Account::displayStatus( void ) const {

	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

void	Account::_displayTimestamp( void ) {

	std::time_t t = time(0);
	std::tm		*now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << now->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << now->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << now->tm_hour 
		<< std::setfill('0') << std::setw(2) << now->tm_min
		<< std::setfill('0') << std::setw(2) << now->tm_sec << "]";
}
