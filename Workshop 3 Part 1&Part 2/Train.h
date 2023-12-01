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


#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000
#define CONCATESIZE 4

namespace sdds {

	class Train {
	private: //object is instance of class
		char* train;
		int people;
		int departTime;

	public:
		
		void initialize();//Initializes the Train object to an invalid state

		bool validTime(int value)const;// Returns true if the value is between the minimum and maximum acceptable values 
		                               //and if the two right digits are less than or equal to 59

		bool validNoOfPassengers(int value)const;//Returns true if the number of passengers is positive and less than max passengers

		void set(const char* name);//Sets the name of the Train dynamically

		void set(int noOfPassengers, int departure);//sets the two attributes for the number of passengers and departure time to the incomming values if the are valid. 
		                                            //If not both will be set to -1 to mark them as invalid

		void set(const char* name, int noOfPassengers, int departure);//sets the name, the number of passengers and the departure time to incomming arguments 
		                                                               //using the same logic of the other two set functions.

		void finalize();  //Finlizes the use of the Train object by deleting the memory pointed by the name attribute pointer

		bool isInvalid()const;//return true if any of the attributes are set to their invalid state

		int noOfPassengers() const;//return the number of people on a train

		const char* getName() const;// return the name of a train

		int getDepartureTime() const;//return  the time of departure

		void display() const;//display valid train information

		bool load(int& numerOfpassenger);//returns a boolean,true if user entered number is less than max num of people allowed,else false

		bool updateDepartureTime();//return true if updated depart time within the range

		bool transfer(const Train& fromTrain);//return true if successfully transfers the passengers of a Train to the current Train.
	};

}



#endif // !
