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
#ifndef SDDS_CONTAINER_H_
#define SDDS_CONTAINER_H_

#include <iostream>

namespace sdds {
	const int maxChar = 50;
	const int maxValue = 220000;
	const int minValue = 1;

	class Container {
		char content[maxChar+1];
		int capacity;
		int contentVolume;

	protected:
		void setEmpty();
		int contentCapacity()const;
		int volume()const;

	public:
		Container(const char* description, int maxCapacity, int volume = 0);
		int operator+=(int num);
		int operator -=(int num);
		operator bool() const;
		void clear(int capacity,const char* description);
		std::ostream& print (std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Container& contain);
	std::istream& operator>>(std::istream& istr, Container& contain);
}
#endif
