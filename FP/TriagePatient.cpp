// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>

using namespace std;
namespace sdds {
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{ 
		m_symptoms = nullptr;
		nextTriageTicket = nextTriageTicket + 1;
	}

	ostream& TriagePatient::csvWrite(ostream& os) const
	{
		Patient::csvWrite(os);
		os << ',' << m_symptoms;
		return os;
	}

	istream& TriagePatient::csvRead(istream& istr)
	{
		delete[] m_symptoms;
		char temp[511];
		Patient::csvRead(istr);
		istr.ignore(511,',');

		istr.get(temp, 511, '\n');
		m_symptoms = new char[strlen(temp) + 1];
		strcpy(m_symptoms, temp);
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}
	ostream& TriagePatient::write(ostream& os) const
	{
		if (fileIO())
		{
			csvWrite(os);
		}
		else
		{
			os << "TRIAGE" << endl;
			Patient::write(os) << endl;
			os << "Symptoms: ";
			os << m_symptoms << endl;
		}
		return os;
	}

	istream& TriagePatient::read(istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptoms;
			char temp[511];
			Patient::read(istr);
			cout << "Symptoms: ";
			istr.ignore(511, '\n');
			istr.getline(temp, 511, '\n');;
			m_symptoms = new char[strlen(temp) + 1];
			strcpy(m_symptoms, temp);

		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

}