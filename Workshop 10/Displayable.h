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
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class Displayable {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
    };
    std::ostream& operator<<(std::ostream& os, const Displayable& c);
}
#endif // !SDDS_READWRITE_H_