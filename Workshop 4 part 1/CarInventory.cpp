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

#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"

using namespace std;
namespace sdds {

	CarInventory::CarInventory() {
		resetInfo();
	}

	void CarInventory::resetInfo() { //set members to safe empty state
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price ) {

		resetInfo();

		if(year >= 1990) {
			m_year = year;
		}
		
		if (code >= 100) {
			m_code = code;
		}

		 if (price > 0.0) {
			m_price = price;
		}

		if (type != nullptr) {
			this->m_type = new char[strlen(type) + 1];
			strcpy(this->m_type, type);
		}

		if (brand != nullptr) {
			this->m_brand = new char[strlen(brand) + 1];
			strcpy(this->m_brand, brand);
		}

		if (model != nullptr) {
			this->m_model = new char[strlen(model) + 1];
			strcpy(this ->m_model, model);
		}
	}

	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {

		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		resetInfo();

		if (year >= 1990) {
			m_year = year;
		}

		if (code >= 100) {
			m_code = code;
		}

		if (price > 0.0) {
			m_price = price;
		}

		if (type != nullptr) {
			this->m_type = new char[strlen(type) + 1];
			strcpy(this->m_type, type);
		}

		if (brand != nullptr) {
			this->m_brand = new char[strlen(brand) + 1];
			strcpy(this->m_brand, brand);
		}

		if (model != nullptr) {
			this->m_model = new char[strlen(model) + 1];
			strcpy(this->m_model, model);
		}

		return *this;
	}

	void CarInventory::printInfo() const {

		cout.setf(ios::fixed);
		cout << "| ";
		cout.setf(ios::left);
		cout.width(10);
		cout << m_type;

		cout << " | ";
		cout.setf(ios::left);
		cout.width(16);
		cout << m_brand;

		cout << " | ";
		cout.setf(ios::left);
		cout.width(16);
		cout << m_model;

		cout << " | ";
		cout.setf(ios::right);
		cout.width(4);
		cout << m_year;

		cout << " |  ";
		cout.setf(ios::right);
		cout.width(3);
		cout << m_code;

		cout << " | ";
		cout.setf(ios::right);
		cout.width(9);
		cout.precision(2);
		cout << m_price;

		cout.unsetf(ios::left);
		cout.unsetf(ios::right);
		cout << " |" << endl;

	}

	bool CarInventory::isValid() const {

		return (m_type != nullptr && m_brand != nullptr && m_model != nullptr &&
				m_year >= 1990 && m_code >= 100 && m_price > 0.0);

	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr) {
			return (strcmp(m_type, car.m_type) == 0 &&                //check if the type, make, brand and year of an object of CarInventory are equal to another object
					strcmp(m_brand, car.m_brand) == 0 &&
					strcmp(m_model, car.m_model) == 0 &&
					m_year == car.m_year);
		}
		else {
			return false;
		}

	}

	int find_similar(CarInventory car[], const int num_cars) {

		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return -1;
	}
	
}