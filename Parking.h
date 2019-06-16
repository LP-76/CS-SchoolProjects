#ifndef Parking_h
#define Parking_h

#include "BankAccount.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Parking //This ADT contains all information related to the management of parking.
{
private:
	int m_sectionNumber;
	int m_parkingSpaceNumber;
	double m_price;
	bool m_available;

    void printParkingInfo(vector<Parking>&); // print out all parking info.
    void printParkingSection(vector<Parking>&); // function lets user filter parking spaces by section. prints to console
    void printAvailableParking(vector<Parking>&); // outputs parking spaces that are available
    void adjustParkingAvailability(vector<Parking>&, vector<BankAccount>&); // lets user change the available tickets and adjust bank account
public:
	Parking();

	void printParkingMenu(vector<Parking>&,vector<BankAccount>&); // print menu for Parking class
    void loadParkingData(vector<Parking>&); // loads all data from txt file

	//accessor functions
	int getSectionNumber();
	int getParkingSpaceNumber();
	double getPrice();
	bool getAvailable();

	//mutator functions
	void setSectionNumber(int);
	void setParkingSpaceNumber(int);
	void setPrice(double);
	void setAvailable(bool);
};
#endif
