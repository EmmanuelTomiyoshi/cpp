#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account:: getTotalAmount( void ) {
	return _totalAmount;
}

int	Account:: getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account:: getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
	(void)initial_deposit;
}

Account::~Account()
{

}

void	Account::_displayTimestamp(void)
{

}

void	Account::displayAccountsInfos( void ) { 
	std::cout << "index:0" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	(void)deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	(void)withdrawal;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{

}

