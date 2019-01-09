// Workshop 5: operator overloading 
// File: Fraction.cpp
// Student # 119823185
// Date: 2018/10/06 
// Author: Robert Dominato
// OOP244 Fall 2018
// ID: rdominato@myseneca.ca

#include <iostream>
#include "Fraction.h"

using namespace std;
namespace sict {
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator 
		int mx = max();  // max of numerator and denominator 
		int g_c_d = 1;
		bool found = false;


		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found 
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;

	}

	int Fraction::max() const {
		return  (num >= denom) ? num : denom;
	}

	int Fraction::min() const {
		return (num <= denom) ? num : denom;
	}

	void Fraction::reduce() { // Divides numerator and denominator by Greatest common divisor
		int GCD = gcd();
		num /= GCD;
		denom /= GCD;
	}

	Fraction::Fraction() {// sets Fraction Object to empty state
		num = -1;
		denom = -1;
	}

	Fraction::Fraction(int N, int D) {
		if (N >= 0 && D >= 1) {// Determines if fraction is valid and reduces it if it is
			num = N;
			denom = D;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}

	bool Fraction::isEmpty() const {
		return (num == -1) ? true : false;
	}

	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (denom == 1) {
			cout << num;
		}
		else {
			cout << num << "/" << denom;
		}
	}

	Fraction Fraction::operator+(const Fraction& rhs) const { // Adds the two fractions together
		int Numer = (rhs.num * denom) + (rhs.denom * num);
		int Den = rhs.denom * denom;
		return Fraction(Numer, Den);

	}

	Fraction Fraction::operator*(const Fraction& rhs) const { // Multiplies two fractions
		int Numer = rhs.num * num;
		int Den = rhs.denom * denom;
		return Fraction(Numer, Den);
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		bool Equal = false;
		if (rhs.denom == denom && rhs.num == num) {
			Equal = true;
		}
		if (isEmpty() || rhs.isEmpty()) {
			Equal = false;
		}
		return Equal;
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		bool nonEqual = true;
		if (rhs.denom == denom && rhs.num == num) {
			nonEqual = false;
		}
		if (isEmpty() || rhs.isEmpty()) {
			nonEqual = false;
			}
		return nonEqual;
	}

	Fraction Fraction::operator+=(const Fraction& rhs) {
		num = (rhs.num * denom) + (rhs.denom * num);
		denom *= rhs.denom;
		return *this;
	}
}




