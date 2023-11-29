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
#include "Shape.h"

using namespace std;
namespace sdds {
	Shape::~Shape() {}
	
	ostream& operator<<(ostream& ostr, const Shape& shape){
		shape.draw(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
}