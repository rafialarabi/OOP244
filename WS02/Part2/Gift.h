//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           7/6/2020


#ifndef GIFT_H
#define GIFT_H

#include <iostream>

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;

	struct Wrapping {
		char* m_pattern;
	};

	struct Gift {
		char      m_description[MAX_DESC + 1];
		double    m_price;
		int       m_units;
		Wrapping* m_wrap;                    // Array of wrappings
		int       m_wrapLayers;             // Layers of wrappings
	};

	void gifting(Gift&);
	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);

	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
}
#endif