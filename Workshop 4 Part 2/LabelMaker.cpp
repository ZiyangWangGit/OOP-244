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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "LabelMaker.h"
#include "Label.h"


using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		numberOfLabels = noOfLabels;
		array = new char* [numberOfLabels];
		for (int i = 0; i < numberOfLabels; i++) {
			array[i] = nullptr;
		}
		frame = new char[strlen("+-+|+-+|")+1];
		strcpy(frame, "+-+|+-+|");
	}

	LabelMaker::~LabelMaker() {
		for (int i = 0; i < numberOfLabels; i++) {
			delete array[i];
		}
		delete[] array;
		delete[] frame;
	}

	void LabelMaker::readLabels() {

		char userinput[contentSize];

		cout << "Enter " << numberOfLabels << " labels:" << endl;

		for (int i = 0; i < numberOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			cin.getline (userinput, contentSize);
			array[i] = new char[strlen(userinput) + 1];
			strcpy(array[i], userinput);

		}
	}

	void LabelMaker::printLabels() {
		
		for (int i = 0; i < numberOfLabels; i++) {
			int contentLength = strlen(array[i]);

			std::cout << frame[0];       //top line
			for (int j = 0; j < contentLength + 2; j++) {
				std::cout << frame[1];
			}
			std::cout << frame[2] << std::endl;

			std::cout << frame[7]; //second line
			cout.width(contentLength + 3);
			std::setfill(' ');
			std::cout << frame[3] << std::endl;

			std::cout << frame[7] << " " << array[i] << " " << frame[3] << std::endl;//third line

			std::cout << frame[7];//fourth line
			cout.width(contentLength + 3);
			std::setfill(' ');
			std::cout << frame[3] << std::endl;

			std::cout << frame[6];//last line
			for (int j = 0; j < contentLength + 2; j++) {
				std::cout << frame[5];
			}
			std::cout << frame[4] << std::endl;
		}
	}
}