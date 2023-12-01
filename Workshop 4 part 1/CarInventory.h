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
#ifndef SDD_CARINVENTORY_H
#define SDD_CARINVENTORY_H

namespace sdds {
	const int defaultYear = 2022;
	const int defaultCode = 100;
	const int defaultPrice = 1.0;

	class CarInventory {
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void  resetInfo();

	public:
		CarInventory();  //default constructor 

		//constructor that will dynamically keep the values of the C-string argument
		CarInventory(const char* type, const char* brand, const char* model, int year = defaultYear, int code = defaultCode, double price = defaultPrice);

		~CarInventory();
		//deallocate all the allocated memory and then set the attributes to the corresponding arguments exactly like the 6-argument constructor
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year = defaultYear, int code = defaultCode, double price = defaultPrice);

		void printInfo() const;//prints the values of all the member variables

		bool isValid() const;// returns whether all member variables have valid values 

		bool isSimilarTo(const CarInventory& car) const;// check whether the type, make, brand and year of an object of CarInventory are equal to another object of this class

	};

	int find_similar(CarInventory car[], const int num_cars);
}


#endif
