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


#include "Population.h"

using namespace sdds;

int main() {
    char code[arraySize]{};
    while (getPostalCode(code)) {
        if (load("PCpopulations.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}