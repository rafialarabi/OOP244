
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 5
// Date:           03/08/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Motorcycle.h"
using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() {
		Sidecar = false;
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) :Vehicle(licensePlate, makeModel) {

		if (licensePlate != nullptr && *licensePlate != '\0' && strlen(licensePlate) <= 8 && makeModel != nullptr && strlen(makeModel) > 2) {

			Sidecar = false;
		}
		else {
			*this = Motorcycle();
		}
	}

	istream& Motorcycle::read(istream& is) {

		bool choice, getin;
		char decision, move;

		if (isCsv()) {

			Vehicle::read(is);
			is >> Sidecar;
			is.ignore(2000, '\n');
		}
		else {

			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(is);

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			
			do {

				decision = cin.get();
				move = cin.get();
				cin.clear();

				choice = (decision == 'Y') || (decision == 'y') || (decision == 'N') || (decision == 'n');
				getin = (move == '\n');

				if (!(choice && getin)) {

					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin.ignore(100, '\n');
				}

			} while (!(choice && getin));


			if (decision == 'Y' || decision == 'y') {
				Sidecar = 1;
			}
			else{

				Sidecar = 0;
			}
		}

		return is;
	}


	ostream& Motorcycle::write(ostream& os) const {

		if (Vehicle::isEmpty()) {

			os << "Invalid Motorcycle Object" << endl;
		}
		else{

			if (isCsv()) {

				os << "M,";
			}
			else {

				os << "Vehicle type: Motorcycle" << endl;
			}

			Vehicle::write(os);

			if (isCsv()) {
				os << Sidecar << endl;
			}
			else {
				if (Sidecar == 1) {

					os << "With Sidecar" << endl;
				}
			}
		}

		return os;
	}
}
