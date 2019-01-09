// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// 2018/10/28
// OOP244 Fall 2018
// Assignment Milestone 5
// Date.cpp

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

namespace aid {
	//calculates the amount of days in a given month and year
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	// sets Safe empty state
	Date::Date() {
		d_Year = 0000;
		d_Month = 00;
		d_Day = 00;
		comparator = 0;
		errorState = NO_ERROR;
	}

	bool Date::getValidDate(int year, int month, int day) {
		int flag = 0;
		int monthLen = mdays(month, year);
		// these bools check if each part of the date is valid
		bool yrCheck = (year >= min_year && year <= max_year);
		bool mnCheck = (month > 0 && month <= 12);
		bool dayCheck = (day > 0 && day <= monthLen);
		// if date is invalid, stop validation and set error state
		if (!yrCheck) { errorState = 4; flag = 1; }
		if (!mnCheck && flag != 1) { errorState = 3; flag = 1; }
		if (!dayCheck && flag != 1) { errorState = 2; flag = 1; }
		return (flag != 1);
	}

	Date::Date(int year, int month, int day) {

		// if data is valid, copy into objects's instance variables
		if (getValidDate(year, month, day)) {
			d_Year = year;
			d_Month = month;
			d_Day = day;
			errorState = NO_ERROR;
			comparator = year * 372 + month * 31 + day;
		}
		else {// invalid data, set empty state
			*this = Date();
		}

	}
	// operator overload: checks if 2 dates are equal
	bool Date::operator==(const Date& rhs) const {
		bool day = d_Day == rhs.d_Day;
		bool month = d_Month == rhs.d_Month;
		bool year = d_Year == rhs.d_Year;
		return (day && month && year);
	}

	bool Date::operator!=(const Date& rhs) const {
		return !(*this == rhs);
	}
	// operator overload: checks if one date is older than another
	bool Date::operator<(const Date& rhs) const {
		int flag = 0;
		bool lessThan = false;
		if (d_Year < rhs.d_Year) { lessThan = true; flag = 1; }
		if (d_Month < rhs.d_Month && flag != 1) { lessThan = true; flag = 1; }
		if (d_Day < rhs.d_Day && flag != 1) { lessThan = true; flag = 1; }
		return lessThan;
	}

	bool Date::operator>(const Date& rhs) const {
		return (*this == rhs || *this < rhs) ? false : true;
	}

	bool Date::operator>=(const Date& rhs) const {
		return (*this > rhs || *this == rhs);
	}

	bool Date::operator<=(const Date& rhs) const {
		return (*this < rhs || *this == rhs);
	}

	void Date::errCode(int errorCode) {
		errorState = errorCode;
	}

	int Date::errCode() const {
		return errorState;
	}

	bool Date::bad() const {
		return (errorState != NO_ERROR);
	}
	// reads a date from input stream, sets appropriate error state if invalid
	std::istream& Date::read(std::istream& istr) {
		char slash;
		int yr, mn, dy;

		//istr.clear();
		istr >> yr >> slash >> mn >> slash >> dy;

		if (istr.fail()) {
			*this = Date();
			errCode(CIN_FAILED);
		}
		else {
			// if date is valid, set and validate comparator
			if (getValidDate(yr, mn, dy)) {
				comparator = yr * 372 + mn * 31 + dy;
				if (comparator != 0 && comparator < MIN_DATE) {
					*this = Date();
					errCode(PAST_ERROR);
				}
				else
				{// set input values of object as they are now validated
					*this = Date(yr, mn, dy);
				}
			}
		}
		return istr;

	}
	// writes date to console in proper format
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << d_Year << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << d_Month << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << d_Day;

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& i) {
		return i.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, Date& o) {
		return o.write(ostr);
	}
}
