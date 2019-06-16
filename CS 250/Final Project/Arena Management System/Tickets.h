#ifndef Tickets_h
#define Tickets_h

#include "Schedule.h"
#include "BankAccount.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Tickets //This ADT contains all information related to the management of ticket sales
{
private:
	int m_sectionNumber;
	int m_seatNumber;
	double m_ticketPrice;
	int m_date;
	int m_time;
	bool m_sold;
	string m_id;

	// FOLLOWING MEMBER FUNCTIONS ARE PRIVATE. ONLY USED BY OTHER FUNCTION IN THIS CLASS.
    void printAvailableTickets(vector<Tickets>& ,vector<Schedule>&); // prints all tickets available (tickets marked as 1 mean not sold)
    void printUnavailableTickets(vector<Tickets>& ,vector<Schedule>&); // prints all tickets available (tickets marked as 1 mean not sold)
    void sellTickets(vector<Tickets>& ,vector<Schedule>&,vector<BankAccount>&); // function will set our sold data member from 0 to 1 depending on what section it lies.
    void printTicketsByDate(vector<Tickets>& ,vector<Schedule>&); // prints all events by date
    void calcTicketsSold(vector<Tickets>&, vector<BankAccount>&); ///COULD NOT GET THIS FUNCTION TO WORK PROPERLY =(
public:
	//*member function declarations here
	Tickets();
	void readTicketFile(vector<Tickets>&); //reads in all of our data and stores it.
	void printTicketMenu(vector<Tickets>& ,vector<Schedule>&,vector<BankAccount>&); // Show all ticket’s info after after we generate a event name
    void generateTickets(vector<Tickets>& ,vector<Schedule>&); // function will generate tickets after our Schedule is made

	//accessor functions
	int getSectionNumber();
	int getSeatNumber();
	double getTicketPrice();
	int getDate();
	int getTime();
	bool getSold();
	string getID();

	//mutator functions
	void setSectionNumber(int);
	void setSeatNumber(int);
	void setTicketPrice(double);
	void setDate(int);
	void setTime(int);
	void setSold(bool);
	void setID(string);
};

#endif
