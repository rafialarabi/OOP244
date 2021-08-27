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
#include "Doctor.h"

using namespace std;

namespace sdds {

    Doctor::Doctor(const char* type, double salary, int hours, bool specification) : Employee(salary, hours) {
        strncpy(doc_type, type, MAX_CHAR);
        doc_specialist = specification;
    }
    
    double Doctor::getSalary(int workedHours) const {

        double Salary = 0.0f;
        double hourlyRate = Employee::getHourlySalary();
        int MinNumHours = Employee::getMinWorkingHours();

        if(workedHours >= MinNumHours) {

            Salary = (hourlyRate * MinNumHours) + ((workedHours - MinNumHours) * (1.5 * hourlyRate));
        }
        else {
            Salary = workedHours * hourlyRate;
        }

        if (doc_specialist == true) {
            Salary += 2000.00;
        }

        return Salary;
    }
    
    ostream& Doctor::display(ostream& out) const {

        out << "Doctor" << endl;

        if (doc_specialist == false) {
            out << setw(16) << "Type: " << doc_type << endl;
        }
        else {
            out << setw(16) << "Type: " << doc_type << " (specialist)" << endl;
        }

        out << setw (16) << "Pay Rate: " << getHourlySalary() << endl;
        out << setw (16) << "Min Hours: " << getMinWorkingHours() << endl;

        return out;
    }
}
