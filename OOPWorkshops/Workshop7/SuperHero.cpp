// Robert Dominato
// rdominato@myseneca.ca
// 119283185
// OOP244 Fall 2018
// Workshop 7 - at home
// SuperHero.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;

namespace sict {
	// Set to empty state
	SuperHero::SuperHero() : Hero() {
		attBonus = -1;
		defStrength = -1;
	}
	// Construct Superhero object with help of base class constructor
	SuperHero::SuperHero(const char* pName, int pHealth, int pAtck, int pBonus, int pDef) : Hero(pName,pHealth,pAtck) {
		
		    attBonus = pBonus;
			defStrength = pDef;
		}
	// return Superhero's attack strength including bonus, 0 if empty state
	int SuperHero::attackStrength() const {
		int currentStren = 0;
		if (Hero::attackStrength() != -1) {
			currentStren = Hero::attackStrength() + attBonus;
		}
		return currentStren;
	}
	// Return Superhero's defense strength, 0 if empty state
	int SuperHero::defend() const {
		return defStrength == -1 ? 0 : defStrength;
	}
	// Operator overload, conduct fight between 2 superheroes, return winner
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero one = first; // Make local copies of superheroes
		SuperHero two = second;
		SuperHero winner;
		int rounds = 0;
		bool firstWon = true;
		// Fight for 100 rounds or until a Superhero dies
		for (int i = 0; i < MAX_ROUNDS && one.isAlive() && two.isAlive(); i++) {
			// Damage from an attack is the attacker's attack strength minus defender's defence strength
			one -= two.attackStrength() - one.defend();
			two -= one.attackStrength() - two.defend();
			rounds = i + 1;
		}
		// Determine who the winner is: whoever is still alive
		if (one.isAlive()) {
			winner = one;
		}
		else if (two.isAlive()) {
			winner = two;
			firstWon = false;
		}
		else {
			winner = one;
		}
		// Output winner and number of rounds in the fight to the console
		cout << "Super Fight! " << one << " vs " << two << " : ";
		cout << "Winner is " << winner << " in " << rounds << " rounds." << endl;

		return (firstWon) ? first : second;
	}

}
