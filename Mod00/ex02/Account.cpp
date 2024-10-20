#include "Account.hpp"

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

void Account::displayAccountsInfos(void)
{
    
}

Account::Account(int initial_deposit)
{
    return ;
}

Account::~Account(void)
{
    return ;
}

void Account::makeDeposit(int deposit)
{
}

bool Account::makeWithdrawal(int withdrawal)
{
    return false;
}

int Account::checkAmount(void) const
{
    return 0;
}

void Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
}
