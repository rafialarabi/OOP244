
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/08/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include <iostream>
#include "Vehicle.h"
#include "Menu.h"
#include"Car.h"
#include"Motorcycle.h"
using namespace std;


namespace sdds {

	const int MAX_NUM_OF_PARKING_SPOT = 100;	

	class Parking {

		char* p_fileName;
		Menu* p_parkingMenu;
		Menu* p_vehicleSelectionMenu;
		int NumOfSpots;
		Vehicle* Spots[MAX_NUM_OF_PARKING_SPOT] = { nullptr };
		int NumOfParkedVehicle;

	private:
		bool isEmpty();
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicle();
		bool closeParking();
		bool exitParkingApp() const;
		bool loadDataFile();
		void saveDataFile();

	public:
		Parking(const char* datafile, int noOfSpots);
		Parking(const Parking&) = default;
		Parking& operator=(const Parking&) = default;
		virtual ~Parking();
		int run();
	};
}

#endif // SDDS_PARKING_H