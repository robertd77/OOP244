// Robert Dominato
// rdominato@myseneca.ca
// 119283185
// OOP244 Fall 2018
// Workshop 7 - at home
// Hero.h


#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {

	const int MAX_ROUNDS = 100;
	const int NAME_LEN = 40;
	class Hero {
		char Name[NAME_LEN + 1];
		int Health;
		int attStrength;
	public:
		Hero();
		Hero(const char* pName, int pHealth, int pAttack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
	}
#endif

