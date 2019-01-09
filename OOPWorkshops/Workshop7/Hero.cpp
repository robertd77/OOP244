// Robert Dominato
// rdominato@myseneca.ca
// 119283185
// OOP244 Fall 2018
// Workshop 7 - at home
// Hero.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict {

	Hero::Hero() {
		Name[0] = '\0';
		Health = -1;
		attStrength = -1;
	}

	Hero::Hero(const char* pName, int pHealth, int pAttack) {
		bool nmcheck = pName != nullptr && pName[0] != '\0';
		bool hcheck = pHealth > 0;
		bool acheck = pAttack > 0;
		if (nmcheck && hcheck && acheck) {
			strcpy(Name, pName);
			Health = pHealth;
			attStrength = pAttack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			Health -= attack;
			if (Health < 0) {
				Health = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		return (Health > 0);
	}

	int Hero::attackStrength() const {
		return attStrength == -1 ? 0 : attStrength;
	}


	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.Health == -1) {
			os << "No hero";
		}
		else {
			os << hero.Name;
		}
		return os;
	}


	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero one = first;
		Hero two = second;
		Hero winner;
		int rounds = 0;
		bool firstWon = true;

		for (int i = 0; i < MAX_ROUNDS && one.isAlive() && two.isAlive(); i++) {
			one -= two.attackStrength();
			two -= one.attackStrength();
			rounds = i + 1;
		}

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

		cout << "Ancient Battle! " << one << " vs " << two << " : ";
		cout << "Winner is " << winner << " in " << rounds << " rounds." << endl;

		return (firstWon) ? first : second;
	}
}
