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
#include <algorithm>
#include "Population.h"
#include "File.h"




using namespace std;
namespace sdds {

    int numberMatches = 0;
    Population* population;

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    void sort() {
        int i, j;
        Population temp;
        for (i = numberMatches - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].population > population[j + 1].population ||
                    (population[j].population == population[j + 1].population &&
                        strcmp(population[j].postalCode, population[j + 1].postalCode) > 0)) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        char postalCode[arraySize];
        int i = 0, number;  

        if (!openFile(filename)) {
            return false;
        }

        numberMatches = numberOfMatches(partial_postal_code_prefix);

        population = new Population[numberMatches]; // Allocate memory for the entire population array

        while (read(postalCode, number)) {
            if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalCode, partial_postal_code_prefix)) {
                population[i].postalCode = new char[arraySize];
                strcpy(population[i].postalCode, postalCode);
                population[i].population = number;
                i++;
            }
        }

        closeFile();
        return true; 
    }

    void display() {
        int totalNumber = 0;

        sort();
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        for (int i = 0; i < numberMatches; i++) {
            cout << i + 1 << "- " << population[i].postalCode << ":  " << population[i].population << endl;
            totalNumber += population[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalNumber << endl << endl;
    }

    void deallocateMemory() {
        if (population != nullptr) {
            for (int i = 0; i < numberMatches; i++) {
                delete[] population[i].postalCode; // Deallocate memory for each postalCode
            }
            delete[] population;
            population = nullptr;
            numberMatches = 0;
        }
    }
}
