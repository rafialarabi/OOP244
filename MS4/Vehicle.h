

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 4
// Date:           29/07/2020

/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <iomanip>
#include "ReadWritable.h"

namespace sdds {

	class Vehicle : public ReadWritable {

		char licensePlate[8 + 1];
		char* makeModel;
		int parkingSpotNum;

	protected:
		void setEmpty();
		bool isEmpty() const;
		char* getLicensePlate() const;
		char* getMakeModel() const;
		void setMakeModel(const char* mkMdl);

	public:
		Vehicle();
		Vehicle(const char* num_plate, const char* mdl_value);
		virtual ~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int spot_num);

		bool operator==(const char* plt_value) const;
		bool operator==(const Vehicle& car) const;

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	};

}

#endif //SDDS_VEHICLE_H