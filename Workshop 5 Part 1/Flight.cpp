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
#include <cstring>
#include <iostream>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight :: operator bool()const {
        return m_passengers > 0 && m_fuel >= (m_passengers * miniFuelForEach);
    }

    Flight :: operator int()const {
        return m_passengers;
    }

    Flight :: operator double()const {
        return m_fuel;
    }

    Flight :: operator const char* ()const {
        return m_title;
    }

    bool Flight :: operator ~() const {
        return m_passengers == 0;
    }

    //overload the assignment operator so a  can be set to another Flight object.
    Flight& Flight::operator=(Flight& Roperand) {
        strcpy(m_title,Roperand.m_title);
        m_passengers=Roperand.m_passengers;
        m_fuel=Roperand.m_fuel;
        Roperand.emptyPlane();

        return *this;
    }


    //Flight&: This specifies the return type of the overloaded assignment, will return a reference to a Flight object.
    Flight& Flight::operator = (const int flightMember) {   
        if (flightMember >= 0 && flightMember <= Boen747Capacity) {
            m_passengers = flightMember;
        }
        return *this;
    }

    Flight& Flight:: operator=(const double flightfuel) {
        if (flightfuel > 0 && flightfuel < FuelTankCapacity) {
            m_fuel = flightfuel;
        }
        return *this;
    }
 
    Flight& Flight::operator+=(double flightfuel) {
        if (flightfuel > 0 && m_fuel < FuelTankCapacity) {
            if ((flightfuel + m_fuel) > FuelTankCapacity) {
                flightfuel -= (FuelTankCapacity - m_fuel);
                m_fuel = FuelTankCapacity;
            }
            else {
                m_fuel += flightfuel;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(int passenger) {
        if (passenger > 0 && m_passengers < Boen747Capacity) {
            if ((m_passengers + passenger) > Boen747Capacity) {
                passenger -= (Boen747Capacity - m_passengers);
                m_passengers = Boen747Capacity;
            }
            else {
                m_passengers += passenger;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double flightfuel) {
        if (flightfuel > 0 && m_fuel > 0) {
            if ((m_fuel - flightfuel) < 0) {
                flightfuel -= (flightfuel - m_fuel);
                m_fuel = 0;
            }
            else {
                m_fuel -= flightfuel;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(int passenger) {
        if (passenger > 0 && m_passengers > 0) {
            if ((m_passengers - passenger) < 0) {
                passenger -= (passenger - m_passengers);
                m_passengers = 0;
            }
            else {
                m_passengers -= passenger;
            }
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& Roperand) {
        if (!(~*this) && !(~Roperand)) { 
            if ((m_passengers + Roperand.m_passengers) > Boen747Capacity) {
                m_passengers -= (Boen747Capacity - Roperand.m_passengers);
                Roperand.m_passengers = Boen747Capacity;                
            }
            else {
                Roperand.m_passengers += m_passengers;
                m_passengers = 0;
            }
        }
        return *this; 
    }

    //oneFlight + anotherFlight
    //oneFlight.operator + (anotherFlight)
    int Flight :: operator+(const Flight& another) const {
        int totalpassenger = 0;
        if (~*this || ~another) { 
                totalpassenger = 0;
        }
        else {
            totalpassenger = m_passengers + another.m_passengers;
        }
        return totalpassenger;
    }

    int operator+=(int& number, const Flight& other) {
        number += int(other);
        return number;
    }
}   