// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Time.h"
#include "utils.h"
#include <iostream>
using namespace std;
namespace sdds {


	Time& Time::reset()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		if ((min == 0) && !(isdigit(min))) {
			m_min = 0;
		}
		else {
			m_min = min;
		}
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int tempHour = 0;
		int tempMin = 0;
		tempHour = m_min / 60;
		tempMin = m_min - (tempHour * 60);
		ostr.fill('0');
		ostr.width(2);
		ostr << tempHour;
		ostr << ":";
		ostr.width(2);
		ostr << tempMin;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int tempHour = 0, tempMin = 0;
		char c = 'z';
		istr >> tempHour >> c >> tempMin;
		if (c == ':')
		{
			m_min = tempHour * 60 + tempMin;
		}
		else
		{
			istr.setstate(ios::failbit);
		}
		return istr;
	}

	Time::operator int()const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		m_min = m_min * val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min > D.m_min)
		{
			m_min = m_min - D.m_min;
		}
		else
		{
			m_min = (m_min + 1440) - D.m_min;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const Time& T)
	{
		return T.write(os);
	}

	istream& operator>>(istream& istr, Time& T)
	{
		return T.read(istr);
	}
	Time Time::operator-(const Time& ROperand) {
		Time LOperand = *this;
		LOperand -= ROperand;
		return LOperand;
	}
}