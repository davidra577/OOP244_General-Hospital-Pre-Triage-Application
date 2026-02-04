// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "Patient.h"
#include "Menu.h"
namespace sdds {
   const int maxNoOfPatients = 100;
   class PreTriage {
      Time 
         m_averCovidWait, 
         m_averTriageWait;
      Patient* m_lineup[maxNoOfPatients]{};
      char* m_dataFilename{};
      int m_lineupSize = 0;
      Menu m_appMenu, m_pMenu;
      void reg();
      void admit();
      const Time getWaitTime(const Patient& p)const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      void load();
      int indexOfFirstInLine(char type) const;
   public:
       PreTriage(const char* dataFilename);
      ~PreTriage();
      void run(void);
   };
}
#endif // !SDDS__H_
