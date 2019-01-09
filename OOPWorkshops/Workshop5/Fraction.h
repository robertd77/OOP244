// Workshop 5: operator overloading 
// File: Fraction.H
// Student # 119823185
// Date: 2018/10/06 
// Author: Robert Dominato
// OOP244 Fall 2018
// ID: rdominato@myseneca.ca

#ifndef _SICT_HEAD_H_
#define _SICT_HEAD_H_

namespace sict {
	class Fraction {
		int num;
		int denom;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		Fraction();
		Fraction(int num, int denom);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
	};
}

#endif _SICT_HEAD_H_

