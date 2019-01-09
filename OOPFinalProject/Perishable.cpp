// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Milestone 5
// Perishable.cpp

#include <iostream>
#include <fstream>
#include "Perishable.h"

namespace aid {
	Perishable::Perishable() : Good('P') {
		expDate = Date();

	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Good::store(file, false);
		file << ',';
		expDate.write(file);
		if (newLine) {
			file << std::endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream & file)
	{
		Good::load(file);
		file.ignore();
		expDate.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream & os, bool linear) const
	{
		Good::write(os, linear);

		if (isClear() && !isEmpty()) {
			if (linear) {
				expDate.write(os);
			}
			else {
				os << "\n Expiry date: ";
				expDate.write(os);
			}
		}
			return os;
		}

	std::istream& Perishable::read(std::istream & is)
	{
		Date temp;
		is.clear();
		Good::read(is);
		std::cout << " Expiry date (YYYY/MM/DD): ";
		temp.read(is);
		if (temp.errCode() == CIN_FAILED) {
			Good::message("Invalid Date Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		if (temp.errCode() == PAST_ERROR) {
			Good::message("Invalid Expiry in Date Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		if (temp.errCode() == YEAR_ERROR) {
			Good::message("Invalid Year in Date Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		if (temp.errCode() == MON_ERROR) {
			Good::message("Invalid Month in Date Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		if (temp.errCode() == DAY_ERROR) {
			Good::message("Invalid Day in Date Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		if (temp.errCode() == NO_ERROR) {
			expDate = temp;
		}
		return is;
	}

	const Date & Perishable::expiry() const
	{
		return expDate;
	}


}
