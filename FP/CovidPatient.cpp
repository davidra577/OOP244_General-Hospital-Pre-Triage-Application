// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;


   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket = nextCovidTicket + 1;
   }

   ostream& CovidPatient::csvWrite(ostream& os) const
   {
	   Patient::csvWrite(os);
	   return os;
   }

   istream& CovidPatient::csvRead(istream& istr)
   {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   return istr;
   }

   ostream& CovidPatient::write(ostream& os) const
   {
	   if (fileIO())
	   {
		   csvWrite(os);
	   }
	   else
	   {
		   os << "COVID TEST" << endl;
		   Patient::write(os) << endl;
	   }
	   return os;
   }

   istream& CovidPatient::read(istream& istr)
   {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }
	   return istr;
   }

}