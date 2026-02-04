// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& istr) const = 0;
		virtual istream& csvRead(istream& istr) = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& istr) = 0;
		virtual ~IOAble() { };
	};

	ostream& operator<<(std::ostream& os, const IOAble& I);
	istream& operator>>(std::istream& istr, IOAble& I);
}
#endif // !SDDS_IOABLE_H_
