
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 2
// Date:           19/07/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include <iostream>
#include "Menu.h"
using namespace std;

namespace sdds
{
	class Parking {
		
		char* p_fileName;
		Menu* p_parkingMenu;
		Menu* p_vehicleSelcetionMenu;

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
		Parking();
		Parking(const char*);
		Parking(const Parking&) = default;
		Parking& operator=(const Parking&) = default;
		~Parking();
		int run();
	};
}

#endif // SDDS_PARKING_H