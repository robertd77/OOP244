// Robert Dominato
// rdominato@myseneca.ca
// 119823185
// OOP244 Fall 2018
// Milestone 5
// Error.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Error.h"

using namespace std;
using namespace aid;

Error::Error(const char* errorMess) {

	if (errorMess != nullptr) {
		if (strcmp(errorMess, "") != 0) {
			errorMessage = new char[strlen(errorMess) + 1];
			strcpy(errorMessage, errorMess);
		}
		else {
			errorMessage = nullptr;
		}
	}
	else {
		errorMessage = nullptr;
	}
}

Error::~Error() {
	delete[] errorMessage;
	errorMessage = nullptr;
}

void Error::clear() {
	delete[] errorMessage;
	errorMessage = nullptr;
}

bool Error::isClear() const {
	return (errorMessage == nullptr);
}

void Error::message(const char* str) {
	delete[] errorMessage;
	errorMessage = nullptr;
	if (str != nullptr) {
		if (strcmp(str, "") != 0) {
			errorMessage = new char[strlen(str) + 1];
			strcpy(errorMessage, str);
		}
		else {
			errorMessage = nullptr;
		}
	}
	else {
		errorMessage = nullptr;
	}
}

const char* Error::message() const {
	return errorMessage;
}


std::ostream & aid::operator<<(std::ostream & os, const Error & em) {

	if (!em.isClear()) {
		os << em.message();
	}
	return os;
}
