#include "Tickets.h"
#include "Schedule.h"
#include "Parking.h"
#include "Staff.h"
#include "BankAccount.h"
#include "ConcessionStand.h"

void printMenu(vector<Tickets>& ,vector<Schedule>&, vector<Parking>&,vector<Staff>&,vector<BankAccount>&,vector<ConcessionStand>&, int&);

int main()
{
    Tickets objTickets;
    Parking objParking;
    Staff objStaff;
    BankAccount objBankAccount;
    ConcessionStand objConcessionStand;
    int callCount = 0; // call count is used for create events class function so user can make more then one event at a time.

    //vectors used for storing our data when they enter our classes.
	vector<Tickets> tickets;
	vector<Schedule> schedule;
	vector<Parking> parking;
	vector<Staff> staff;
	vector<BankAccount> bankAccount;
	vector<ConcessionStand> stand;


    objTickets.readTicketFile(tickets); // function to load all data in text file
    objStaff.loadStaffData(staff); // function to load all data in text file
    objParking.loadParkingData(parking); // function to load all data in text file
    objBankAccount.loadBankAccountData(bankAccount); // function to load all data in text file
    objConcessionStand.loadConcessionStandData(stand); // function to load all data in text file

 	printMenu(tickets,schedule,parking,staff,bankAccount,stand,callCount); // prints menu for user to select

	return 0;
}

void printMenu(vector<Tickets>& tickets,vector<Schedule>& schedule, vector<Parking>& parking,vector<Staff>& staff,vector<BankAccount>& bankAccount,vector<ConcessionStand>& stand, int& callCount)
{

    //obj used to print our menu selection screens
    Staff objStaff;
    Tickets objTickets;
    Schedule objSchedule;
    Parking objParking;
    BankAccount objBankAccount;
    ConcessionStand objConcessionStand;

	int selector = 0; // selects menu option menu
	do
	{
		std::cout << "Main Menu\n\t" <<
		"1. Manage Tickets\n\t" <<
		"2. Manage Schedule\n\t" <<
		"3. Manage Parking\n\t" <<
		"4. Manage Staff\n\t" <<
		"5. Manage Bank Account\n\t" <<
		"6. Manage Concession Stand\n\t" <<
		"7. Exit\n" <<
		std::endl;
		std::cin >> selector;

		switch(selector)
		{
			case 1:
			//call function for managing tickets member functions
            objTickets.printTicketMenu(tickets, schedule,bankAccount);
			break;
			case 2:
			//call function for managing Schedule member functions
			objSchedule.printScheduleMenu(schedule, callCount);
			break;
			case 3:
			//call function for managing Parking member functions
			objParking.printParkingMenu(parking,bankAccount);
			break;
			case 4:
			//call function for managing Staff member functions
			objStaff.printStafffMenu(staff);
			break;
			case 5:
			//call function for managing Bank Account member functions
			objBankAccount.printBankAccountMenu(bankAccount);
			break;
			case 6:
			//call function for managing Concession Stand member functions
			objConcessionStand.printConcessionStandMenu(stand, bankAccount);
			break;
			default:
                cout << "Please Enter a number from 1-7" << endl;
			break;
		}
	}
	while(selector != 7); // loop until user select
}
