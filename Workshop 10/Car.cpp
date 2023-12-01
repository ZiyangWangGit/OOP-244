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
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds {
    Car::Car(const char* plate, const char* makeModel) {
        strncpy(m_plate, plate, 8);
        m_plate[8] = 0;
        strncpy(m_makeModel, makeModel, 40);
        m_makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << m_plate << " " << m_makeModel;
    }
    bool Car::operator==(const char* mmSubstr)const {
        return strstr(m_makeModel, mmSubstr) != nullptr;
    }
}