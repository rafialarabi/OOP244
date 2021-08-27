

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Workshop 9
// Date:           29/07/2020

/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */

#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H

namespace sict{

template <typename F, typename S>
bool validate(const F& minimum, const S* testValue, int num_element, bool* values) {
	bool solution = true;

	for (int i = 0; i < num_element; i++) {
		if (testValue[i] >= minimum) {
			values[i] = true;
		}
		else {
			values[i] = false;
			solution = false;
		}
	}
	return solution;
};

}
#endif //SDDS_VALIDATE_H