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
#include"Engine.h"

using namespace std;

namespace sdds {


	Engine::Engine() {
		m_type[0] = '\0';
		m_size = 0;
	}

	Engine::Engine(const char* name, double size) {
		setEmpty();
		set(name, size);
	}

	void Engine::setEmpty() {
		m_type[0] = '\0';
		m_size = 0;
	}

	void Engine::set(const char* name, double size) {
		

		if (name != nullptr && name[0] != '\0') 
		{
			int eng = strlen(name);

			strncpy(this->m_type, name, eng);
			strncpy(m_type, name, eng);

		    this->m_type[eng] = '\0';
			this->m_size = size;
		}
		else 
		{
			setEmpty();
		}
	}


	double Engine::get() const {
		double length = m_size;
		
		return length;
	}

	void Engine::display() const {
		
		cout << fixed;
		cout.precision(1);

		if (floor(m_size) == m_size) 
		{
			cout << fixed;
			cout.precision(0);
			cout << m_size << " liters" << " - " << m_type << endl;
		}
		else 
		{
			cout << m_size << " liters" << " - " << m_type << endl;
		}
	}
}
