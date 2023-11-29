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
#include "LblShape.h"

namespace sdds {
	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		if (label != nullptr){
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
		else {
			m_label = nullptr;
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	const char* LblShape::label() const {
		return m_label;
	}

	void LblShape::getSpecs(std::istream& istr) {
		char buffer[charSize];
		istr.getline(buffer, charSize, ',');

		delete[] m_label;

		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);
	}

}