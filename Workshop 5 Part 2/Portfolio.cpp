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
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio:: operator double()const {
        return m_value;
    }

    Portfolio::operator const char* ()const {
        return m_stock;
    }

    Portfolio::operator char()const {
        return m_type;
    }

    Portfolio::operator bool()const {
        return (m_type == 'G' || m_type == 'I' || m_type == 'V'); //return TRUE if the type of the investment m_type is Growth 'G' or Value 'V or Investment 'I'
    }

    Portfolio& Portfolio::operator+=(double value) {
        if ((*this) && value > 0) {
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double value) {
        if ((*this) && value > 0) {
            m_value -= value;
        }
        return *this;
    }

    bool Portfolio::operator ~()const {
        return (m_value < 0);
    }

    Portfolio& Portfolio::operator << (Portfolio& rOperand) {
        m_value += rOperand.m_value;
        rOperand.emptyPortfolio();

        return *this;
    }

    Portfolio& Portfolio::operator >> (Portfolio& rOperand) {
        if ((*this) && rOperand) {              //check If any of the two portfolios don't evaluate to TRUE
            rOperand.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    double operator+(const Portfolio& lOperand,const Portfolio& rOperand) {
        if ((lOperand) && (rOperand)) {
            return double(lOperand) + double(rOperand);
        }
        else {
            return 0.0;
        }
    }

    double operator+=(double& value, const Portfolio& rOperand) {
        value += double(rOperand);
        return value;
    }
}
