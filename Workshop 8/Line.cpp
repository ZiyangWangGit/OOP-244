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
#include <sstream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line() {
		m_length = 0;
	}

	Line::Line(const char* label, int length): LblShape(label) {
		m_length = length;
	}

	Line::~Line() {}

	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);  // Call the function from the base class
		char lengthValue[charSize];
		istr.getline(lengthValue, charSize, '\n');
		m_length = stoi(lengthValue);
	}


	void Line::draw(std::ostream& ostr) const {
		if (m_length > 0 && label()) {
			ostr << label() << endl;
			for (int i = 0; i < m_length; ++i) {
				ostr << "=";
			}
		}
		
	}
}