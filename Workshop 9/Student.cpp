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

#include  <cstring>
#include <iostream>
#include "Student.h"


using namespace std;
namespace sdds {
	Student::Student() : m_name(nullptr), m_age(0) {}

	Student::Student(const char* name, int age) : m_age(age) {
		if (name != nullptr) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else {
			m_name = nullptr;
		}
	}

	Student::~Student() {
		delete[] m_name;
	}

	Student::Student(const Student& RO):m_age(RO.m_age) {
		if (RO.m_name != nullptr) {
			m_name = new char[strlen(RO.m_name) + 1];
			strcpy(m_name, RO.m_name);
		}
		else {
			m_name = nullptr;
		}
	}

	Student& Student::operator = (const Student& RO) {
		if (this != &RO) {
			m_age = RO.m_age;

			delete[] m_name;

			if (RO.m_name != nullptr) {
				m_name = new char[strlen(RO.m_name) + 1];
				strcpy(m_name, RO.m_name);
			}
			else {
				m_name = nullptr;
			}
		}
		return *this;
	}

	void Student::display()const {
		cout << "Name: " << m_name << endl;
		cout << "Age: " << m_age << endl;
	}

}