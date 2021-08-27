//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           24/6/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <iomanip>
#include <math.h> 
#include <sstream>
#include <cstring>
#include"Ship.h"

using namespace std;

namespace sdds {

	Ship::Ship() {
		m_type[0] = '\0';
		m_engCnt = 0;
	}

	Ship::Ship(const char* type, Engine* engCnt, int engine) {
		setEmpty();
		set(type, engCnt, engine);
	}

	void Ship::setEmpty() {
		m_type[0] = '\0';
		m_engCnt = 0;
	}

	void Ship::set(const char* name, Engine* engine, int size) {
		int eng = strlen(name);

		if (name != nullptr && engine != nullptr) 
		{
			for (int i = 0; i < size; i++) 
			{
				m_engine[i] = engine[i];
			}

			strncpy(m_type, name, eng);
			this->m_type[eng] = '\0';
			m_engCnt = size;
		}
		else 
		{
			setEmpty();
		}
	}

	bool Ship::checkEmpty() const {
		if ((m_type[0] == '\0') || m_engCnt == 0) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	void Ship::display() const {
		if (strlen(m_type) < TYPE_MAX_SIZE && m_engCnt > 0 && m_engCnt < 10) {
			cout << m_type << " - ";

			if (floor(getPower()) == getPower()) 
			{
				cout << fixed;
				cout.precision(0);
				cout << getPower() << endl;
			}
			else
			{
				cout << getPower() << endl;
			}
			for (int i = 0; i < m_engCnt; i++) 
			{

				m_engine[i].display();
			}
			cout << fixed;
			cout.precision(3);
		}
		else {
			cout << "No available data" << endl;
		}

	}

	Ship& Ship::operator+=(Engine engine) {
		if (m_engCnt >= 10 || m_type[0] == '\0') 
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else 
		{
			this->m_engine[m_engCnt++] = engine;

		}
		return *this;
	}

	bool Ship::operator<(double power) const {

		if (this->getPower() < power) 
		{
			return true;
		}
		return false;
	}

	float Ship::getPower() const {
		float Pwr;
		double solution = 0;
		
		for (int i = 0; i < m_engCnt; i++) 
		{
			solution += m_engine[i].get();
		}
		
		Pwr = float(solution) * 5;
		
		return Pwr;

	}

	Ship::operator bool() const {
		return !this->checkEmpty();
	}
	bool operator<(double power, const Ship& theShip) {
		if (power < theShip.getPower())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    bool operator==(const Ship& count, const Ship& option) {
		if (count.getPower() > option.getPower() || count.getPower() < option.getPower()) 
		{
			return false;
		}
		else {
			return true;
		}
	}
}
