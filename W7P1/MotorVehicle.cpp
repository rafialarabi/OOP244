
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 7(part1)
// Date:           15/07/2020


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "MotorVehicle.h"
using namespace std;

namespace sdds {

	MotorVehicle::MotorVehicle(const char* plate, int year) {
		strcpy(m_presentAddress, "Factory");
		strcpy(m_licensePlate, plate);
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {

		cout << "|" << right << setw(10) << m_licensePlate << "| |" << right << setw(20) << m_presentAddress << " --->--- " << left << setw(20) << address
			<< "|\n";
		
		strcpy(m_presentAddress, address);
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "| " << m_year;
		os << " | " << m_licensePlate;
		os << " | " << m_presentAddress;

		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_year;

		cout << "License plate: ";
		in >> m_licensePlate;

		cout << "Current location: ";
		in >> m_presentAddress;

		return in;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& vehicle) {
		
		return vehicle.write(os);
	}

	istream& operator>>(istream& in, MotorVehicle& vehicle) {
		
		return vehicle.read(in);
	}

}
