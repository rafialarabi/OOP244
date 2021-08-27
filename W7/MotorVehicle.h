
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 7(part1)
// Date:           15/07/2020

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

namespace sdds {
	
	class MotorVehicle {
	private:
		char m_licensePlate[32];
		char m_presentAddress[64];
		int m_year;

	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}

#endif //SDDS_MOTORVEHICLE_H

