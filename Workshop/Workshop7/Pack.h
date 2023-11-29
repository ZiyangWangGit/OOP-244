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
#ifndef SDDS_PACK_H_
#define SDDS_PACK_H_

#include <iostream>
#include "Container.h"

namespace sdds {

	class Pack : public Container{
		int unitSize;

	public:
		Pack(const char* description,int maxUnits,int unitSize = 330,int units = 0);
		int operator +=(int num);
		int operator -=(int num);
		int unit()const;
		int noOfUnits()const;
		int size()const;
		void clear(int packSize,int unitSize,const char* description);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);
}

#endif
