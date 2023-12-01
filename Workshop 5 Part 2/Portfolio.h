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
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void emptyPortfolio();
        void dispPortfolio() const;
        std::ostream& display() const;

        operator double()const;            //result would be the value of the Portfolio m_value
        operator const char* ()const;      //result would be the name of the stock m_stock
        operator char()const;              //result would be the type of investment m_type
        operator bool()const;              //return TRUE if the type of the investment m_type is Growth 'G' or Value 'V or Investment 'I'

        Portfolio& operator+=(double value);        
        Portfolio& operator-=(double value);
        bool operator ~()const;
        Portfolio& operator << (Portfolio& rOperand);
        Portfolio& operator >> (Portfolio& rOperand);
    };
    double operator+(const Portfolio& lOperand, const Portfolio& rOperand);
    double operator+=(double& value, const Portfolio& rOperand);
}
#endif // SDDS_Portfolio_H_