
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 7(part1)
// Date:           15/07/2020

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H


#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
	
	class Truck : public MotorVehicle {
	
	private:
		double m_capacity;
		double m_cargo;

	public:
		Truck(const char* plate, int year, double capacity, const char* address);

		bool addCargo(double cargo);
		bool unloadCargo();


		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;
	};

	std::istream& operator>>(std::istream& in, Truck& truck);
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
}

#endif //SDDS_TRUCK_H

