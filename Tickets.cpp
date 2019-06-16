#include "Tickets.h"
#include "Schedule.h"
#include "BankAccount.h"


//initialization each time a class is created
Tickets::Tickets()
{

}

int Tickets::getSectionNumber()
{
	return m_sectionNumber;
}

int Tickets::getSeatNumber()
{
	return m_seatNumber;
}

double Tickets::getTicketPrice()
{
    return m_ticketPrice;
}

int Tickets::getDate()
{
    return m_date;
}

int Tickets::getTime()
{
    return m_time;
}

bool Tickets::getSold()
{
    return m_sold;
}

string Tickets::getID()
{
    return m_id;
}

void Tickets::setSectionNumber(int section)
{
	m_sectionNumber = section;
}

void Tickets::setSeatNumber(int seat)
{
	m_seatNumber = seat;
}

void Tickets::setTicketPrice(double price)
{
	m_ticketPrice = price;
}

void Tickets::setDate(int dates)
{
	m_date = dates;
}

void Tickets::setTime(int times)
{
	m_time = times;
}

void Tickets::setSold(bool solds)
{
	m_sold = solds;
}

void Tickets::setID(string ids)
{
	m_id = ids;
}


//reads in all of our data and stores it.
void Tickets::readTicketFile(vector<Tickets>& tickets)
{
	int section, seat,i = 0;
	double price;
	bool available;
	string eventName;

    Tickets obj;

	ifstream input("ticket.txt");
	while(!input.eof()) // while loop will load in all data inside "ticket.txt file until end of file.
	{
		input >> section;
		obj.setSectionNumber(section);
		input >> seat;
		obj.setSeatNumber(seat);
		input >> price;
		obj.setTicketPrice(price);
		input >> available;
		obj.setSold(available);
		input >> eventName;
		obj.setID(eventName);

        tickets.push_back(obj); // stores all data inside vector obj
		i++;
	}

    input.close(); // close our file after all data is loaded.
}

void Tickets::generateTickets(vector<Tickets>& tickets,vector<Schedule>& schedule) // function will generate tickets needed.
{

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        for(unsigned int j = 0; j < tickets.size(); j++)
            {
                if(schedule[i].getEventName() == tickets[j].getID()) // if events in tickets match event user entered. It will create tickets for that event.
                {
                    cout << "Section Number: " << tickets[j].getSectionNumber()
                    << "\nSeat Number: " << tickets[j].getSeatNumber()
                    << "\nPrice: " << tickets[j].getTicketPrice()
                    << "\nAvailable: " << tickets[j].getSold()
                    << "\nName: " << tickets[j].getID()
                    << endl << endl;
                }
            }
    }
}

void Tickets::printAvailableTickets(vector<Tickets>& tickets, vector<Schedule>& schedule) // prints all tickets available (tickets marked as 1 mean not sold)
{
    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        for(unsigned int j = 0; j < tickets.size(); j++)
            {
                if(schedule[i].getEventName() == tickets[j].getID())
                {
                    if(tickets[j].getSold() != 0) // if tickets or not sold. they will print to console. Not sold is a 1
                    {
                        cout << "Section Number: " << tickets[j].getSectionNumber()
                        << "\nSeat Number: " << tickets[j].getSeatNumber()
                        << "\nPrice: " << tickets[j].getTicketPrice()
                        << "\nAvailable: " << tickets[j].getSold()
                        << "\nName: " << tickets[j].getID()
                        << endl << endl;
                    }
                }
            }
    }

}


void Tickets::printUnavailableTickets(vector<Tickets>& tickets, vector<Schedule>& schedule) // prints all tickets available (tickets marked as 1 mean not sold)
{

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        for(unsigned int j = 0; j < tickets.size(); j++)
            {
                if(schedule[i].getEventName() == tickets[j].getID())
                {
                    if(tickets[j].getSold() != 1) // prints out if out tickets are sold to the console. sold is a 0
                    {
                        cout << "Section Number: " << tickets[j].getSectionNumber()
                        << "\nSeat Number: " << tickets[j].getSeatNumber()
                        << "\nPrice: " << tickets[j].getTicketPrice()
                        << "\nAvailable: " << tickets[j].getSold()
                        << "\nName: " << tickets[j].getID()
                        << endl << endl;
                    }
                }
            }
    }

}

