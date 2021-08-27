


// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/08/2020

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

 

        bool value = false;

 

        int f_length = strlen(licensePlate);
        int s_length = strlen(plt_value);

 

        if (*plt_value != '\0' && (f_length == s_length)) {

 

            int length = strlen(plt_value);

 

            for (int i = 0; i < length; i++) {

 

                if (toupper(licensePlate[i]) == toupper(plt_value[i])) {

 

                    value = true;
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

		bool choice;
		setEmpty();

		char license[8 + 1];
		license[0] = '\0';
		int Spot = 0;

		string count;
		int length = 0;

		if (this->isCsv()){

			if (getline(is, count, ',')) Spot = stoi(count);
			this->setParkingSpot(Spot);

			if (std::getline(is, count, ',')) {

				length = count.length();
				for (int i = 0; i < length; i++){

					license[i] = toupper(count[i]);
				}
				license[length] = '\0';
			}
			strcpy(licensePlate, license);

			if (std::getline(is, count, ',')) {

				this->setMakeModel(count.c_str());
			}
		}
		else {
			char digit = '\0';
			license[0] = '\0';
			std::cout << "Enter Licence Plate Number: ";

			do {
				is.get(license, 9);
				is.get(digit);
				choice = true;
				if (strlen(license) > 8 || digit != '\n' || is.bad()) {
					is.clear();
					is.ignore(500, '\n');
					cout << "Invalid Licence Plate, try again: ";
					choice = false;
				}
			} while (!choice);

			for (unsigned int i = 0; i < strlen(license); i++) {
				license[i] = toupper(license[i]);
			}
			strcpy(licensePlate, license);



			cout << "Enter Make and Model: ";
			if (getline(is, count)){

				while (count.length() < 2 || count.length() > 60){
					cout << "Invalid Make and model, try again: ";
					getline(is, count);
				}

				setMakeModel(count.c_str());
			}
			setParkingSpot(0);
		}
		return is;
	}


	ostream& Vehicle::write(ostream& os) const {

		if (isEmpty()) {

			os << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				os << parkingSpotNum << "," << licensePlate << "," << makeModel << ",";
			}
			else if (!isCsv()) {
				os << "Parking Spot Number: ";

				if (parkingSpotNum > 0) {
					os << getParkingSpot() << endl;
				}
				else {
					os << "N/A" << endl;
				}
				os << "Licence Plate: " << licensePlate << endl;

				os << "Make and Model: " << makeModel << endl;
			}
		}
		return os;


	}
}