//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           21/6/2020

#define _CRT_SECURE_NO_WARNINGS

#include "Saiyan.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {

	Saiyan::Saiyan() {
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		m_name = nullptr;
		set(name, dob, power);
	}

	Saiyan::~Saiyan() {

		delete[] m_name;
		m_name = nullptr;

	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (name == nullptr || dob > 2020 || power < 0 || level < 0) {
			setEmpty();
		}
		else {

			if (m_name == nullptr)
			{
				m_name = new char[strlen(name) + 1];
				strcpy(m_name, name);
			}

			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	}

	void Saiyan::setEmpty() {

		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = 0;
	}

	bool Saiyan::isValid() const {
		bool i = true;

		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0 || m_level < 0) {

			i = false;
		}
		return i;

	}

	void Saiyan::display() const {
		if (!isValid()) {
			cout << "Invalid Saiyan!" << endl;
		}
		else {
			cout << m_name << endl;
			cout << "     DOB: " << m_dob << endl;
			cout << "   Power: " << m_power << endl;
			cout << "   Super: ";
			if (m_super == true) {
				cout << "yes" << endl;
				cout << "   Level: " << m_level << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}

	void Saiyan::powerIncrement() {

		m_power += (m_level * m_power * 10) / 100;

	}

	bool Saiyan::fight(Saiyan& other) {
		
		if (isValid() && other.isValid()) {

			if (m_super)
			{
				powerIncrement();
			}
			if (other.m_super) {
				other.powerIncrement();
			}
			if (m_power < other.m_power) {
				return false;
			}
			else {
				return true;
			}
		}
		else {

			return false;

		}

	}	
	
}


