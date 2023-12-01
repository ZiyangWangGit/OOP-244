/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP244
*

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SDDS_WORD_H 
#define SDDS_WORD_H

#include <cstring>
#include <cctype>
#include <iostream>


const int MAX_WORD_LEN = 21;


namespace sdds {
	
	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};
	
	int searchWords(const Word words[], int num, const char word[]);             //return the index from an arry if a word match found,otherise return -1

	int readWord(char* word, FILE* fptr, int maxLen);                            //reads characters from a file,return true if word successfully read
	
	void addWord(Word words[], int* index, const char newWord[]);                //add new word to an array

	void title(const char* value, int len);                                      //display a formatted table

	void endList();                                                              //display dashes to indicate it is the ned of list

	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);       //display the number of words information

	void print(const Word* w, int gotoNextLine, int len);                        //display data from Word structure

	int findMaxLen(const Word words[], int noOfWords);                           //find the longest word in an array 

	void listWords(const Word words[], int noOfWords, const char* theTitle);     //display list of words

	void swap(Word* p1, Word* p2);                                               //swap two words

	void sort(Word words[], int cnt, int sortType);                              //sort an array of Word structure

	int totalCount(const Word* words, int num);                                  //return total number of words in array of Word structure

	void wordStats(const char* filename);                                        //provide word statistics from a text file

	void programTitle();                                                         //display program title
}

#endif
