//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 8
// Date:           22/07/2020


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Employee.h"
using namespace std;


namespace sdds {

    Employee::Employee(double salary, int hours) : MIN_NUM_HOURS{hours} {
        emp_hourlySalary = salary;
    }

    Employee::~Employee() {}

    double Employee::getHourlySalary() const {
        return emp_hourlySalary;
    }
    
    int Employee::getMinWorkingHours() const {
        return MIN_NUM_HOURS;
    }

    std::ostream& operator<<(std::ostream& out, const Employee& emp) {
        
        emp.display();
        return out;
    }
}