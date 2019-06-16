#ifndef Schedule_h
#define Schedule_h

#include "BankAccount.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Schedule //This ADT contains all information related to the scheduling of events.
{
private:
	string m_date;
	string m_time;
	string m_eventName;

    void cancelEvent(vector<Schedule>&);
    void printEventDate(vector<Schedule>&);
    void createEvent(vector<Schedule>&, int&); // function to create a new event.
    void showEventsCreated(vector<Schedule>&); // prints out all the events created
    void adjustEvents(vector<Schedule>&); // adjust events created.
public:
	Schedule();
    void printScheduleMenu(vector<Schedule>&, int&); // function to print menu to console

	string getEventName();
	string getDate();
	string getTime();

	void setDate(int);
	void setTime(string);
	void setEventName(string);
};

#endif
