//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           21/6/2020

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
namespace sdds {

	class Saiyan {

	private:
		char* m_name;   // member instances
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;

	public:
		~Saiyan();     //destructor
		Saiyan();     //default constructor
		Saiyan(const char*, int, int);   //custom constructor
		bool isValid() const;    //member functions
		void setEmpty();
		void display() const;        
		bool fight(Saiyan& other) ;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		void powerIncrement();   //increase power of the Super Saiyan
	};
}
#endif 
