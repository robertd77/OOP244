// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Milestone 5
// Good.h

#ifndef  AID_GOOD_H
#define AID_GOOD_H

#include <iostream>
#include "Error.h"
#include "iGood.h"

namespace aid {
	const int max_sku_length = 7;// Max length for good's sku
	const int max_name_length = 75;// Max length for a good's name
	const int max_unit_length = 10;// max length for a good's description
	const double tax_rate = 0.13; // Tax rate for taxable goods

	class Good : public iGood {
		char goodType;
		char goodSku[max_sku_length + 1];
		char goodDesc[max_unit_length + 1];
		char* goodName;
		int qtyOnHand;
		int qty_needed;
		double iPrice; // Initial price of a good before tax
		bool taxable;
		Error error;
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Good(char g_type = 'N');
		Good(const char* sku, const char* name, const char* unit, int onHand = 0, bool taxed = true, double iPrice = 0, int needed = 0);
		Good(const Good&);
		Good& operator=(const Good&);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const;
		int operator+=(int);
	};

	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);
	iGood* CreateGood();
}
#endif
