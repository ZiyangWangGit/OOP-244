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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Displayable.h"
namespace sdds {
    class Car : public Displayable {
        char m_plate[9]{};
        char m_makeModel[41]{};
    public:
        Car() = default;
        Car(const char* plate, const char* makeModel);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* mmSubstr)const;
    };


}
#endif // !SDDS_CAR_H_