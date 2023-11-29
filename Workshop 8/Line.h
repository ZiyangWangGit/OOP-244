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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include"LblShape.h"

namespace sdds {
	class Line : public LblShape {
	private:
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		~Line();
		void getSpecs(std::istream& istr) ;
		void draw(std::ostream& ostr) const;
	};
}
#endif
