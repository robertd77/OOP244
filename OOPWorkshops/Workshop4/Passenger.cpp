// Workshop 4 - Constructors
// Passenger.cpp
// Robert Dominato
// 119823185
//OOP244 Fall 2018
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
namespace sict {


	Passenger::Passenger() {
		passName[0] = '\0';
		destination[0] = '\0';
		DepDay = 0;
		DepMonth = 0;
		DepYear = 0;
	}

	Passenger::Passenger(const char* Name, const  char* Dest) {
		if (Name != nullptr && Dest != nullptr && strcmp(Name, "") != 0 && strcmp(Dest, "") != 0) {
			strncpy(passName, Name, SIZE);
			passName[SIZE - 1] = '\0';
			strncpy(destination, Dest, SIZE);
			destination[SIZE - 1] = '\0';
			this->DepDay = 1;
			this->DepMonth = 10;
			this->DepYear = 2018;
		}
		else {
			*this = Passenger();
		}
	}

Passenger::Passenger(const char* Name, const char* Dest, int year, int month, int day) {
	bool yearcheck = year > 2017 && year < 2021;
	bool monthcheck = month > 0 && month < 13;
	bool daycheck = day > 0 && day < 32;

	*this = Passenger(Name, Dest); // checks if name and destination are valid

	if (!isEmpty() && yearcheck && monthcheck && daycheck) {
		    this->DepYear = year;
			this->DepMonth = month;
			this->DepDay = day;
		}
	else {
		*this = Passenger();
	   }
	}

	bool Passenger::isEmpty() const {
		if (passName[0] != '\0' || destination[0] != '\0') {
			return false;
		}
		else {
			return true;
		}
	}

	void Passenger::display() const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << this->passName << " - " << this->destination << " on ";
			cout << this->DepYear << "/" << this->DepMonth << "/";
			cout.width(2);
			cout.fill('0');
			cout << this->DepDay << endl;
		}
	}

	const char* Passenger::name() const {
		return this->passName;
	}

	bool Passenger::canTravelWith(const Passenger& currentPass) const {
		bool dest = strcmp(currentPass.destination,this->destination) == 0;
		bool month = currentPass.DepMonth == this->DepMonth;
		bool day = currentPass.DepDay == this->DepDay;
		bool year = currentPass.DepYear == this->DepYear;

		bool samecheck = dest && month && day && year;

		return samecheck;
	}
}
