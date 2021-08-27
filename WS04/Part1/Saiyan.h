//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/6/2020

#include <iostream>

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds {
	
	class Saiyan {
	private:
		char m_name[32];   // member instances
		int m_dob;
		int m_power;
		bool m_super;

	public:
		Saiyan();     // default constructor
		Saiyan(const char*, int, int);   //custom constructor
		bool isValid() const;    //member functions
		bool isSuper() const;
		void setEmpty();
		void display() const;
		bool fight(const Saiyan&) const;
		void set(const char*, int, int, bool super = false);
	};
}
#endif 
