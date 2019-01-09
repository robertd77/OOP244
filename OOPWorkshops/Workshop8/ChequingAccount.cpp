// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - at home
// ChequingAccount.cpp

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// Constructs a Chequing account object 
	ChequingAccount::ChequingAccount(double iBalance, double tFee, double mFee) : Account(iBalance) {
		// Fees must be positive to be valid, set to zero otherwise
		tFee > 0.00 ? transFee = tFee : transFee = 0.00;
		mFee > 0.00 ? mnthEndFee = mFee : mnthEndFee = 0.00;
	}
	// Add credit amount to account if it is valid, subtract transaction fee
	bool ChequingAccount::credit(double plus) {
		bool success = Account::credit(plus);
		if (success) {
			Account::debit(transFee);
		}
		return success;
	}
	// Subtract debit amount from account, subtract transaction fee
	bool ChequingAccount::debit(double sub) {
		bool success = Account::debit(sub);
		if (success) {
			Account::debit(transFee);
		}
		return success;
	}
	// Subtract monthly fee from account
	void ChequingAccount::monthEnd() {
		Account::debit(mnthEndFee);
	}
	// Output account details to console
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
		os.precision(2);
		os.setf(os.fixed, os.floatfield);
		os << "Balance: " << balance() << std::endl;
		os << "Per Transaction Fee: " << transFee << std::endl;
		os << "Monthly Fee: " << mnthEndFee << std::endl;
	}
}