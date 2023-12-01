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
#include "Displayable.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const Displayable& c) {
        return c.display(os);
    }
}