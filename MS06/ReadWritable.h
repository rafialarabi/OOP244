



// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/08/2020

/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */


#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>
#include <string>


namespace sdds {

	class ReadWritable {

		bool choice;

	public:
		ReadWritable();
		~ReadWritable();
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream&) = 0;
		virtual std::ostream& write(std::ostream&) const = 0;
	};
	std::istream& operator>>(std::istream&, ReadWritable&);
	std::ostream& operator<<(std::ostream&, const ReadWritable&);

}

#endif // !SDDS_READWRITABLE_H

