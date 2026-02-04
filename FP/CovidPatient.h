// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		virtual char type() const {
			return 'C';
		}
		
		ostream& csvWrite(ostream& os) const ;
		istream& csvRead(istream& istr) ;
		ostream& write(ostream& os) const ;
		istream& read(istream& istr) ;
	};
}
#endif // !SDDS_COVIDPATIENT_H_



