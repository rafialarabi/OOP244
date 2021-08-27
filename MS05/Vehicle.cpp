
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 5
// Date:           03/08/2020

/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Vehicle.h"
using namespace std;

namespace sdds {

	void Vehicle::setEmpty() {

		licensePlate[0] = '\0';
		delete[] makeModel;
		makeModel = nullptr;
		parkingSpotNum = 0;
	}

	Vehicle::Vehicle() {

		licensePlate[0] = '\0';
		makeModel = nullptr;
		parkingSpotNum = 0;
	}


	Vehicle::Vehicle(const char* num_plate, const char* mdl_value) {

		licensePlate[0] = '\0';
		makeModel = nullptr;
		parkingSpotNum = 0;

		if (num_plate != nullptr && *num_plate != '\0' && strlen(num_plate) <= 8 && mdl_value != nullptr && strlen(mdl_value) > 2) {

			this->parkingSpotNum = 0;
			strncpy(licensePlate, num_plate, 9);
			licensePlate[8] = '\0';
			makeModel = new char[strlen(mdl_value) + 1];
			strcpy(makeModel, mdl_value);
		}
	}


	Vehicle::~Vehicle() {
		delete[] makeModel;
	}

	bool Vehicle::isEmpty() const {

		bool value;

		if (licensePlate[0] == '\0' || makeModel == nullptr || parkingSpotNum < 0) {

			value = true;
		}
		else {

			value = false;
		}

		return value;
	}

	char* Vehicle::getLicensePlate() const {

		char* i = new char[strlen(licensePlate) + 1];
		strcpy(i, licensePlate);
		return i;
	}

	char* Vehicle::getMakeModel() const {

		return makeModel;
	}

	void Vehicle::setMakeModel(const char* mkMdl) {

		delete[] makeModel;

		makeModel = nullptr;
		if (mkMdl != nullptr) {

			int size = strlen(mkMdl);
			makeModel = new char[size + 1];
			strcpy(makeModel, mkMdl);
		}

	}

	int Vehicle::getParkingSpot() const {

		return parkingSpotNum;
	}

	void Vehicle::setParkingSpot(int spot_num) {
		parkingSpotNum = spot_num;
	}

	bool Vehicle::operator==(const char* plt_value) const {

		bool value = true;

		int f_length = strlen(licensePlate);
		int s_length = strlen(plt_value);

		if (*plt_value != '\0' && (f_length = s_length)) {

			int length = strlen(plt_value);

			for (int i = 0; i < length; i++) {

				if (toupper(licensePlate[i]) != toupper(plt_value[i])) {

					value = false;
				}
			}
		}

		return value;
	}

	bool Vehicle::operator==(const Vehicle& car) const {

		bool value;

		if (car.licensePlate == nullptr || car.licensePlate[0] == '\0') {
			value = true;
		}
		else if (strcmp(licensePlate, car.licensePlate) == 0) {
			value = false;
		}
		else {
			value = true;
		}

		return value;
	}

	istream& Vehicle::read(istream& is) {

		if (isCsv() && !is.fail()) {

			is >> parkingSpotNum;
			is.ignore();

			is.getline(licensePlate, 9, ',');
			int length = strlen(licensePlate);
			for (int i = 0; i < length; i++) {

				if (licensePlate[i] >= 97 && licensePlate[i] <= 122)
					licensePlate[i] -= 32;
			}

			char mdl[61];
			is.getline(mdl, 61, ',');
			delete[] makeModel;
			makeModel = new char[strlen(mdl) + 1];
			strcpy(makeModel, mdl);
			makeModel[strlen(mdl)] = '\0';
		}
		else if (!isCsv() && !is.fail()) {

			cout << "Enter Licence Plate Number: ";
			string plate;
			getline(is, plate);
			while (plate.size() < 1 || plate.size() > 8)
			{
				cout << "Invalid Licence Plate, try again: ";
				getline(is, plate);
			}

			strcpy(licensePlate, plate.c_str());
			int size = strlen(licensePlate);
			for (int i = 0; i < size; i++) {

				if (licensePlate[i] >= 97 && licensePlate[i] <= 122) {
					
					licensePlate[i] -= 32;
				}
			}

			cout << "Enter Make and Model: ";
			string mkMdl;
			getline(is, mkMdl, '\n');

			while (mkMdl.size() < 2 || mkMdl.size() > 60) {

				cout << "Invalid Make and model, try again: ";
				getline(is, mkMdl, '\n');
			}

			delete[] makeModel;
			makeModel = new char[mkMdl.size() + 1];
			strcpy(makeModel, mkMdl.c_str());
			makeModel[mkMdl.size()] = '\0';
		}
		else {

			setEmpty();
		}

		return is;
	}
	

	ostream& Vehicle::write(ostream& os) const {

		if (isEmpty())
		{
			os << "Invalid Vehicle Object" << endl;
		}
		else if (isCsv())
		{
			os << parkingSpotNum << "," << licensePlate << "," << makeModel << ",";

		}
		else if (!isCsv())
		{
			os << "Parking Spot Number: ";
			getParkingSpot() == 0 ? os << "N/A" << endl : os << getParkingSpot() << endl;
			char* license = getLicensePlate();
			os << "Licence Plate: " << license << endl;
			delete[] license;
			os << "Make and Model: " << getMakeModel() << endl;
		}
		return os;
	}
}
