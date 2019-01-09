// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - in lab
// SavingsAccount.h

#ifndef SAVACCOUNT_SICT_H
#define SAVACCOUNT_SICT_H

#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double intRate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif

