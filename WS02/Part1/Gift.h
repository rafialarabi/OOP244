#ifndef GIFT_H
#define GIFT_H

#include <iostream>

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	void gifting(char* desc);

	void gifting(double& price);

	void gifting(int& units);

	void display(const Gift& theGift);
} 
#endif