// Workshop 4 - Constructors
// Passenger.h
// Robert Dominato
// 119823185
//OOP244 Fall 2018
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_

namespace sict {
	const int SIZE = 19;
	class  Passenger {
		char passName[SIZE + 1];
		char destination[SIZE + 1];
		int DepYear = 0;
		int  DepMonth = 0;
		int DepDay = 0;
	public:
		Passenger();
		Passenger(const char* Name, const char* Dest);
		Passenger(const char* Name, const char* Dest, int year, int month, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif


