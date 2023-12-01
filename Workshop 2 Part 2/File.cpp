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
#include <iostream>
#include <cstring> 
#include "File.h"
#include "Population.h"

using namespace std;
namespace sdds {

    FILE* fptr; 

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* letter, int& number) {
        if (fscanf(fptr, "%3[^,],%d\n", letter, &number) == 2) {
            return true;
        }
        return false;
    }

    int numberOfMatches(const char* partial_postal_code_prefix) {
        char postalCode[arraySize];
        int numberMatches = 0;

        if (fptr) {
            while (fscanf(fptr, "%3[^,],%*s\n", postalCode) == 1) {
                if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalCode, partial_postal_code_prefix)) {
                    numberMatches++;
                }
            }

            rewind(fptr);
        }
        return numberMatches;
    }

    bool getPostalCode(char* postal_code_prefix) {

        bool ok = true;
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> " ;
        cin >> postal_code_prefix;
       
        if ((strcmp(postal_code_prefix, "!")) == 0) {
            ok = false;
        }
        return ok;
    }
}
