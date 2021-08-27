

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 4
// Date:           29/07/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */




#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "ReadWritable.h"
using namespace std;


namespace sdds {

	ReadWritable::ReadWritable() {

		choice = false;
	}

	ReadWritable::~ReadWritable() {

	}

	bool ReadWritable::isCsv() const {

		return choice;
	}

	void ReadWritable::setCsv(bool value) {

		choice = value;
	}

	std::istream& operator>>(std::istream& in, ReadWritable& park) {
		return park.read(in);
	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& park) {

		return park.write(os);
	}

}
