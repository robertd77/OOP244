// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - in lab
// Account.cpp

#include <iostream>
#include "Account.h"
using namespace std;

namespace sict{
	// Add initial balance to account if it is valid (positive)
	Account::Account(double iBalance) {
		if (iBalance < 0.00) {
			c_Balance = 0.00;
		}
		else {
			c_Balance = iBalance;
		}
	}
	// Subtract debit amount from account balance
	bool Account::debit(double sub) {
		bool success = false;
		if (sub > 0.00) {
			c_Balance -= sub;
			success = true;
		}
		return success;
	}
	// Add credit amount to account balance
	bool Account::credit(double add) {
		bool success = false;
		if (add > 0.00) {
			c_Balance += add;
			success = true;
		}
		return success;
	}
	// Returns current balance of account
	double Account::balance() const {
		return c_Balance;
	}
}
