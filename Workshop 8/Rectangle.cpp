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
#include <sstream>
#include "Rectangle.h"
#include "LblShape.h"

using namespace std;
namespace sdds {
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {

		if (label != nullptr) {
			if (height < 3 || width < static_cast<int>(strlen(LblShape::label()) + 2)) {
				m_width = 0;
				m_height = 0;
			}
			else {
				m_width = width;
				m_height = height;
			}
		}
		else {
			m_width = 0;
			m_height = 0;
		}
	}

	Rectangle :: ~Rectangle() {}

	void Rectangle::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);

		char widthValue[charSize];
		istr.getline(widthValue, charSize, ',');
		m_width = stoi(widthValue);

		char heightValue[charSize];
		istr.getline(heightValue, charSize);
		m_height = stoi(heightValue);
	}

	void Rectangle::draw(std::ostream& ostr) const {
		if (m_width > 0 && m_height > 0 && label() != nullptr) {
			ostr << "+";
			for (int i = 0; i < static_cast<int>(m_width - 2); i++) {
				ostr << '-';
			}
			ostr << '+' << endl;

			ostr << "|";
			ostr.width(m_width - 2);
			ostr.setf(ios::left);
			ostr << label() << '|' << endl;
			
			if ((m_height - 3) >= 1) {
				for (int i = 1; i <= static_cast<int>(m_height - 3); i++) {
					ostr << "|";
					for (int i = 0; i < static_cast<int>(m_width - 2); i++) {
						ostr << ' ';
					}
					ostr << "|" << endl;
				}
			}

			ostr << "+";
			for (int i = 0; i < static_cast<int>(m_width - 2); i++) {
				ostr << '-';
			}
			ostr << '+';
		}
	}
}