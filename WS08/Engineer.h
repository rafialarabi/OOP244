
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 8
// Date:           22/07/2020


#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Employee.h"

namespace sdds {

    class Engineer : public Employee {
    private:
        int eng_level;

    public:
        Engineer(double salary, int level);
        virtual double getSalary(int workedHours) const;
        virtual std::ostream& display(std::ostream& out) const;
    };    
}

#endif //SDDS_ENIGINEER_H