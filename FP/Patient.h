// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
using namespace std;
namespace sdds {
	class Patient : public IOAble
	{
		char* m_name;
		int m_ohip;
		Ticket m_ticket = 0;
		bool m_file;

	public:
		Patient();
		Patient(int i = 0, bool f = false);
		~Patient();
		Patient(Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool a);
		bool operator==(char a) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		ostream& csvWrite(ostream& os) const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
	};

}
#endif // !SDDS_PATIENT_H_


