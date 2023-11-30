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
#ifndef SDDS_GRADUATE_H_
#define SDDS_GRADUATE_H_

namespace sdds {
	class Graduate :public Student {
		char* m_supName;
		char* m_title;
	public:
		Graduate() : m_supName(nullptr), m_title(nullptr) {}
		Graduate(const char* studentName, int studentAge, const char* title, const char* supervisor);
		virtual ~Graduate();
		Graduate(const Graduate&);
		Graduate& operator = (const Graduate&);
		void display()const;
	};

}
#endif
