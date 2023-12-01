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
#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds {
    class Student : public Displayable {
        int m_stno{};
        char m_name[41]{};
        double m_gpa{};
    public:
        Student() = default;
        Student(int stno, const char* name, double gpa);
        std::ostream& display(std::ostream& os)const;
        bool operator==(double gpa)const;
    };
}
#endif // !SDDS_STUDENT_H_