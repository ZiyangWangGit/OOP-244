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
#ifndef SDDS_PHONE_H 
#define SDDS_PHONE_H

const int MAX_NAME_LENGTH = 50;
const int MAX_PHONE_RECORD = 500;

namespace sdds {
	struct PhoneRecord {
		char name[MAX_NAME_LENGTH];
		char areaCode[4];
		char prefix[4];
		char number[5];
	};

	void phoneDir(const char* programTitle, const char* fileName);
	void inputName(const char* fileName);
	void searchByName(const char* inputName, const char* fileName);
}

#endif

