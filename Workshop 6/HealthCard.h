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
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>

namespace sdds {
    const int toFileChar = 50;
    const int MaxNameLength = 55;
    const int vCodeLength = 3;
    const int sNumberLength = 10;
    const int defaultNumber = 0;

    class HealthCard {
        char* m_name{};
        long long m_number;
        char m_vCode[vCodeLength];
        char m_sNumber[sNumberLength];
    public:
        HealthCard();
        HealthCard(const char* m_name, long long m_number = defaultNumber,
            const char vCode[] = "", const char sNumber[] = "");
        HealthCard(const HealthCard& hc);
        ~HealthCard();
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(std::istream& istr, char ch) const;
        std::ostream& printIDInfo(std::ostream& ostr) const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

        HealthCard& operator=(const HealthCard& hc);
        operator bool()const;
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        std::istream& read(std::istream& istr);

    };
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
    std::istream& operator>>(std::istream& istr, HealthCard& hc);

}


#endif
