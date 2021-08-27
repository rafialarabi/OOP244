#define _CRT_SECUR_NO_WARNINGS

#include "Gift.h"
using namespace std;

namespace sdds {
	//This below function recieve a pointer of character array and also recieve the value
	void gifting(char* desc) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	//Below fi=unction works with a double and gets the value
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

	// This particular function works with a structure and gets the value from it
	void display(const Gift& theGift) {
		cout << "Gift Details:" << endl << " Description: " << theGift.g_description << endl << "       Price: "
		<< theGift.g_price << endl << "       Units: " << theGift.g_units << endl << endl;
	}
	
}