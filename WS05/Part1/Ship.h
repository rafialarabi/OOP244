//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           24/6/2020


#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include"Engine.h"

using namespace std;

namespace sdds {

	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;


	class Ship {
		char m_type[TYPE_MAX_SIZE];
		int m_engCnt;
		Engine m_engine[10];
	public:
		Ship();
		Ship(const char*, Engine*, int);
		void setEmpty();
		bool checkEmpty() const;
		void set(const char* name, Engine* engine, int size);
		void display() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		friend bool operator==(const Ship& count, const Ship& option);
		float getPower() const;
		explicit operator bool() const;
	};

	bool operator<(double power, const Ship& theShip);
}
#endif
