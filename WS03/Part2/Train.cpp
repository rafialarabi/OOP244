//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           14/6/2020



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"
#include"Cargo.h"
using namespace std;

namespace sdds {
	void Train::initialize(const char* t_name, int t_id) {
		if (t_name == nullptr || t_name[0] == '\0' || t_id < 0) {
			name[0] = '\0';
			id = 0;
		}
		else {
			strcpy(name, t_name);
			id = t_id;
		}
		cargo = nullptr;
	}

	bool Train::isValid() const {
		bool valid;

		if (id != 0) {
			valid = true;
		}
		else {
			valid = false;
		}

		return valid;
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if ((name[0] == '\0' || id < 0)) {
			cout << "This is an empty train." << endl;
		}
		else
		{
			cout << "    Name: " << name << endl;
			cout << "      ID: " << id << endl;

			if (cargo != nullptr) {
				cout.precision(2);
				cout << "   Cargo: " << cargo->getDesc() << endl;
				cout << fixed << "  Weight: " << cargo->getWeight() << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}
	}

	void Train::loadCargo(Cargo car) {
		if (cargo != nullptr) {
			delete cargo;
		}
		cargo = new Cargo;
		*cargo = car;
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}


	bool Train::swapCargo(Train& other) {
		bool valid = false;


		if (other.cargo != nullptr) {
			Cargo temp;
			temp.initialize(cargo->getDesc(), cargo->getWeight());
			cargo->initialize(other.cargo->getDesc(), other.cargo->getWeight());
			other.cargo->initialize(temp.getDesc(), temp.getWeight());
			valid = true;
		}
		return valid;
	}

	bool Train::increaseCargo(double weight) {

		bool valid;
		if (cargo == nullptr || cargo->getWeight() == MAX_WEIGHT)
			valid = false;
		else {

			cout.precision(3);
			if (cargo->getWeight() + weight > MAX_WEIGHT)
				cargo->setWeight(MAX_WEIGHT);
			else
				cargo->setWeight(cargo->getWeight() + weight);

			valid = true;

		}
		return valid;
	}

	bool Train::decreaseCargo(double weight) {
		bool result;
		cout.precision(4);

		if (cargo == nullptr || cargo->getWeight() == MIN_WEIGHT)
			result = false;

		else {

			if (cargo->getWeight() - weight < MIN_WEIGHT)
				cargo->setWeight(MIN_WEIGHT);
			else
				cargo->setWeight(cargo->getWeight() - weight);
			result = true;
		}
		return result;

	}


}