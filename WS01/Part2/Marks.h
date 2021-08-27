//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Date:           31-05-2020

#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H
#include <iostream>
using namespace std;

namespace sdds {
    void markstat();
        //takeNum declaration changing
        bool takeNum(string strNum, int& num, string & errorMsg);

    //This will ask the user for mark depending on the min or max
    int getInt(string prompt, int min, int max, string errorPrompt);

    struct Mark {
        int no;
    };

    const int MAX_NUM = 50;
    const int MAX_LEN = 40;
}
#endif