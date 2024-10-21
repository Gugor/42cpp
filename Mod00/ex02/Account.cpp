#include "Account.hpp"

#pragma region Attributes
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
#pragma endregion

#pragma region Constructors & Destructors
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}
#pragma endregion

#pragma region Getters
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
#pragma endregion

#pragma region Display Methods
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	char        buf[80];
	std::time_t curTime = std::time(0);
	std::tm*    locTime = std::localtime(&curTime);

	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", locTime);
	std::cout << buf << " ";
}
#pragma endregion

#pragma region Main Methods
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount > withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:";
		std::cout << "refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const
{
	return 0;
}
#pragma endregion
