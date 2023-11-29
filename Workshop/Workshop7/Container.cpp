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
#include <string>
#include "Container.h"


using namespace std;
namespace sdds {

	Container::Container(const char* description, int maxCapacity, int volume) {
		if (description == nullptr || volume > maxCapacity) {
			setEmpty();
		}
		else {
			strncpy(content, description, maxChar);
			content[50] = '\0';
			capacity = maxCapacity;
			contentVolume = volume;
		}
	}

	void Container::setEmpty() {
		content[0] = '\0';
		capacity = 0;
		contentVolume = 0;
	};

	int Container::contentCapacity()const{
		return capacity;
	};

	int Container::volume()const {
		return contentVolume;
	}

	int Container:: operator+=(int num) {
		int numAdded;
		if ((num + contentVolume) <= capacity) {
			numAdded = num;
			contentVolume += num;
		}
		else {
			numAdded = capacity - contentVolume;
			contentVolume = capacity;
		}
		return numAdded;
	}

	int Container::operator -=(int num) {
		int numDeducted;
		if ((contentVolume - num) >= 0) {
			numDeducted = num;
			contentVolume -= num;
		}
		else {
			numDeducted = contentVolume;
			contentVolume = 0;
		}	
		return numDeducted;
	}

	Container:: operator bool() const {
		return (content[0] != '\0' && contentVolume <= capacity);
	}

	void Container::clear(int newCapacity, const char* description) {
		if (newCapacity >= 0 && description != nullptr) {
			capacity = newCapacity;
			strncpy(content, description, maxChar);
			content[50] = '\0';
		}
	}
	
	ostream& Container::print(ostream& ostr) const{
		if (*this) {
			ostr << content << ": (" << contentVolume << "cc/" << capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	istream& Container::read(istream& istr) {
		int userInput;
		bool control = false;

		if (!(*this)) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.get();
			istr.ignore(1000, '\n');
		}
		else{
			do {
				cout << "Add to ";
				print(std::cout);
				cout << endl << "> ";
				istr >> userInput;
				if (istr.fail()) {
					cout << "Invalid Integer, retry: ";
					istr.clear();
					istr.ignore(1000, '\n');
				}
				else if (userInput > maxValue || userInput < minValue) {
					cout << "Value out of range [1<=" << userInput << " <=" << maxValue << "]: ";
				}
				else {
					int volumeAdded = *this += userInput;
					cout << "Added " << volumeAdded << " CCs" << endl;
					control = true;
				}
			} while (control == false);
		}
		return istr;
	}

	ostream& operator<<(ostream& ostr, const Container& contain) {
		contain.print(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Container& contain) {
		contain.read(istr);
		return istr;
	}

}