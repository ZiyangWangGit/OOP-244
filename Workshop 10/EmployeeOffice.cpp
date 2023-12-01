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
#include <iomanip>
#include <cstring>
using namespace std;
#include "EmployeeOffice.h"
namespace sdds {
    EmployeeOffice::EmployeeOffice(const char* name, int office) {
        strcpy(m_name, name);
        m_office = office;
    }
    ostream& EmployeeOffice::display(ostream& os)const {
        return os << m_name << " (Office# " << m_office << ")";
    }
    bool EmployeeOffice::operator==(int office)const {
        return m_office == office;
    }
}