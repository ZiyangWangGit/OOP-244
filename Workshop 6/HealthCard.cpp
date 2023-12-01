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
#include <cstring>
#include "HealthCard.h"


using namespace std;
namespace sdds {

	HealthCard::HealthCard() {
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	};

	HealthCard::HealthCard(const char* m_name, long long m_number, const char vCode[], const char sNumber[]) {
		set(m_name, m_number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {
		if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			allocateAndCopy(hc.m_name);
			m_number = hc.m_number;
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
		}
	};

	HealthCard::~HealthCard() {
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
	}

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		return (name != nullptr && strlen(name) > 0 &&
			number >= 1000000000LL && number <= 9999999999LL &&
			strlen(vCode) == 2 && strlen(sNumber) == 9);
	}

	void HealthCard::setEmpty() {	
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
	}

	void HealthCard::allocateAndCopy(const char* name) {
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = new char[strlen(name) + 1];
		if (name != nullptr) {
			strcpy(m_name, name);
		}
	}

	void HealthCard::extractChar(istream& istr, char ch) const {

		int next;
		next = istr.peek();
		if (next == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const {

		ostr << m_number << "-" << m_vCode << ", " << m_sNumber << endl;
		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			setEmpty();
		};
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {
			if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
				allocateAndCopy(hc.m_name);
				m_number = hc.m_number;
				strcpy(m_vCode, hc.m_vCode);
				strcpy(m_sNumber, hc.m_sNumber);
			}
			else {
				setEmpty();
			}
		}

		return *this;
	}

	HealthCard::operator bool()const {
		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const {
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << m_name << ",";
				printIDInfo(ostr);
			}
			else {
				ostr.width(toFileChar);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		char* name = new char[MaxNameLength + 1];
		long long number;
		char vCode[vCodeLength];
		char sNumber[sNumberLength];

		istr.get(name, MaxNameLength + 1, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, vCodeLength + 1, ',');
		extractChar(istr, ',');
		istr.get(sNumber, sNumberLength + 1, '\n');

		if (!istr.fail()) {
			set(name, number, vCode, sNumber);
		}
		else {
			setEmpty();
		}
		delete[] name;

		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}


	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, HealthCard& hc) {
		hc.read(istr);
		return istr;
	}

}