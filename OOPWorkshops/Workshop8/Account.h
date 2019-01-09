// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Workshop 8 - in lab
// Account.h

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H


#include <iostream>
#include"iAccount.h"


namespace sict {
	class Account : public iAccount {
		double c_Balance;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}

#endif
