

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 6 (part-1)
// Date:           08/07/2020


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Basket.h"

using namespace std;

namespace sdds {

	Basket::Basket() {
		setEmpty();
	}

	Basket::Basket(Fruit* fruits, int cnt, double price) {
		
		setEmpty();

		if (fruits != nullptr && cnt > 0 && price > 0) {
			m_cnt = cnt;
			m_fruits = new Fruit[m_cnt];

			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = fruits[i];
			}
			m_price = price;
		}
		else {
			setEmpty();
		}
	}

	Basket::Basket(const Basket& other) {

         m_fruits = nullptr;
		*this = other;
	}

	Basket::~Basket() {
		delete[] m_fruits;
		m_fruits = nullptr;
	}

	void Basket::setEmpty() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	void Basket::setPrice(double price) {
		if (price >= 0) {
			m_price = price;
		}
	}

	bool Basket::CheckEmpty() const {
		bool space = true;

		if (m_fruits == nullptr && m_cnt == 0 && m_price == 0) {
			space = false;
		}
		return space;
	}

	Basket& Basket::operator+=(Fruit type) {

		Fruit* count = new Fruit[m_cnt + 1];
		
		for (int i = 0; i < m_cnt; i++) {
			
			count[i] = m_fruits[i];
		}
		count[m_cnt++] = type;
		
		delete[] m_fruits;
		m_fruits = count;

		return *this;
	}

	Basket& Basket::operator=(const Basket& bask) {

		if (this != &bask) {
			m_cnt = bask.m_cnt;
			m_price = bask.m_price;

			delete[] m_fruits;

			if (bask.m_fruits != nullptr) {
				m_fruits = new Fruit[m_cnt];

				for (int i = 0; i < m_cnt; i++) {
					m_fruits[i] = bask.m_fruits[i];
				}
			}
			else {
				m_fruits = nullptr;
			}
		}
		return *this;
	}

	void Basket::display(std::ostream& msg) const {
		if (m_fruits != nullptr) {
			cout << "Basket Content:" << endl;

			for (int i = 0; i < m_cnt; i++) {

				cout.setf(ios::fixed);
				cout.precision(2);
				cout.width(10);
				cout << m_fruits[i].m_name << ": " << m_fruits[i].m_qty << "kg" << endl;
			}

			cout << "Price: " << m_price << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
		else
		{
			cout << "The basket is empty!" << endl;

		}
	}

	Basket::operator bool() const {
		bool solution;

		if (m_fruits != nullptr) {
			solution = true;
		}
		else {
			solution = false;
		}
		return solution;
	}

	std::ostream& operator<<(std::ostream& msg, const Basket& bask) {
		
		bask.display(msg);
		return msg;
	}

}

