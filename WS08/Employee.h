//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 8
// Date:           22/07/2020


#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds  {

    class Employee {
    private:
        const int MIN_NUM_HOURS;
        double emp_hourlySalary;

    protected:
        double getHourlySalary() const;
        int getMinWorkingHours() const;
        
    public:
        Employee(double salary, int hours);
        virtual double getSalary(int workedHours) const = 0;
        virtual std::ostream& display(std::ostream& os = std::cout) const = 0;
        virtual ~Employee();
    };

    std::ostream& operator<<(std::ostream& out, const Employee& emp); 
}

#endif //SDDS_EMPLOYEE_H