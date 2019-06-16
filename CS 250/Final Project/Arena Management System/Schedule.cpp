#include "Schedule.h"
#include "Tickets.h"
#include "BankAccount.h"


Schedule::Schedule()
{
	m_eventName = "NULL";
}

std::string Schedule::getDate()
{
	return m_date;
}

std::string Schedule::getTime()
{
	return m_time;
}

std::string Schedule::getEventName()
{
	return m_eventName;
}

/*
	setdate function will convert a int date in the formate YYYYMMDD
	This string value will be converted into a string.
	The string will be assigned to m_date data member.
*/
void Schedule::setDate(int date)
{
	int day, month, year;

	day = (date % 100);
	month = (date / 100) % 100;
	year = (date / 10000);
	auto s = std::to_string(day); // convent a int to a string
	auto x = std::to_string(month); // convent a int to a string
	auto v = std:: to_string(year); // convent a int to a string
	m_date = x +"/"+ s + "/"+  v ;
}

void Schedule::setTime(std::string time)
{
	m_time = time;
}

void Schedule::setEventName(string eventName)
{
	m_eventName = eventName;
}

/*
 creates a new event, accept input from user of date, time and event name
 store this data in our member data above in vectors.
*/
void Schedule::createEvent(vector<Schedule>& schedule, int& callCount)
{
	string event = "Concert", time = "5:00 PM";
	int date = 20180101;

    Schedule objSchedule;

		// promot user to enter an event name
		cout << "Enter Event Name" << endl;
		cin >> event; // user can enter name with spaces using getline

		objSchedule.setEventName(event); // store the user into into our event data member

		cout << "Enter Date of Event in YYYYMMDD formate (EXMPLE: 20180607)" << endl;
		cin >> date;
		objSchedule.setDate(date); // store the user into into our date data member

		cin.ignore();
		cout << "Enter Time of Event Ex. 5:00PM" << endl;
		getline(cin, time);
		objSchedule.setTime(time); // store the user into into our time data member

		schedule.push_back(objSchedule); // store data back into obj vector
}

void Schedule::showEventsCreated(vector<Schedule>& schedule) //call function for print all event’s information
{
    for(unsigned int i = 0; i < schedule.size(); i++)
    {
 		cout << "Event Name: " << schedule[i].getEventName()  <<"\nEvent Date: " << schedule[i].getDate() // prints out all data
		<< "\nEvent Time: " << schedule[i].getTime() << endl << endl;
    }
}

void Schedule::adjustEvents(vector<Schedule>& schedule) //adjust an event’s information (also adjust tickets  accordingly)
{
	string name, event, time;
	int date;

	cout << "Enter name of the Event to edit" << endl;
	cin.ignore();
	getline(cin, name);

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        if (schedule[i].getEventName() == name) // when match we can edit vector position of the event
        {
            cout << "The Event " << name << " was found!\n" << "You may now edit" << endl;
            cout << "Enter Event Name" << endl;
            cin >> event;
            cout << "Enter Date of Event in YYYYMMDD formate (EXMPLE: 20180607)" << endl;
            cin >> date;
            cin.ignore();
            cout << "Enter Time of Event Ex. 5:00PM" << endl;
            getline(cin, time);

            schedule[i].setEventName(event);
            schedule[i].setDate(date);
            schedule[i].setTime(time);
        }
    }
}

void Schedule::printEventDate(vector<Schedule>& schedule) // searches and prints all events at a certain date
{
    string date;
    cout << "Enter Date of Event Ex. 1/1/2018" << endl;
    cin >> date;

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        if(schedule[i].getDate() == date)
        {
            cout << "Event Name: " << schedule[i].getEventName()  <<"\nEvent Date: " << schedule[i].getDate() // prints out all data
            << "\nEvent Time: " << schedule[i].getTime() << endl;
        }
    }
}

void Schedule::cancelEvent(vector<Schedule>& schedule)
{
	string name;

	cout << "Enter name of the Event to cancel" << endl;
	cin.ignore();
	getline(cin, name);

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        if (schedule[i].getEventName() == name)
        {
            ///need a way to refund here. not complete
            schedule.erase (schedule.begin()+i); // deletes all data at event named entered
        }
    }
}


void Schedule::printScheduleMenu(vector<Schedule>& schedule, int& callCount)
{
	int selector = 0; // selects menu option menu
	do{
			std::cout << "Schedule Menu\n\t" <<
			"1. Create New Event\n\t" <<
			"2. Print All Event Information\n\t" <<
			"3. Edit an Event\n\t" <<
			"4. Cancel an Event\n\t" <<
			"5. Print Events at Specific Date\n\t" <<
			"6. Return to Main Menu\n\t" <<
			std::endl;
			std::cin >> selector;

			switch(selector)
			{
				case 1:
				//call function for create a new event and have tickets generated automatically
				createEvent(schedule, callCount);
				break;
				case 2:
				//call function for showing events created.
				showEventsCreated(schedule);
				break;
				case 3:
				//call function for adjust an events information
				adjustEvents(schedule);
				break;
				case 4:
				//call function for cancel an event, refund all ticket sales, and adjust the bank account accordingly
				cancelEvent(schedule);
				break;
				case 5:
                //print all events on a certain date
                printEventDate(schedule);
				break;
				default:
				    cout << "Please Enter a number from 1-6" << endl;
				break;
			}
		}
		while(selector!=6); // loops until we select option 6 to return to main menu
}
