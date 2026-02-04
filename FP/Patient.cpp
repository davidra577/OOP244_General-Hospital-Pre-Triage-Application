// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds {

	Patient::Patient()
	{
		m_name = nullptr;
		m_ohip = 0;
		m_file = true;
		m_ticket = Ticket(0);
	}

	Patient::Patient(int i, bool f)
	{
		m_name = nullptr;
		m_ohip = 0;
		m_file = f;
		m_ticket = Ticket(i);
	}

	Patient::~Patient()
	{
		delete[] m_name;
	}

	bool Patient::fileIO() const
	{
		return m_file;
	}

	void Patient::fileIO(bool a)
	{
		m_file = a;
	}

	bool Patient::operator==(char a) const
	{
		bool ok = false;
		if (type() == a)
		{
			ok = true;
		}
		return ok;
	}

	bool Patient::operator==(const Patient& p) const
	{
		bool ok = false;
		if (this->type() == p.type())
		{
			ok = true;
		}
		return ok;
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& os) const
	{
		os << type() << "," << m_name << "," << m_ohip << ",";
		m_ticket.csvWrite(os);
		return os;
	}
	istream& Patient::csvRead(istream& istr)
	{
		char temp[51];
		delete[] m_name;
		int tempNum = 0;
		istr.get(temp, 51, ',');
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);
		istr.ignore(256, ',');
		istr >> tempNum;
		m_ohip = tempNum;
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;

	}

	ostream& Patient::write(ostream& os) const
	{
		m_ticket.write(os) << endl;
		os << m_name << ", OHIP: " << m_ohip;
		return os;
	}
	istream& Patient::read(istream& istr)
	{
		char temp[51];
		bool ok = false;
		delete[] m_name;
		int tempNum = 0;
		cout << "Name: ";
		istr.getline(temp, 51, '\n');
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);
		cout << "OHIP: ";
		while (!ok)
		{
			if (istr >> tempNum)
			{
				if (tempNum >= 100000000 && tempNum <= 999999999)
				{
					m_ohip = tempNum;
					ok = true;
				}
				else
				{
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				}
			}
			else
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		return istr;
	}

	Patient::operator Time() const
	{
		return m_ticket.operator sdds::Time();
	}
}