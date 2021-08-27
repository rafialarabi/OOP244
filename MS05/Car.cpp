
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
#include "Vehicle.h"
#include "Car.h"
using namespace std;

namespace sdds {

	Car::Car() : Vehicle(), Carwash(false) {}


	Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel), Carwash(false) {}


	istream& Car::read(istream& is) {
		bool choice, getin;
		char decision, move;

		if (isCsv()) {

			Vehicle::read(is);
			is >> Carwash;
			is.ignore(2000, '\n');
		}
		else {

			cout << "\nCar information entry" << endl;
			Vehicle::read(is);

			cout << "Carwash while parked? (Y)es/(N)o: ";


			do {

				decision = cin.get();
				move = cin.get();
				cin.clear();

				choice = (decision == 'Y') || (decision == 'y') || (decision == 'N') || (decision == 'n');
				getin = (move == '\n');

				if (!(choice && getin)) {

					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin.ignore(200, '\n');
				}

			} while (!(choice && getin));


			if (decision == 'Y' || decision == 'y') {

				Carwash = 1;
			}
			else {

				Carwash = 0;
			}

		}
		return is;
	}

	ostream& Car::write(ostream& os) const {
       
		if (Vehicle::isEmpty()) {

			os << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {

				os << "C,";
			}
			else {

				os << "Vehicle type: Car" << endl;
			}

			Vehicle::write(os);

			if (isCsv()) {

				os << Carwash << endl;
			}
			else {
				if (Carwash == 1) {

					os << "With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}
		return os;
	}
}
