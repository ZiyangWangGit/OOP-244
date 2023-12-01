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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

	bool openFile(const char filename[]);

	void closeFile(); 

	bool read(char* letter, int& number);

	int numberOfMatches(const char* partial_postal_code_prefix); //return the number of matched postalcode

	bool getPostalCode(char* postal_code_prefix); //check user input,return false if user enter"!"

}
#endif 
