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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

namespace sdds {
	class Student {
		char* m_name;
		int m_age;
	public:
		Student();
		Student(const char* name,int age);
		virtual ~Student();
		Student(const Student&);
		Student& operator = (const Student&);
		void display()const;
	};

}


#endif