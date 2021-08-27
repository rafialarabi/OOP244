



// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/08/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>
#include "Vehicle.h"
#include "Menu.h"
#include "Parking.h"
using namespace std;

namespace sdds {

	Parking::Parking(const char* datafile, int noOfSpots) {

		if (datafile != nullptr && *datafile != '\0' && noOfSpots >= 10 && noOfSpots <= MAX_NUM_OF_PARKING_SPOT) {

			p_fileName = new char[strlen(datafile) + 1];
			strcpy(p_fileName, datafile);

			NumOfSpots = noOfSpots;
			NumOfParkedVehicle = 0;

			for (int i = 0; i < MAX_NUM_OF_PARKING_SPOT; i++) {
				Spots[i] = nullptr;
			}

			bool valid = loadDataFile();

			if (valid) {
				p_parkingMenu = new Menu("Parking Menu, select an action:");
				p_parkingMenu->add("Park Vehicle");
				p_parkingMenu->add("Return Vehicle");
				p_parkingMenu->add("List Parked Vehicles");
				p_parkingMenu->add("Close Parking (End of day)");
				p_parkingMenu->add("Exit Program");

				p_vehicleSelectionMenu = new Menu("Select type of the vehicle:", 1);
				p_vehicleSelectionMenu->add("Car");
				p_vehicleSelectionMenu->add("Motorcycle");
				p_vehicleSelectionMenu->add("Cancel");
			}
			else {
				p_parkingMenu = nullptr;
				p_vehicleSelectionMenu = nullptr;
			}
		}
		else {

			cout << "Error in data file" << endl;
			p_fileName = nullptr;
			p_parkingMenu = nullptr;
			p_vehicleSelectionMenu = nullptr;
			NumOfSpots = 0;
			NumOfParkedVehicle = 0;

			for (int i = 0; i < MAX_NUM_OF_PARKING_SPOT; i++) {
				Spots[i] = nullptr;
			}
		}
	}

	Parking::~Parking() {
		saveDataFile();
		delete[] p_fileName;
		for (int i = 0; i < MAX_NUM_OF_PARKING_SPOT; i++) {
			Spots[i] = nullptr;
			delete Spots[i];
		}

	}


	bool Parking::isEmpty() {
		bool valid = false;

		if (p_fileName == nullptr && p_parkingMenu == nullptr && p_vehicleSelectionMenu == nullptr) {
			valid = true;
		}

		return valid;
	}

	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";

		int available_spots = NumOfSpots - NumOfParkedVehicle;

		cout << left << setw(4) << available_spots << " *****" << endl;
	}


	void Parking::parkVehicle() {

		if (NumOfSpots == NumOfParkedVehicle) {
			cout << "Parking is full" << endl;
		}
		else {

			int choice = p_vehicleSelectionMenu->run();
			Vehicle* vehicle;
			switch (choice) {

			case 1:
				vehicle = new Car();
				vehicle->setCsv(false);

				vehicle->read(cin);  


				for (int i = 0; i < NumOfSpots; i++) {
					if (Spots[i] == nullptr) {
						Spots[i] = vehicle;
						vehicle->setParkingSpot(i + 1);
						NumOfParkedVehicle++;

						cout << "\nParking Ticket" << endl;
						cout << *vehicle << endl;

						break; 
					}
				}
				break;

			case 2:
				vehicle = new Motorcycle();
				vehicle->setCsv(false);

				vehicle->read(cin);  

				for (int i = 0; i < NumOfSpots; i++) {
					if (Spots[i] == nullptr) {
						Spots[i] = vehicle;
						vehicle->setParkingSpot(i + 1);
						NumOfParkedVehicle++;

						cout << "\nParking Ticket" << endl;
						cout << *vehicle << endl;

						break; 
					}
				}
				break;

			case 3:
				cout << "Parking Cancelled" << endl;
				break;

			default:
				cout << "Invalid input" << endl;
			}
		}
	}

	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";

		char l_plate[8 + 1];
		bool found = false;
		
		do {
			cin.getline(l_plate, 8 + 1);
			if (strlen(l_plate) < 1 || strlen(l_plate) > 8) {
				cout << "Invalid Licence Plate, try again: ";
			}
		} while (strlen(l_plate) < 1 || strlen(l_plate) > 8);

		for (int i = 0; i < NumOfSpots; i++) {
			
			if (Spots != nullptr && *Spots[i] == l_plate) {  
				Spots[i]->setCsv(false);
				cout << "\nReturning: " << endl;
				//cout << *Spots[i] << endl;
				Spots[i]->write(cout);   
				NumOfParkedVehicle--;

				delete Spots[i];
				Spots[i] = nullptr;
				found = false;
				break; 			}
			else {
				found = true;  			}			
		}
		if(found)  
			{
				cout << "License plate " << l_plate << " Not found" << endl;
			}
	}

	void Parking::listParkedVehicle() {
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < NumOfSpots; i++) {
			if (Spots[i] != nullptr) {
				Spots[i]->setCsv(false);
				Spots[i]->write(cout);     
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {

		char cp[10];
		bool confirmation = true;
		bool getin = false;
		bool selection = false;

		for (int i = 0; i < NumOfSpots; i++) {
			if (Spots[i] != nullptr) {
				confirmation = false;
			}
		}

		if (!confirmation) {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> cp;
			cin.clear();

			while (!getin) {
				if (!strcmp(cp, "y")) {
					cout << "Closing Parking" << endl << endl;
					for (int i = 0; i < NumOfSpots; i++) {
						if (Spots[i] != nullptr) {
							cout << "Towing request" << endl;
							cout << "*********************" << endl;

							cout << *Spots[i];
							if (i < NumOfParkedVehicle - 1) {

								cout << endl;
							}
							Spots[i]->~Vehicle();
							Spots[i] = nullptr;
						}
					}

					selection = false;

					getin = true;
				}
				else if (!strcmp(cp, "n")) {
					cout << "Aborted!" << endl;
					getin = true;
					selection = true;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> cp;
					cin.ignore(2000, '\n');
				}
			}
		}
		return selection;
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

		bool goodState = true;


		if (!isEmpty()) {

			ifstream filemng(p_fileName);         

			if (!filemng.is_open() || isEmpty()) { goodState = true; } 

			char word;
			Vehicle* vehicle;
			int counterValue = 0;
		
			while (goodState && counterValue < NumOfSpots && filemng) {
				vehicle = nullptr;
				word = '\0';  

				filemng >> word;
				filemng.ignore();

				if (word == 'M') {
					vehicle = new Motorcycle;
				}
				else if (word == 'C') {
					vehicle = new Car;
				}

				if (vehicle) {
					vehicle->setCsv(true);
					filemng >> *vehicle;

					if (filemng) {
						Spots[vehicle->getParkingSpot() - 1] = vehicle;
						NumOfParkedVehicle++;
					}
					else {
						delete vehicle;
						vehicle = nullptr;
						goodState = false;
					}
				}
				counterValue++;
			}
		}
		return goodState;
	}

	void Parking::saveDataFile() {

		std::ofstream filemng(p_fileName);

		if (!isEmpty() && filemng.is_open()) {
			for (int i = 0; i < NumOfSpots; i++) {
				if (Spots[i] != nullptr) {
					Spots[i]->setCsv(true);
					Spots[i]->write(filemng);
				}
			}
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
