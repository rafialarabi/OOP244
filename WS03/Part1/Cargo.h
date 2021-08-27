//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           10/6/2020


#include <iostream>
#include <cstring>

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds {

	const int MAX_DESC = 20;

		struct Cargo {
			char cargo_desc[MAX_DESC];
			double weight;
		};
}

#endif // !SDDS_CARGO_H