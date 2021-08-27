//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 8
// Date:           22/07/2020


#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Employee.h"

namespace sdds {

    const int MAX_CHAR = 32; 

    class Doctor : public Employee {
    private:
        char doc_type[MAX_CHAR + 1];
        bool doc_specialist;

    public:
        Doctor(const char* type, double salary, int hours, bool specialist = false);
        virtual double getSalary(int workedHours) const;
        virtual std::ostream& display(std::ostream& out = std::cout) const;
    };
}

#endif //SDDS_DOCTOR_H