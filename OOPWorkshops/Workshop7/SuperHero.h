// Robert Dominato
// rdominato@myseneca.ca
// 119283185
// OOP244 Fall 2018
// Workshop 7 - at home
// SuperHero.h

#ifndef SICT_SUPERHERO_H 
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
		int attBonus;
		int defStrength;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif


