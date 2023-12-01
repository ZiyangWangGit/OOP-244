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

#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include "Label.h"

using namespace std;
namespace sdds {
	void  Label::frameInfo(const char* frameArg) {
		if (frameArg != nullptr) {
			frame = new char[frameSize];
			strncpy(frame, frameArg, frameSize);
			labelContent = nullptr;
		}
		else {
			this->frame = new char[strlen("+-+|+-+|") + 1];
			strcpy(this->frame, "+-+|+-+|");
			labelContent = nullptr;
		}
	}

	void Label::contentInfo(const char* contentArg) {
		if (contentArg != nullptr) {
			this->labelContent = new char[contentSize];
			strncpy(this->labelContent, contentArg,contentSize);
		}
	}

	Label::Label() {
		frameInfo(nullptr);
	}

	Label::Label(const char* frameArg) {
		frameInfo(frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {
		frameInfo(frameArg);
		contentInfo(content);
	}

	Label::~Label() {
		delete[] frame;
		delete[] labelContent;
	}

	istream& Label::readLabel() {
		std::cin.getline(labelContent, contentSize);
		return std::cin;
	}

	std::ostream& Label::printLabel()const {
		if (labelContent != nullptr) {
			int contentLen = strlen(labelContent);

			std::cout << frame[0];       //top line
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << frame[1];
			}
			std::cout << frame[2] << std::endl;

			std::cout << frame[7]; //second line
			cout.width(contentLen + 3);
			std::setfill(' ');
			std::cout << frame[3] << std::endl;

			std::cout << frame[7] << " " << labelContent << " " << frame[3] << std::endl;//third line

			std::cout << frame[7];//fourth line
			cout.width(contentLen + 3);
			std::setfill(' ');
			std::cout << frame[3] << std::endl;

			std::cout << frame[6];//last line
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << frame[5];
			}
			std::cout << frame[4];
		}
		return std::cout;
	}

	Label& Label::text(const char* content) {
		contentInfo(content);
		return *this;
	}
}