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
#include <string>
#include "Pack.h"

using namespace std;
namespace sdds {
	Pack::Pack(const char* description, int maxUnits, int singleUnitSize, int units):
		Container(description, maxUnits* singleUnitSize,singleUnitSize * units){

		if (singleUnitSize > 0) {
			unitSize = singleUnitSize;
		}
		else {
			unitSize = 0;
			setEmpty();
		}	
	}

	int	Pack ::operator +=(int num) {
		int numAdded = Container :: operator += (num * unitSize);
		return (numAdded / unitSize);
	}

	int Pack :: operator -= (int num) {
		int numDeducted = Container :: operator -= (num * unitSize);
		return (numDeducted / unitSize);
	}

	int Pack::unit()const{
		return unitSize;
	}

	int Pack::noOfUnits ()const {
		int contentVolume = volume();
		return (contentVolume / unitSize);
	}

	int Pack::size()const {
		int capacity = contentCapacity();
		return(capacity / unitSize);
	}

	void Pack::clear(int packSize, int unitSize, const char* description) {
		if (unitSize > 0) {
			Container::clear(packSize * unitSize,description);
			this -> unitSize = unitSize;
		}
	}

	ostream& Pack::print(ostream& ostr) const {
		Container::print(ostr);
		if(this){
		ostr << ", " << noOfUnits() << " in a pack of " << size();
		}		
		return ostr;
	}

	istream& Pack::read(istream& istr) {
		int userInput;
		bool control = false;
		if (!(*this)) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.get();
		}
		else {
			if (noOfUnits() >= size()) {
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.get();
				istr.ignore(1000, '\n');
			}
			else {
					cout << "Add to ";
					print(std::cout);
					cout << endl << "> ";
					do {
						istr >> userInput;
						if (istr.fail()) {
							cout << "Invalid Integer, retry: ";
							istr.clear();
							istr.ignore(1000, '\n');
						}
						else if ((userInput + noOfUnits()) > (size())) {
							cout << "Value out of range [1<=val<=" << (size() - noOfUnits()) << "]: ";
						}
						else {
							int numAdded = *this += userInput;
							cout << "Added " << numAdded << endl;
							control = true;
						}
				} while (control == false);
			}

		}
		return istr;
	}

	ostream& operator<<(ostream& ostr, const Pack& pack) {
		pack.print(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Pack& pack) {
		pack.read(istr);
		return istr;
	}

}