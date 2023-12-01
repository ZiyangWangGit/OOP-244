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

#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;
namespace sdds {

	void Train::initialize(){
		train = nullptr;
		people = -1;
		departTime = -1;	
	}

	bool Train::validTime(int value)const {
		if (value > MIN_TIME && value < MAX_TIME) {   //check if the value is between the minimum and maximum values 
			if ((value % 100) <= 59) {                //check if the two right digits are less than or equal to 59
				return true;
			}
		}
		return false;

	}

	bool Train::validNoOfPassengers(int value)const {
		if (value > 0 && value <= MAX_NO_OF_PASSENGERS){  //check if the value is less than the max passengers
			return true;
		}
		return false;
	}

	void Train::set(const char* name) {
		delete[] train;
		train = nullptr;

		if (name != nullptr && name[0] != '\0') {   //check if the name either nullprt or undefined
			train = new char[strlen(name) + 1];
			strcpy(train, name);		
		}
	}

	void Train::set(int noOfPassengers, int departure) {
		if (!validTime(departure) || !validNoOfPassengers(noOfPassengers)) { //check if any attributes are invalid
			people = -1;
			departTime = -1;
		}
		else {
			people = noOfPassengers;
			departTime = departure;
		}
	}

	void Train::set(const char* name, int noOfPassengers, int departure) {
		set(name);
		set(noOfPassengers, departure);
	}

	void Train :: finalize() {
		delete[] train;
	}

	bool Train::isInvalid()const {
		if ((people == -1) || (departTime == -1) || (train == nullptr)) {   //check if any of the values are invalid
			return true;
		}
		return false;

	}

	int Train::noOfPassengers() const {
		return people;
	}

	const char* Train::getName() const {
		return train;
	}

	int Train::getDepartureTime() const{
		return departTime;
	}

	void Train::display() const {        //display train information if all values are valid
		if (!(isInvalid())) {
			cout << "NAME OF THE TRAIN:    " << train << endl;
			cout << "NUMBER OF PASSENGERS: " << people << endl;
			cout << "DEPARTURE TIME:       " << departTime << endl;
		}
		else
		{
			cout << "Train in an invalid State!" << endl;
		}
	}

	bool Train::load(int& numberOfPassenger){
		int newPassengers;

		cout << "Enter number of passengers boarding:" << endl << "> ";
		cin >> newPassengers;
		people += newPassengers;

		if (!validNoOfPassengers(people)){                //check if the number of passengers within the range
			numberOfPassenger = people - MAX_NO_OF_PASSENGERS;
			return false;
		}
		return true;
	}

	bool Train::updateDepartureTime() {
		int newDepartTime;

		cout << "Enter new departure time:" << endl << "> ";
		cin >> newDepartTime;

		if (!validTime(newDepartTime)) //check if updated depart time within the range
		{
			departTime = -1;
			return false;
		}
		departTime = newDepartTime;
		return true;
	}

	bool Train::transfer(const Train& fromTrain) {

		if (isInvalid() || (fromTrain.isInvalid())) {
			return false;
		}

		char* concatenatedTrain = new char[strlen(train) + strlen(fromTrain.train) + CONCATESIZE]; // Calculate the length needed for the concatenated train name
		strcpy(concatenatedTrain, train);   //copying the content of the train string into the concatenatedTrain string
		strcat(concatenatedTrain, ", ");
		//if concatenatedTrain initially contained "ABC," and fromTrain.train contains "XYZ," the result of the strcat operation 
		// will be that concatenatedTrain now contains "ABCXYZ."
		strcat(concatenatedTrain, fromTrain.train);
		set(concatenatedTrain);  //set concatenatedTrain name to the current train
		delete[] concatenatedTrain;

		people += fromTrain.people;
		if (validNoOfPassengers(people)) {  //check if updated number of passengers within the range
			;
		}
		else {
			int passengerLeft = people - MAX_NO_OF_PASSENGERS;
			people = MAX_NO_OF_PASSENGERS;
			cout << "Train is full; ";
			cout << passengerLeft;
			cout << " passengers of ";
			cout << fromTrain.train;
			cout << " could not be boarded!" << endl;
		}		

		return true;
	}
}
