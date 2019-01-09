// Robert Dominato
// rdominato@myseneca.ca
//119823185
// 2018/10/28
// OOP244 Fall 2018
// Assignment Milestone 5
// Date.h

#ifndef AID_DATE_H
#define AID_DATE_H

namespace aid {
	const int min_year = 2018;
	const int max_year = 2038;
	const int MIN_DATE = 751098;
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int DAY_ERROR = 2;
	const int MON_ERROR = 3;
	const int YEAR_ERROR = 4;
	const int PAST_ERROR = 5;

	class Date {
		int d_Year;
		int d_Month;
		int d_Day;
		int comparator;
		int errorState;
		int mdays(int month, int year) const;
		void errCode(int errorCode);
	public:
		Date();
		Date(int year, int month, int day);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		bool getValidDate(int year, int month, int day);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, Date&);
	std::ostream& operator<<(std::ostream& ostr, Date&);
}
#endif

