// Name: David Ra
// Email: dra@myseneca.ca
// Student ID: 101977205
// Assigment Milestone 5
// Date: Dec 4th 2020
// SECTION: OOP244 NEE
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
	Menu::Menu()
	{
		setEmpty();
	}
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		if (MenuContent != nullptr)
		{
			m_noOfSel = 0;
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
			m_noOfSel = NoOfSelections;
		}
		else {
			setEmpty();
		}
	}

	Menu::~Menu()
	{
		delete[] m_text;
	}

	void Menu::setEmpty()
	{
		m_text = nullptr;
		m_noOfSel = 0;
	}
	std::ostream& Menu::display(std::ostream& ostr)const
	{
		ostr << m_text;
		ostr << '\n';
		ostr << "0- Exit" << endl;
		ostr << "> ";
		return ostr;

	}

	int& Menu::operator>>(int& Selection)
	{
		int temp;
		bool ok = false;
		display();
		while (!ok)
		{
			if (cin >> temp)
			{
				if (temp >= 0 && temp <= m_noOfSel)
				{
					Selection = temp;
					ok = true;
				}
				else
				{
					cout << "Invalid value enterd, retry[0 <= value <= 3]: ";
				}
			}
			else
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		return Selection;

	}
}