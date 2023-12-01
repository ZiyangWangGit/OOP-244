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
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"
namespace sdds {
    class EmployeeOffice : public Displayable {
        int m_office{};
        char m_name[41]{};
    public:
        EmployeeOffice() = default;
        EmployeeOffice(const char* name, int office);
        std::ostream& display(std::ostream& os)const;
        bool operator==(int office)const;
    };


}
#endif // !SDDS_EMPLOYEE_H_