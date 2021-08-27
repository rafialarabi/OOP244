//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           7/6/2020



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Gift.h"
using namespace std;

namespace sdds {

	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	}


	//This below function recieve a pointer of character array and also recieve the value
	void gifting(char* desc) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	//Below function works with a double and gets the value
	void gifting(double& price) {
		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and 999.999" << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	// The function works with a integer and gets the value
	void gifting(int& units) {
		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1) {
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}

	void display(const Gift& theGift) {
		if (theGift.m_wrapLayers == 0) {
			cout << "Gift Details:" << endl << " Description: " << theGift.m_description << endl << "       Price: "
				<< theGift.m_price << endl << "       Units: " << theGift.m_units << endl << "Unwrapped!" << endl;
		}
		else {
			cout << "Gift Details:" << endl << " Description: " << theGift.m_description << endl << "       Price: "
				<< theGift.m_price << endl << "       Units: " << theGift.m_units << endl << "Wrap Layers: " << theGift.m_wrapLayers << endl;
				

			for (int i = 0; i < theGift.m_wrapLayers; i++) {
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap->m_pattern << endl;
			}
		}
	} 



	bool wrap(Gift& theGift) {
		bool options, Input;
		if (theGift.m_wrapLayers < 1) {
			cout << "Wrapping gifts..." << endl;
			do
			{
				Input = true;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> theGift.m_wrapLayers;
				if (theGift.m_wrapLayers < 1) {
					cout << "Layers at minimum must be 1, try again." << endl;
					Input = false;

				}
			} while (!Input);
			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				char* choice = new char[MAX_WRAP + 1];
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin.width(MAX_WRAP + 1);
				cin >> choice;
				theGift.m_wrap[i].m_pattern = new char[strlen(choice) + 1];
				strcpy(theGift.m_wrap[i].m_pattern,choice);
				delete[]choice;
				choice = nullptr;
			}
			options = true;

		}
		else
		{
			cout << "Gift is already wrapped!" << endl;
			options = false;
		}
		return options;
	}
	bool unwrap(Gift& theGift)
	{
		bool options;
		if (theGift.m_wrap != nullptr)
		{
			cout << "Gift being unwrapped." << endl;
			// Deallocation of wrap and all children to prevent leak
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				delete[] theGift.m_wrap[i].m_pattern;
				theGift.m_wrap[i].m_pattern = nullptr;
			}
			delete[] theGift.m_wrap;
			theGift.m_wrap = nullptr;
			theGift.m_wrapLayers = 0;
			options = true;
		}
		else
		{
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			options = false;
		}
		return options;
	}
}