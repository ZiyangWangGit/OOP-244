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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds {
	const int charSize = 1000;
	class LblShape : public Shape {
	private:
		char* m_label;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&) = delete; 
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream& istr);




	};

}
#endif