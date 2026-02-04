// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
   class TriagePatient : public Patient {
	   char* m_symptoms;
   public:
	   TriagePatient();
	   virtual char type() const {
		   return 'T';
	   }

	   ostream& csvWrite(ostream& os) const;
	   istream& csvRead(istream& istr);
	   ostream& write(ostream& os) const;
	   istream& read(istream& istr);
	   ~TriagePatient();
   };

}
#endif // !SDDS_


