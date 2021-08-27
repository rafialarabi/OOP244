//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           10/6/2020


#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include <iostream>
#include <cstring>
#include "Cargo.h"

namespace sdds {

	const int MAX_NAME = 30;

	class Train
	{
		char name[MAX_NAME];
		int id;
		Cargo* cargo;
		
	public:
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;
	};
}
#endif // !SDDS_TRAI_H

