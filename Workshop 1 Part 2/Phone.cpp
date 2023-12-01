//*****************************************************************************
//<assessment name example : Workshop1 Part2
//  Full Name : Ziyang Wang
//  Student ID# : 154296222
//	Email : zwang331@myseneca.ca
//	Section : OOP244 NBB
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include"Phone.h"
#include"cStrTools.h"



using namespace std;
namespace sdds {

	void phoneDir(const char* programTitle, const char* fileName) {
		cout << programTitle << " phone direcotry search" << endl
			<< "-------------------------------------------------------" << endl;

		if (strCmp(fileName, "phones.txt") == 0) {

			inputName(fileName);
		}
		else {
			cout << fileName << " file not found!" << endl
				<< "Thank you for using " << programTitle << " directory." << endl;

		}
	}

	void inputName(const char* fileName) {

		int i = 1;
		do {
			char partialInput[MAX_NAME_LENGTH];

			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl
				<< "> ";
			cin >> partialInput;

			if (strCmp(partialInput, "!") == 0) {
				cout << "Thank you for using Star Wars directory." << endl;
				i = 0;
			}
			else {
				searchByName(partialInput, fileName);
			}
		} while (i == 1);
	}

	void searchByName(const char* inputName, const char* fileName) {
		if (strlen(inputName) > MAX_NAME_LENGTH) {
			cout << "You have exceeded the maximum word limit,please try again." << endl;
		}
		else if (!isAlpha(*inputName)) {
			cout << "Please enter alphabet letters." << endl;
		}
		else {
			PhoneRecord record;
			FILE* fptr = fopen(fileName, "r");
			if (fptr != NULL)
			{

				char lowercaseInput[MAX_NAME_LENGTH];
				toLowerCaseAndCopy(lowercaseInput, inputName);

				while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", record.name, record.areaCode,
					record.prefix, record.number) == 4) {
					char lowercaseName[MAX_NAME_LENGTH];
					toLowerCaseAndCopy(lowercaseName, record.name);

					if (strstr(lowercaseName, lowercaseInput) != NULL) {
						cout << record.name << ": (" << record.areaCode << ") " << record.prefix << "-" << record.number << endl;
					}
				}
				fclose(fptr);
				fptr = NULL;
			}
		}
	}
}

