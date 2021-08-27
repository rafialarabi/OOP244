
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 2
// Date:           19/07/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Parking.h"

using namespace std;

namespace sdds {

	Parking::Parking() {

		p_fileName = nullptr;
		p_parkingMenu = nullptr;
		p_vehicleSelcetionMenu = nullptr;
	}

	Parking::Parking(const char* file) {

		if (file != nullptr && *file != '\0') {

			p_fileName = new char[strlen(file) + 1];
			strcpy(p_fileName, file);
			bool valid = loadDataFile();
			if (valid) {
				p_parkingMenu = new Menu("Parking Menu, select an action:");
				p_parkingMenu->add("Park Vehicle");
				p_parkingMenu->add("Return Vehicle");
				p_parkingMenu->add("List Parked Vehicles");
				p_parkingMenu->add("Close Parking (End of day)");
				p_parkingMenu->add("Exit Program");

				p_vehicleSelcetionMenu = new Menu("Select type of the vehicle:", 1);
				p_vehicleSelcetionMenu->add("Car");
				p_vehicleSelcetionMenu->add("Motorcycle");
				p_vehicleSelcetionMenu->add("Cancel");
			}
			else {
				p_parkingMenu = nullptr;
				p_vehicleSelcetionMenu = nullptr;
			}
		}
		else {
			cout << "Error in data file" << endl;
			p_fileName = nullptr;
			p_parkingMenu = nullptr;
			p_vehicleSelcetionMenu = nullptr;
		}
	}

	Parking::~Parking() {
		saveDataFile();
		delete[] p_fileName;
		delete p_parkingMenu;
		delete p_vehicleSelcetionMenu;
	}

	bool Parking::isEmpty() {
		bool valid = false;

		if (p_fileName == nullptr && p_parkingMenu == nullptr && p_vehicleSelcetionMenu == nullptr) {
			valid = true;
		}

		return valid;
	}

	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() {

		int option = p_vehicleSelcetionMenu->run();
		switch (option) {
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		}
	}

	void Parking::returnVehicle() {
		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkedVehicle() {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() {
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitParkingApp() const {

		bool valid = true;
		bool decision, confirmed;
		char choice, move;

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			choice = cin.get();
			move = cin.get();
			cin.clear();

			decision = (choice == 'Y') || (choice == 'y') || (choice == 'N') || (choice == 'n');
			confirmed = (move == '\n');

			if (!(decision && confirmed)) {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.ignore(100, '\n');
			}

		} while (!(decision && confirmed));


		if (choice == 'Y' || choice == 'y') {
			cout << "Exiting program!" << endl;
		}
		else {
			valid = false;
		}
		return valid;
	}

	bool Parking::loadDataFile() {
		bool valid = true;
		if (!isEmpty()) {
			cout << "loading data from " << p_fileName << endl;
		}
		else {
			valid = false;
		}
		return valid;
	}

	void Parking::saveDataFile() {
		if (!isEmpty()) {
			cout << "Saving data into " << p_fileName << endl;
		}
	}


	int Parking::run() {
		int valid = 1;
		int choice;

		if (!isEmpty()) {
			
			while (1) {
				parkingStatus();
				choice = p_parkingMenu->run();
				switch (choice) {
				case 1:
					parkVehicle();
					break;

				case 2:
					returnVehicle();
					break;

				case 3: listParkedVehicle();
					break;

				case 4:
					if (closeParking()) {
						return 1;
					}
					else {
						break;
					}

				case 5:
					if (exitParkingApp()) {
						return 1;
					}
					else {
						break;
					}
				}
			}
		}
		return valid;
	}
}