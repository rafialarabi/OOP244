//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           10/6/2020


#define _CRT_SECURE_NO_WARNINGS

#include "Cargo.h"
#include "Train.h"

using namespace std; 

namespace sdds {
	void Train::initialize(const char* tname, int t_id) {
		if (tname == nullptr || tname[0] == '\0' || t_id < 1 ){
			name[0] = '\0';
			id = 0;
		}
		else {
			strcpy(name, tname);
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
	
	void Train::loadCargo(Cargo car) {
		unloadCargo();
		cargo = new Cargo;
		*cargo = car;
	}
	
	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}
	
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if(!isValid()){ 
			cout << "This is an invalid train." << endl;
		}
		else if (isValid()) {
			cout << "Name: " << name << endl << "ID: " << id << endl;
			if (cargo == nullptr) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "Cargo: " << cargo->cargo_desc << endl << "Weight: " << cargo->weight<< endl;
			}
		}
	}
}
