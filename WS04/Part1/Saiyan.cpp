//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/6/2020

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Saiyan.h"
#include <cstring>

using namespace std;

namespace sdds{

    Saiyan::Saiyan() {
         setEmpty();
	}
	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || strlen(name) < 1 || dob > 2020 || power < 0) {
			setEmpty();
		}
			else {
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}


	void Saiyan::setEmpty() {
		
		m_name[0] = '\0';
		m_dob = 0;
	    m_power = 0;
	    m_super = false;
	}

	bool Saiyan::isValid() const {
		if (m_name != nullptr && m_dob != 0 && m_power != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}

	void Saiyan::display() const {
		if (!isValid()) {
			cout << "Invalid Saiyan!" << endl;
		} 
		else {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << endl;
			cout << "Power: " << m_power << endl;
			if (m_super == true) {
				cout << "Super: yes" << endl;
			}
			else {
				cout << "Super: no" << endl;
			}			
		}
		return;
	}

	bool Saiyan::fight(const Saiyan& other) const {
		if (m_name == nullptr || m_dob > 2020 || m_power <= 0) {
			return false;
		}
		else {
			if (m_power < other.m_power) { 
				return false;
			}
			else {
				return true;
			}
		}
	}
}

