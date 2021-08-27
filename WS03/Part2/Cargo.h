//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           14/6/2020


#include <iostream>
#include <cstring>

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds {

	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	class Cargo {
		char desc[MAX_DESC + 1];
		double weight;

	public:
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);
	};
}

#endif 

