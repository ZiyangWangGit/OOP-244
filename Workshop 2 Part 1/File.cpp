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
#include <cstdio>
#include <cstring>
#include "File.h"


namespace sdds {

    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }

        rewind(fptr);

        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* &name) {
        char localArray[arraySize];
        int nameLength;

        if (fscanf(fptr,"%127[^\n]\n", localArray) == 1) {

            nameLength = strlen(localArray);       //calculate the length of the string
            name = new char[nameLength + 1];    //allocate memory for the name 
            strcpy(name, localArray);   

            return true; // read employee name return true if read was successful
        }

        return false;
    }

    bool read(int &employeeNumber) {
     
        return (fscanf(fptr, "%d,", &employeeNumber) == 1);  //read employee number return true if read was successful
      
    }

    bool read(double &employeeSalary) {

        return (fscanf(fptr,"%lf,", &employeeSalary) == 1);   //read employee salary return true if read was successful
      
  
    }
}