


// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/08/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */



#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_

#include <iostream>
#include "Vehicle.h"

namespace sdds {

	class Motorcycle : public Vehicle {

	private:

		bool Sidecar;

	public:
		Motorcycle();
		Motorcycle(const char* licensePlate, const char* makeModel);
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	};
}

#endif //SDDS_MOTORCYCLE_H_

