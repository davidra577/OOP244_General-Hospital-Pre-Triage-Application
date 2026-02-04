// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>

using namespace std;
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& ROperand);
    };
    // helper operator << and >> prototypes
    istream& operator>>(istream& istr, Time& T);
    ostream& operator<<(ostream& os, const Time& T);
}

#endif // !SDDS_TIME_H

