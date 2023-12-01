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
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;
    const int miniFuelForEach = 600;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;

        operator bool() const;                    //True,if m_passengers > 0 and m_fuel >= (m_passengers * miniFuelForEach)otherwise false.
        operator int()const;                      //Returns the Flight number of passengers
        operator double()const;                   //Returns the Flight Fuel
        operator const char*()const;              //Returns the Flight Title

        bool operator~ () const;                  //true if the Flight number of passengers is equal to 0, otherwisefalse. 

        Flight& operator=(Flight& Roperand);           
        Flight& operator=(const int flightMember);     
        Flight& operator=(const double flightfuel);    
        Flight& operator+=(double flightfuel);         
        Flight& operator+=(int passenger);
        Flight& operator-=(double flightfuel);
        Flight& operator-=(int passenger);
        Flight& operator >>(Flight& Roperand);

        int operator+(const Flight& other) const;

       

    };
    int operator+=(int& number, const Flight&);
    

}
#endif // SDDS_FLIGHT_H
