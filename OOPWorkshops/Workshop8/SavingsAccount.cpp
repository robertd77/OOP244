// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - in lab
// SavingsAccount.cpp

#include <iostream>
#include <cstring>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	// Construct a savings account with interest rate if iRate is valid
	SavingsAccount::SavingsAccount(double iBalance, double iRate) : Account(iBalance) {
		if (iRate > 0.00) {intRate = iRate;}
		else { intRate = 0.00;}
	}
	// Calculate new account balance with accumulated interest
	void SavingsAccount::monthEnd() {
		credit(balance() * intRate);
	}
	// Display a savings account's details
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os.precision(2);
		os.setf(os.fixed, os.floatfield);
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << intRate * 100 << std::endl;
	}
}
