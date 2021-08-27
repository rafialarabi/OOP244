//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Date:           28-05-2020

#ifndef SDDS_WORD_H
#define SDDS_WORD_H

	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;
	const int SORT_BY_OCCURANCE = 1;
	const int SORT_ALPHABETICALLY = 0;

namespace sdds {

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word words[], int num, const char word[]);
	void addWord(Word words[], int* index, const char newWord[]);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, bool gotoNextLine, int len);
	int findMaxLen(const Word words[], int noOfWords);
	void listWords(const Word words[], int noOfWords, const char* theTitle);
	void swap(Word* p1, Word* p2);
	void sort(Word words[], int cnt, int sortType);
	int totalCount(const Word* words, int num);
	void wordStats();
	void programTitle();
}
#endif