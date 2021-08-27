//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Date:           31-05-2020

#include "Marks.h"
#include "Utils.h"
#include <sstream>
#include <ctype.h>
#include <iomanip>

namespace sdds {
    void markstat() {
        char assessmentName[MAX_LEN];
        int totalMarks;
        Mark* grade = nullptr;

        cout << "Mark Stats Program.\n\n";
        cout << "Please enter the assessment name: "; //printing assessment name 
        cin.getline(assessmentName, 40);
        cout << "Please enter the number of marks: "; //Asking for the number of marks
        totalMarks = getInt("", 5, 50, "Invalid value (5 <= value <= 50), try again: ");

        cout << "Please enter " << totalMarks << " marks (0<=Mark<=100)" << endl; //Asking the new mark depending on Mark 
        grade = new Mark[totalMarks];    
        for (int i = 0; i < totalMarks; i++) {
            cout << i + 1 << "> ";
            grade[i].no = getInt("", 0, 100, "Invalid value(0 <= value <= 100), try again: ");
        }
        cout << "Thank you...";
        cout << endl << "Assessment Name: " << assessmentName << endl;
        cout << "------------------------" << endl;

        int total = 0;
        int pass = 0;
        int count;
        for (int i = 0; i < totalMarks; i++) {
            for (int j = i + 1; j < totalMarks; j++) {
                if (grade[i].no < grade[j].no) {
                    count = grade[i].no;
                    grade[i].no = grade[j].no;
                    grade[j].no = count;
                }
            }
            cout << grade[i].no;
            if (i + 1 < totalMarks) {
                cout << ",";
            }
        }

        for (int i = 0; i < totalMarks; i++) {
            total = total + grade[i].no;
            if (grade[i].no >= 50) {
                pass++;
            }
        }
        cout << setprecision(1) << fixed;
        cout << endl << "Average: " << total / (double)totalMarks << endl;
        cout << "Number of Passing Marks: " << pass << endl;
        delete[] grade;
        grade = nullptr;
    }
}