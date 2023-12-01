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

const int arraySize = 128;

namespace sdds {
	

	bool openFile(const char filename[]);

	int noOfRecords();

	void closeFile();

	bool read(char* &name);                  //read employee name return true if read was successful

	bool read(int& employeeNumber);         // read employee number return true if read was successful

	bool read(double &employeeSalary);      ///read employee salary return true if read was successful


}

#endif // !SDDS_FILE_H_
