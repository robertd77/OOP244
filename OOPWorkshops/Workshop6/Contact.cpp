/*Robert Dominato
rdominato@myseneca.ca
OOP244 fall 2018
Workshop 6 at home
Contact.cpp
119823185*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Contact.h"

using namespace std;
using namespace sict;

bool Contact::getValidPhone(const long long phone) {
	bool valid = true;
	string phoneStr = to_string(phone);
	// Checks if phone number is the right length
	if (phoneStr.length() < 13 && phoneStr.length() > 10) {
		// checks if number is formatted correctly according to country code
		if (phoneStr.length() == 11) {
			if (phoneStr[0] == 0 || phoneStr[1] == 0 || phoneStr[4] == 0)
			{
				valid = false;
			}
		}
		else {
			if (phoneStr[0] == 0 || phoneStr[1] == 0 || phoneStr[2] == 0 || phoneStr[5] == 0)
			{
				valid = false;
			}
		}
	}
	else {
		valid = false;
	}
	return valid;
}
// Sets empty state
Contact::Contact() {
	name[0] = '\0';
	phoneNums = nullptr;
	numPhoneNums = 0;
}
//Copies the name and phone numbers into the object if they are valid
Contact::Contact(const char *nm, const long long* phones, int no) {
	if (nm != nullptr && nm[0] != '\0') {
		strncpy(name, nm, MAX_CHAR);
	}
	else {
		name[0] = '\0';
	}
	if (phones != nullptr && no > 0) {
		phoneNums = new long long[no];

		for (int i = 0; i < no; i++) {
			if (getValidPhone(phones[i])) {
				numPhoneNums++;
					phoneNums[numPhoneNums - 1] = phones[i];
			}
		}
	}
	else {
		numPhoneNums = 0;
		phoneNums = nullptr;
	}
}
// delete any dynamically allocated memory
Contact::~Contact() {
	
	delete[] phoneNums;
	phoneNums = nullptr;
}
// Checks if object is in an empty state
bool Contact::isEmpty() const {
	return (name[0] == '\0' ? true : false);
}
// Displays a contact and their phone numbers in the appropriate format
void Contact::display() const {
	if (isEmpty()) {
		cout << "Empty contact!" << endl;
	}
	else {
		cout << name << endl;
		for (int i = 0; i < numPhoneNums; i++) {
			string phoneStr = to_string(phoneNums[i]);
			cout << "(+" << phoneStr[0];
			if (phoneStr.length() == 12) {
				cout << phoneStr[1] << ") " << phoneStr[2] << phoneStr[3] << phoneStr[4];
				cout << " " << phoneStr[5] << phoneStr[6] << phoneStr[7] << "-";
				cout << phoneStr[8]<< phoneStr[9] << phoneStr[10] << phoneStr[11];
				}
			else {
				cout << ") " << phoneStr[1] << phoneStr[2] << phoneStr[3];
				cout << " " << phoneStr[4] << phoneStr[5] << phoneStr[6] << "-";
				cout << phoneStr[7] << phoneStr[8] << phoneStr[9] << phoneStr[10];
			}
			cout << endl;
		}
	}
}
// Copy Constructor: utilizes assignment operator
Contact::Contact(const Contact& src) {
	phoneNums = nullptr;
	*this = src;
}
// Assignment operator
Contact& Contact::operator=(const Contact& src) {
	if (this != &src) {
		numPhoneNums = src.numPhoneNums;
		strncpy(name, src.name, MAX_CHAR);
		delete[] phoneNums;

		if (src.phoneNums != nullptr) {
			phoneNums = new long long[numPhoneNums];
			for (int i = 0; i < numPhoneNums; i++) {
				
				phoneNums[i] = src.phoneNums[i];
			}
		}
		else {
			phoneNums = nullptr;
		}
	}
	return *this;
}
// Operator overload
Contact& Contact::operator+=(long long newNum) {
	// check if phone number is valid and object is not empty
	if (getValidPhone(newNum) && !isEmpty()) {
		// increment phone number array by 1
		numPhoneNums++;
		long long* temp = nullptr;
		temp = new long long[numPhoneNums];
		// copy old array into new temporary array
		for (int i = 0; i < numPhoneNums - 1; ++i) {
			temp[i] = phoneNums[i];
		}
		// add new phone number to array
		temp[numPhoneNums - 1] = newNum;
		// delete old array and copy temp array into PhoneNums
		delete[] phoneNums;
		phoneNums = nullptr;
		phoneNums = temp;
		}
	return *this;
}
