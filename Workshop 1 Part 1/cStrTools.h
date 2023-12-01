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

#ifndef SDDS_CSTRTOOLS_H 
#define SDDS_CSTRTOOLS_H


namespace sdds {

	char toLower(char ch);	                                  // returns the lower case value of a character

	int strCmp(const char* s1, const char* s2);	              // compares s1 and s2 cStrings and returns

	int strnCmp(const char* s1, const char* s2, int len);     // compares s1 and s2 cStrings upto len characters and returns

	
	const char* strStr(const char* str, const char* find);    // if "find" is found in "str" it will return the addres of the match
	
	                                                          // if not found it will returns nullptr (zero)
	void strCpy(char* des, const char* src);                  // copies src to des

	int strLen(const char* str);                              // returns the length of str

	int isAlpha(char ch);                                     // returns true if ch is alphabetical
	
	int isSpace(char ch);                                     // returns true if ch is a whitespace character
	
	void trim(char word[]);                                   //removes the non-alphabetic characters from the begining and end of a word

	void toLowerCaseAndCopy(char des[], const char source[]);// copies the  lower case version of the source into des

}
#endif
