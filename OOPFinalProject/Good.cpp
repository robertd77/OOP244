// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Milestone 5
// Good.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Good.h"
//#include "Error.h"

using namespace std;

namespace aid {
	// Set Good to empty state
	Good::Good(char g_type) {
		goodType = g_type;
		goodSku[0] = '\0';
		goodDesc[0] = '\0';
		goodName = nullptr;
		qtyOnHand = 0;
		qty_needed = 0;
		iPrice = 0.00;
		taxable = true;

	}
	// Creates a Good object with all provided information
	Good::Good(const char * sku, const char * t_name, const char * unit, int onHand, bool taxed, double t_iPrice, int needed) {
		name(t_name);
		strncpy(goodSku, sku, max_sku_length);
		goodSku[max_sku_length] = '\0';
		strncpy(goodDesc, unit, max_unit_length);
		goodDesc[max_unit_length] = '\0';

		qtyOnHand = onHand;
		qty_needed = needed;
		taxable = taxed;
		iPrice = t_iPrice;
	}
	// Destructor
	Good::~Good() {
		delete[] goodName;
		goodName = nullptr;
	}
	// Stores the name of a Good in dynamic memory
	void Good::name(const char* nameAddress) {
		if (nameAddress != nullptr) {
			int length = strlen(nameAddress);
			goodName = new char[length + 1];

			for (int i = 0; i < length; ++i) {
				goodName[i] = nameAddress[i];
			}
			goodName[length] = '\0';
		}
	}
	// returns name of current Good if it has one,nullptr otherwise
	const char* Good::name() const {
		return (goodName[0] != '\0') ? goodName : nullptr;
		
	}
	// returns current Goods's sku#
	const char* Good::sku() const {
		return goodSku;
	}
	// returns description of current Good
	const char* Good::unit() const {
		return goodDesc;
	}
	// returns true if current Good is taxable
	bool Good::taxed() const {
		return taxable;
	}
	// returns initial price of current Good
	double Good::itemPrice() const {
		return iPrice;
	}
	// Calculates a Good's price including any applicable tax
	double Good::itemCost() const {
		double itemCost;
		if (taxed()) {
			itemCost = itemPrice() * (tax_rate + 1);
		}
		else { itemCost = itemPrice(); }
		return itemCost;
	}
	// Stores message in the Error object to current object
	void Good::message(const char* err) {
		error.message(err);
	}
	// Returns true if Error object is clear
	bool Good::isClear() const {
		return error.isClear();
	}
	// Copy Assignment Operator
	Good& Good::operator=(const Good& src) {
		if (this != &src) {
			if (src.goodType != '\0') {
				goodType = src.goodType;
			}
			strncpy(goodSku, src.goodSku, max_sku_length);
			goodSku[strlen(src.goodSku)] = '\0';
			strncpy(goodDesc, src.goodDesc, max_unit_length);
			goodDesc[strlen(src.goodDesc)] = '\0';
			qtyOnHand = src.qtyOnHand;
			qty_needed = src.qty_needed;
			taxable = src.taxable;
			iPrice = src.iPrice;
			error.message(src.error.message());
			delete[] goodName;
			if (src.goodName != nullptr) {
				name(src.goodName);
			}

			else
			{
				goodName = nullptr;
			}

		}
		return *this;
	}
	// Copy Constructor
	Good::Good(const Good& src) {
		goodName = nullptr;
		*this = src;
	}
	// Inserts current object's data into an fstream object
	std::fstream& Good::store(std::fstream& file, bool newLine) const {
		if (goodName[0] == 'b') { file << 'N'; }
		if (goodName[0] == 'w') { file << 'P'; }
		file  << ',' << goodSku << ',' << goodName << ',' << goodDesc << ',' << taxable
			<< ',' << iPrice << ',' << qtyOnHand << ',' << qty_needed;
		if (newLine) {
			file << endl;
		}
		return file;
	}
	// Extracts fields for a record into fstream object
	std::fstream& Good::load(std::fstream& file) {
		// Create a temporary object
		char tGoodSku[max_sku_length];
		char tGoodName[max_name_length];
		char tGoodDesc[max_unit_length];
		double tPrice;
		int tQtyHand;
		int tQtyNeeded;
		char tTax;
		bool tTaxable;
		// Extract field data into temporary object
		if (file.is_open()) {
			
			file.getline(tGoodSku, max_sku_length, ',');
			tGoodSku[strlen(tGoodSku)] = '\0';

			file.getline(tGoodName, max_name_length, ',');
			tGoodName[strlen(tGoodName)] = '\0';

			file.getline(tGoodDesc, max_unit_length, ',');
			tGoodDesc[strlen(tGoodDesc)] = '\0';
			file >> tTax;

			if (tTax == '1') {
				tTaxable = true;
			}
			else {
				tTaxable = false;
			}
			file.ignore();
			file >> tPrice;
			file.ignore();
			file >> tQtyHand;
			file.ignore();
			file >> tQtyNeeded;
			char saveType = goodType;
			*this = Good(tGoodSku,tGoodName,tGoodDesc,tQtyHand,tTaxable,tPrice,tQtyNeeded); // Assign to current object
			goodType = saveType;
		}
		
		return file;
	}
	// Inserts current object's data into ostream in desired format
	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (isClear() && !isEmpty()) {
			if (linear) {
				os << setw(max_sku_length) << left << setfill(' ') << sku() << '|';
				os << setw(20) << left << name() << '|';
				os << setw(7) << right << fixed << setprecision(2) << itemCost() << '|';
				os << setw(4) << right << quantity() << '|';
				os << setw(10) << left << unit() << '|';
				os << setw(4) << right << qtyNeeded() << '|';
			}
			else {
				os << " Sku: " << goodSku << endl;
				os << " Name (no spaces): " << goodName << endl;
				os << " Price: " << iPrice << endl;
				if (taxable) {
					os << " Price after tax: " << itemCost() << endl;
				}
				else {
					os << " Price after tax:  N/A" << endl;
				}
				os << " Quantity on Hand: " << qtyOnHand << ' ' << unit() << endl;
				os << " Quantity needed: " << qty_needed;
			}
		}
		if (!isClear()) {
			os << error.message();
		}
		return os;
	}
	// Extracts data fields for the current object based on user input
	std::istream& Good::read(std::istream& is) {
		// Store data in temporary variables
		char t_goodSku[max_sku_length + 1];
		char *t_goodName = new char[max_name_length + 1];
		char t_goodDesc[max_unit_length + 1];
		int t_qtyOnHand;
		int t_qty_needed;
		double t_price;
		char taxed;
		bool t_taxable;
		//Error error;

		// Prompt user for data, store into istream object
		cout << " Sku: ";
		is >> t_goodSku;
		cout << " Name (no spaces): ";
		is >> t_goodName;
		cout << " Unit: ";
		is >> t_goodDesc;
		cout << " Taxed? (y/n): ";
		is >> taxed;
		if (taxed == 'Y' || taxed == 'y') {
			t_taxable = true;
		}
		else if (taxed == 'N' || taxed == 'n') {
			t_taxable = false;
		}
		// If input is invalid, set istream failbit and display error message
		else {
			is.setstate(std::ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}
		if (!is.fail()) {
			cout << " Price: ";
			is >> t_price;
			if (is.fail()) {
				error.message("Invalid Price Entry");
				delete[] t_goodName;
				return is;
			}
		}
		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> t_qtyOnHand;
			if (is.fail()) {
				error.message("Invalid Quantity Entry");
				delete[] t_goodName;
				return is;
			}
		}
		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> t_qty_needed;
			if (is.fail()) {
				error.message("Invalid Quantity Needed Entry");
				delete[] t_goodName;
				return is;
			}
		}
		// If all input is valid, create temporary object with given values, copy assign to current object
		if (!is.fail()) {
			Good temp = Good(t_goodSku, t_goodName, t_goodDesc, t_qtyOnHand, t_taxable, t_price, t_qty_needed);
			*this = temp;
			
		}
		delete[] t_goodName;
		t_goodName = nullptr;
		is.ignore(2000, '\n');
		return is;
	}

	bool Good::operator==(const char* string) const {
		return strcmp(string, goodSku) == 0;
	}

	double Good::total_cost() const {
		return itemCost() * qtyOnHand;
	}

	void Good::quantity(int units) {
		if (units > 0) {
			qtyOnHand = units;
		}
	}

	bool Good::isEmpty() const {
		return goodSku[0] == '\0';
	}

	int Good::qtyNeeded() const {
		return qty_needed;
	}

	int Good::quantity() const {
		return qtyOnHand;
	}

	bool Good::operator>(const char* string) const {
		return (strcmp(goodSku, string) > 0) ? true : false;
	}

	bool Good::operator>(const iGood& src) const {
		return (strcmp(name(), src.name()) > 0) ? true : false;
	}

	int Good::operator+=(int add) {
		if (add > 0) {
			qtyOnHand += add;
		}
		return qtyOnHand;
	}
	// Inserts a Good record into the ostream
	std::ostream& operator<<(std::ostream& os, const iGood& src) {
		return src.write(os, true);
	}
	// Extracts a Good record from the istream
	std::istream& operator>>(std::istream& is, iGood& src) {
		src.read(is);
		return is;
	}

	double operator+=(double& total, const iGood& src) {
		total += src.total_cost();
		return total;
	}
}
