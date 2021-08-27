
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 7(part1)
// Date:           15/07/2020

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<iomanip>
#include <cstring>
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds {

	Truck::Truck(const char* plate, int year, double capacity, const char* address): MotorVehicle(plate, year) {

		m_capacity = capacity;
		m_cargo = 0;
		MotorVehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo) {

		if (m_cargo >= m_capacity) {

			return false;
		}
		else {
			m_cargo += cargo;

			if (m_cargo > m_capacity) {
				
				m_cargo = m_capacity;
			}

			return true;
		}
    }

	bool Truck::unloadCargo() {
		
		bool unload = m_cargo;
		m_cargo = 0;
		return unload;
	}

	istream& Truck::read(istream& in) {
		
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}

	ostream& Truck::write(ostream& os) const {

		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;

		return os;
	}

	istream& operator>>(istream& in, Truck& truck) {

		return truck.read(in);
	}

	ostream& operator<<(ostream& os, const Truck& truck) {

		return truck.write(os);
	}

}


