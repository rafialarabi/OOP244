//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Date:           28-05-2020

#ifndef SDDS_UTILSS_H
#define SDDS_UTILSS_H

namespace sdds {
	char ToLower(char ch);
	int StrCmp(const char* s1, const char* s2);
	void StrCpy(char* des, const char* src);
	int StrLen(const char* str);
	bool isAlpha(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif