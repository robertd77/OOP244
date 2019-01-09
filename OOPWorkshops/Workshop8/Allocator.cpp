// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - at home
// Allocator.cpp

#include <iostream>
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	const double intRate = 0.05; // Interest rate for accounts
	const double trFee = 0.50; // Transaction Fee 
	const double monthlyFee = 2.00; // Monthly fee for accounts

	iAccount* CreateAccount(const char* type, double iBalance) {
		// Creates a new account based on input type
		iAccount *p = nullptr;
		if (type[0] == 'S') { // Create Savings Account
			p = new SavingsAccount(iBalance, intRate);
		}
		if (type[0] == 'C') { // Create Chequing Account
			p = new ChequingAccount(iBalance, trFee, monthlyFee);
		}
		return p;
	}
	// Empty virtual constructor 
	iAccount:: ~iAccount() {}
}
