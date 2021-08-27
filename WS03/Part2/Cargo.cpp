//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           14/6/2020


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"
#include"Cargo.h"

using namespace std;

namespace sdds {

	void Cargo::initialize(const char* desc, double weight) {
		if (strlen(desc) <= MAX_DESC + 1) {
			setDesc(desc);
		}
		else {
			setDesc("\0");
		}
		if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT) {
			setWeight(weight);
		}
		else {
			setWeight(MIN_WEIGHT);
		}
	}
	const char* Cargo::getDesc() const {
		return desc;

	}
	double Cargo::getWeight() const {
		return weight;

	}
	void Cargo::setDesc(const char* description) {

		strcpy(desc, description);
	}
	void Cargo::setWeight(double weight) {

		this->weight = weight;

	}
}




