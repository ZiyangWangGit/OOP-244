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

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
# include "File.h"

const int arraySize = 4;

namespace sdds {

	struct Population {
		char* postalCode;
		int population;	
	};

	bool startsWith(const char* cString, const char* subString);	// returns true of the cstring starts with subString

	void sort(); // sort the array in ascending order based on population numbers.if the numbers are the same
	             //ascending order based on the postalcode

	bool load(const char* filename, const char* partial_postal_code_prefix);
	//reads data from a file, filters and stores specific records in a dynamically allocated array
	void display();

	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_