void Tickets::sellTickets(vector<Tickets>& tickets,vector<Schedule>& schedule,vector<BankAccount>& bankAccount) // function will set our sold data member from 0 to 1 depending on what section it lies.
{
    string event = " ";
    int section = 0, seat = 0,buySell = 0;
    int numTicketsSold = 0;

    cout << "Please Select: \n1. Sell a Ticket\n2. Refund a Ticket" << endl;
    cin >> buySell;

    cout << "Which event would you like to attend?" << endl;
    cin >> event;
    cout << "Which section number would you like?" << endl;
    cin >> section;
    cout << "Which seat number would you like?" << endl;
    cin >> seat;

    // if statement to set out ticket as sold.
    if(buySell == 1)
    {
        for(unsigned int j = 0; j < schedule.size(); j++)
        {
            for(unsigned int i = 0; i < tickets.size(); i++)
            {
                if(schedule[j].getEventName() == event)
                {
                    if(tickets[i].getSectionNumber() == section)
                    {
                        if(tickets[i].getSeatNumber() == seat)
                        {
                            tickets[i].setSold(0);
                            numTicketsSold++;
                            cout << "Testing" << tickets[i].getSold() << endl;
                        }else
                            cout << "Seat not working" << endl;
                    }
                    else
                        cout << "Section not working" << endl;
                }else
                    cout << "User not working" << endl;
            }
        }
    }
    else if(buySell == 2) // if else statement to refund tickets.
    {
        for(unsigned int j = 0; j < schedule.size(); j++)
        {
            for(unsigned int i = 0; i < tickets.size(); i++)
            {
                if(schedule[j].getEventName() == event)
                {
                    if(tickets[i].getSectionNumber() == section)
                    {
                        if(tickets[i].getSeatNumber() == seat)
                        {
                            tickets[i].setSold(1);
                            numTicketsSold--;
                            cout << "Testing" << tickets[i].getSold() << endl;
                        }else
                            cout << "Seat not working" << endl;
                    }
                    else
                        cout << "Section not working" << endl;
                }else
                    cout << "User not working" << endl;
            }
        }
    }

    BankAccount objBankAccount;

    objBankAccount.numTicketSales(bankAccount,numTicketsSold); // changes amount in bank.
}

void Tickets::printTicketsByDate(vector<Tickets>& tickets ,vector<Schedule>& schedule) // prints all tickets by date when user enters a string for the date.
{
    string date;
    cout << "Enter Date of Event Ex. 1/1/2018" << endl;
    cin >> date; // input need to be

    for(unsigned int i = 0; i < schedule.size(); i++)
    {
        for(unsigned int j = 0; j < tickets.size(); j++)
            {
                if(schedule[i].getEventName() == tickets[j].getID()) // event must match what we are looking for. then proceeds
                {
                    if(schedule[i].getDate() == date) // if date match. we will print event to the console.
                    {
                        cout << "Section Number: " << tickets[j].getSectionNumber()
                        << "\nSeat Number: " << tickets[j].getSeatNumber()
                        << "\nPrice: " << tickets[j].getTicketPrice()
                        << "\nAvailable: " << tickets[j].getSold()
                        << "\nName: " << schedule[i].getEventName()
                        << "\nDate: " << schedule[i].getDate()
                        << endl << endl;
                    }
                }
            }
    }
}

void Tickets::calcTicketsSold(vector<Tickets>& tickets, vector<BankAccount>& bankAccount) /// FUNCTION NOT WORKING CORRECTLY.
{
    int counting = 0;
    double bankBalance = bankAccount[0].getTotalSales();
    double refundAmount = 0;
    for(unsigned int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i].getSold() == 0)
        {
            counting++;
        }
    }
    refundAmount *= counting;
    bankBalance += refundAmount;
    bankAccount[0].setTotalSales(bankBalance);
}


//Show all ticket’s info after after we generate a event name
void Tickets::printTicketMenu(vector<Tickets>& tickets,vector<Schedule>& schedule,vector<BankAccount>& bankAccount)
{
	int selector = 0; // selects menu option menu
	do{
			std::cout << "Ticket Manager\n\t" <<
			"1. Show all ticket information\n\t" <<
			"2. Show all available tickets\n\t" <<
			"3. Show all unavailable tickets\n\t" <<
			"4. Sell/Refund ticket\n\t" <<
			"5. Search for ticket by date\n\t" <<
			"6. Return to Main Menu\n\t" <<
			std::endl;
			std::cin >> selector;

			switch(selector)
			{
				case 1:
				//call function for show all ticket’s info
				generateTickets(tickets,schedule);
				break;
				case 2:
				//call function for show all available tickets
				printAvailableTickets(tickets,schedule);
				break;
				case 3:
				//call function for show all unavailable tickets
                printUnavailableTickets(tickets,schedule);
				break;
				case 4:
				//call function for able to sell/refund a ticket (adjust bank account accordingly)
				sellTickets(tickets,schedule,bankAccount);
				break;
				case 5:
				//print a ticket by date
				printTicketsByDate(tickets,schedule);
				break;
				default:
				    cout << "Please enter a number 1-6" << endl;
				break;
			}
		}
		while(selector!=6); // loops until we select option 6 to return to main menu
}
