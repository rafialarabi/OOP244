

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 6 (part-1)
// Date:           08/07/2020


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H


namespace sdds {

	struct Fruit {
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket {
	private:
		Fruit* m_fruits; 
		int m_cnt;
		double m_price;

	public:
		Basket();                                           //default constructor
	    Basket(Fruit* m_fruits, int cnt, double price);     //custom constructor
		Basket(const Basket&);                              //copy constructor
		~Basket();                                          //destructor
		void setEmpty();                                     
		void setPrice(double price);
		bool CheckEmpty() const;
		Basket& operator+=(Fruit fruit);                    //overloaiding an operator
		Basket& operator=(const Basket& bask);              //copy assignment operator												
		void display(std::ostream& msg) const;
		explicit operator bool() const;
	};

     std::ostream& operator<<(std::ostream& msg, const Basket& bask); //friend helper func.
}

#endif

