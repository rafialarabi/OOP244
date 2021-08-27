//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           24/6/2020


#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;

	class Engine {
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];
	public:
		Engine();
		Engine(const char*, double);
		void setEmpty();
		double get() const;
		void set(const char* name, double size);
		void display() const;
	};

}

#endif