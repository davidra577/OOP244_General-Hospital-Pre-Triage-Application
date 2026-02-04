// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const IOAble& I)
	{
		I.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& istr, IOAble& I)
	{
		I.read(istr);
		return istr;
	}
}