/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP244
*

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include "Student.h"
#include "Graduate.h"

using namespace std;
namespace sdds {

	Graduate::Graduate(const char* studentName, int studentAge, const char* title, const char* supervisor)
		: Student(studentName, studentAge) {
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
		if (supervisor != nullptr) {
			m_supName = new char[strlen(supervisor) + 1];
			strcpy(m_supName, supervisor);
		}
		else {
			m_supName = nullptr;
		}
	}

	Graduate::~Graduate() {
		delete[] m_title;
		delete[] m_supName;
	}

	Graduate::Graduate(const Graduate& RO) : Student(RO){
		if (RO.m_supName != nullptr) {
			m_supName = new char[strlen(RO.m_supName) + 1];
			strcpy(m_supName, RO.m_supName);
		}
		else {
			m_supName = nullptr;
		}
		if (RO.m_title != nullptr) {
			m_title = new char[strlen(RO.m_title) + 1];
			strcpy(m_title, RO.m_title);
		}
		else {
			m_title = nullptr;
		}
	}

	Graduate& Graduate::operator = (const Graduate& RO) {
		if (this != &RO) {
			Student::operator = (RO);
			delete[] m_title;
			delete[] m_supName;
			if (RO.m_supName != nullptr) {
				m_supName = new char[strlen(RO.m_supName) + 1];
				strcpy(m_supName, RO.m_supName);
			}
			else {
				m_supName = nullptr;
			}
			if (RO.m_title != nullptr) {
				m_title = new char[strlen(RO.m_title) + 1];
				strcpy(m_title, RO.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	void Graduate::display()const {
		Student::display();
		cout << "Thesis Title: " << m_title << endl;
		cout << "Supervisor: " << m_supName << endl;
		cout << "---------------------------------------------" << endl;
	}
}