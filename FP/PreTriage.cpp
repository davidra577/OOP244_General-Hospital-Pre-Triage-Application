// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include "Time.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5),m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}
	 
	PreTriage::~PreTriage()
	{
		fstream fin(m_dataFilename, ios::trunc);
		fin.open(m_dataFilename, fstream::out);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: ";
		cout << m_averCovidWait << endl;
		cout << "   Triage: ";
		cout << m_averTriageWait << endl;
		fin << m_averCovidWait;
		fin << ',';
		fin << m_averTriageWait;
		fin << '\n';
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout);
			cout << '\n';
			m_lineup[i]->csvWrite(fin);
			fin << '\n';
			delete m_lineup[i];
		}
		fin.close();
		delete[] m_dataFilename;
		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		int count = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				count++;
			}
		}
		if (p == 'C')
		{
			return m_averTriageWait * count;
		}
		else
		{
			return m_averTriageWait * count; 
		}
	}


	void PreTriage::setAverageWaitTime(const Patient& p)
	{

		if (p == 'C')
		{
			m_averCovidWait = ((getTime() - p.operator sdds::Time()) + (m_averCovidWait *= (p.number() - 1))) / p.number();
		}
		else
		{
			m_averTriageWait = ((getTime() - p.operator sdds::Time()) + (m_averTriageWait *= (p.number() - 1))) / p.number();
		}

	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int index = -1;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				index = i;
				break;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		ifstream fin(m_dataFilename);
		char z = 't';
		cout << "Loading data..." << endl;
		fin >> m_averCovidWait;
		fin.ignore(1000, ',');
		fin >> m_averTriageWait;
		fin.ignore(1000, '\n');
		Patient* p = nullptr;
		int i = 0;
		for (i = 0; i < maxNoOfPatients; i++)
		{
			fin >> z;
			fin.ignore(1000, ',');
			if (z == 'C')
			{
				p = new CovidPatient();

			}
			else if(z == 'T')
			{
				p = new TriagePatient();

			}
			if (fin)
			{
				p->fileIO(true);
				p->csvRead(fin);
				p->fileIO(false);
				m_lineup[m_lineupSize] = p;
				m_lineupSize = m_lineupSize + 1;
			}
			if (!fin)
			{
				delete p;
				break;
			}
		}


		if (fin)
		{
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		}

		if (i == 0)
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else
		{
			cout << i << " Records imported..." << endl << endl;
		}
	}

	void PreTriage::reg()
	{
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
			return;
		}
		int selection;
		while (m_pMenu >> selection)
		{
			switch (selection) 
			{
			case 0:
				break;
			case 1:		
				m_lineup[m_lineupSize] = new CovidPatient();
				break;
			
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			}
			m_lineup[m_lineupSize]->setArrivalTime();
			if (m_lineup[m_lineupSize] != nullptr)
			{
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << '\n';
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
				break;
			}
		}


	}

	void PreTriage::admit() 
	{
		int selection;
		char z = 't';
		int index = 0;

		while (m_pMenu >> selection)
		{
			switch (selection)
			{
			case 0:
				break;
			case 1:
				z = 'C';
				break;

			case 2:
				z = 'T';
				break;
			}
			index = indexOfFirstInLine(z);
			if (index == -1)
			{
				break;
			}
			else {
				cout << '\n';
				cout << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
				break;
			}

		}
	}





	void PreTriage::run(void)
	{
		int selection;
		while (m_appMenu >> selection)
		{
			switch (selection) {
			case 0:
				break;
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			}
		}
	}
}

