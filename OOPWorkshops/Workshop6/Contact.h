/*Robert Dominato
rdominato@myseneca.ca
119823185
OOP244 fall 2018
Workshop 6 in lab
Contact.h*/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	const int MAX_CHAR = 20;
	class Contact {
		char name[MAX_CHAR + 1];
		long long* phoneNums;
		int numPhoneNums;
		bool getValidPhone(const long long);
	public:
		Contact();
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
#endif 



