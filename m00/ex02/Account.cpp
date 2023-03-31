#include "Account.hpp"
#include <sys/time.h>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int Account::getNbAccounts(void){return (_nbAccounts);}
int Account::getTotalAmount(void){return (_totalAmount);}
int Account::getNbDeposits(void){return(_totalNbDeposits);}
int Account::getNbWithdrawals(){return(_totalNbWithdrawals);}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_nbAccounts += 1;
	this->_amount = initial_deposit; 
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts - 1;
	std::cout << "index:" << _accountIndex <<";amount:"<< this->_amount << ";created" << std::endl;
}

Account::~Account(){_displayTimestamp();	std::cout << "index:" << _accountIndex <<";amount:"<< this->_amount <<";closed" << std::endl;}

////////////////////////////////////////////////////////////////////

void	Account::_displayTimestamp()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	std::cout << "[" << (t.tv_sec) << "_" << t.tv_usec << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void	Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_nbDeposits += 1;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;		
		return(1);
	}
	std::cout << ";withdrawal:refused"<< std::endl; 
	return(0);
}