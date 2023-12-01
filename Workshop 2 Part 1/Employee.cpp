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

#include <iostream>
#include <cstring>
#include <cstdio>
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(Employee &employees) {
        bool ok = false;

        
      if (read(employees.m_empNo) && read(employees.m_salary) && read(employees.m_name)) //return true if all three read functions successfully read
        {
            ok = true;
        }

        return ok;
    }
  
    bool load() {
        bool ok = false;
        int i;


        if (!(openFile(DATAFILE))) {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        else {
            ok = true;
        }
        
        
        noOfEmployees = noOfRecords();
        employees = new Employee[noOfEmployees];

        for (i = 0; i < noOfEmployees; i++) {   //loop through employee and get their data 
            if (!load(employees[i])) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                ok = false;
            }
            else {
                ok = true;
            }
        }

        closeFile();

        return ok;
    }

    void display(const Employee &employee) {
        
            cout << employee.m_empNo << ": " << employee.m_name << ", $" << employee.m_salary << endl;
    }

    void display() {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (i = 0;  i < noOfEmployees; i++) {
                cout << i+1  << "- ";
                display(employees[i]);
            }
          
    }

    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) { //ooop through each employee and deallocate the 'm_name' arrays
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
        }

        delete[] employees;
        employees = nullptr;

        noOfEmployees = 0;
    }

}