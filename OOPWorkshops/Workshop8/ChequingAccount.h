// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - at home
// ChequingAccount.h

#ifndef  CHEQACCOUNT_SICT_H
#define CHEQACCOUNT_SICT_H

#include <iostream>
#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		double transFee;
		double mnthEndFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif 

