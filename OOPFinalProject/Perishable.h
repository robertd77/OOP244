// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Milestone 5
// Pershable.h

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include <iostream>
#include "Date.h"
#include "Good.h"

namespace aid {
	class Perishable : public Good {
		Date expDate;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};
	iGood* CreatePerishable();
}
#endif 

