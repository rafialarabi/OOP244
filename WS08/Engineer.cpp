//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Workshop 8
// Date:           22/07/2020

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Engineer.h"
using namespace std;

namespace sdds {

    Engineer::Engineer(double salary, int level) : Employee(salary, 30) {
        eng_level = level;
    }
    
    double Engineer::getSalary(int workedHours) const {
        
        double Salary = 0.0f;
        double hourlyRate = Employee::getHourlySalary();
        int MinNumHours = Employee::getMinWorkingHours();

        Salary = (workedHours * hourlyRate) + (eng_level * 40.00);

        if (workedHours < MinNumHours) {
            Salary -= Salary * 0.2;
        }
        return Salary;
    }
    
    ostream& Engineer::display(ostream& out) const {

        out << "Engineer" << endl;
        out << setw (20) << "Level: " << eng_level << endl;
        out << setw (20) << "Pay Rate: " << getHourlySalary() << endl;
        out << setw (20) << "Min Hours: " << getMinWorkingHours() << endl;

        return out; 
    }
}