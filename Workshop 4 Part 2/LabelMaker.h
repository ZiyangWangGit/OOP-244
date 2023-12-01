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
#ifndef SDD_LABELMAKER_H
#define SDD_LABELMAKER_H


namespace sdds {


	class LabelMaker {
	private:
		int numberOfLabels;
		char* frame;
		char** array;

	public:
		LabelMaker(int noOfLabels); //creates a dynamic array of Labels to the size of noOfLabels

		void readLabels(); //Gets the contents of the Labels 

		void printLabels();//Prints the Labels 

		~LabelMaker();//Deallocates the memory
	};
}

#endif
