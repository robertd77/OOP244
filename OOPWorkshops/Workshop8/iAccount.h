	// Robert Dominato
	// rdominato@myseneca.ca
	// 119823185
	// OOP244 Fall 2018
	// Workshop 8 - in lab
	// iAccount.h

#ifndef SICT_IACCOUNT_H	
#define SICT_IACCOUNT_H


#include <iostream>

namespace sict {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	    virtual ~iAccount() = 0;
	};

	iAccount* CreateAccount(const char*, double);
}
#endif 
