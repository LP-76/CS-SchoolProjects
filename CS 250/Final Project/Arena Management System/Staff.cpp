#include "Staff.h"

Staff::Staff()
{

}

int Staff::getID()
{
    return m_id;
}

string Staff::getName()
{
    return m_name;
}

string Staff::getJobTitle()
{
    return m_jobTitle;
}

double Staff::getSalary()
{
    return m_salary;
}

void Staff::setID(int ID)
{
    m_id = ID;
}

void Staff::setName(string first,string last)
{

    m_name = first + " " + last;
}

void Staff::setJobTitle(string jobTitle)
{
    m_jobTitle = jobTitle;
}

void Staff::setSalary(double salary)
{
    m_salary = salary;
}

void Staff::loadStaffData(vector<Staff>& staff) // loads in all data from "staff.txt file when program starts
{
    int ID, i = 0;
    string first,last, job;
    double salary;

    Staff objStaff;

	ifstream input("staff.txt");
	while(!input.eof()) // while loop will load in all data inside "ticket.txt file until end of file.
	{
		input >> ID;
		objStaff.setID(ID);
		input >> first;
		input >> last;
		objStaff.setName(first,last);
		input >> job;
		objStaff.setJobTitle(job);
		input >> salary;
		objStaff.setSalary(salary);

        staff.push_back(objStaff); // stores all data inside vector obj
		i++;
	}
    input.close(); // close our file after all data is loaded.
}

/*
    User enters ID of staff member to edit.
    If user if is a match.
    User enters new data for first,last name, Job title, and Salary
    Data user entered is stored into vectors
*/
void Staff::adjustStaff(vector<Staff>& staff)
{
    string first,last,job, name;
    int ID;
    double salary;

	cout << "Enter ID number of the Staff to Edit" << std::endl;
    cin >> ID;

    for(unsigned int i = 0; i < staff.size(); i++)
    {
        if (staff[i].getID() == ID)
        {
            cout << "The staff " << name << " was found!\n" << "You may now edit" << endl;
            cout << "Enter Staff Name" << endl;
            cin >> first;
            cin >> last;
            cout << "Enter Job Title" << endl;
            cin.ignore();
            getline(cin, job);
            cout << "Enter Salary" << endl;
            cin >> salary;

            staff[i].setName(first,last);
            staff[i].setJobTitle(job);
            staff[i].setSalary(salary);
        }
    }
}
/*
    For loop to print out all our data stored inside of the staff vector
*/
void Staff::printAllStaff(vector<Staff>& staff)
{
    for(unsigned int i = 0; i < staff.size(); i++)
    {
        cout << "ID: " << staff[i].getID() << "\nName: " << staff[i].getName()
        << "\nJob Title: " << staff[i].getJobTitle() << "\nSalary: " << staff[i].getSalary()
        << endl << endl;
    }
}

/*
    User enters staff ID of user to print out.
    if user id matches what is on record.
    print out all data members for staff member.
*/
void Staff::printStaffJobID(vector<Staff>& staff)
{
    int ID = 0;

    cout << "Enter Staff ID" << endl;
    cin >> ID;
    for(unsigned int i = 0; i < staff.size(); i++)
    {
        if (staff[i].getID() == ID)
        {
            cout << "ID: " << staff[i].getID() << "\nName: " << staff[i].getName()
            << "\nJob Title: " << staff[i].getJobTitle() << "\nSalary: " << staff[i].getSalary()
            << endl << endl;
        }
    }
}

/*
    User enters staff Job Title of user to print out.
    if user id matches what is on record.
    print out all data members for staff member.
*/
void Staff::printStaffJobType(vector<Staff>& staff)
{
    string job;

    cout << "Enter Staff Job Title" << endl;
    cin.ignore();
    getline(cin,job);
    for(unsigned int i = 0; i < staff.size(); i++)
    {
        if (staff[i].getJobTitle() == job)
        {
            cout << "ID: " << staff[i].getID() << "\nName: " << staff[i].getName()
            << "\nJob Title: " << staff[i].getJobTitle() << "\nSalary: " << staff[i].getSalary()
            << endl << endl;
        }
    }
}

/*
    Promts user to enter first, last, id number, job title and salary.
    store data into vector staff
*/
void Staff::hireNewStaff(vector<Staff>& staff) // user can add staff member to
{

    string first,last,job;
    int ID;
    double salary;

    Staff objStaff;

    cout << "Enter Staff Name" << endl;
    cin >> first;
    cin >> last;
    cout << "Enter ID Number" << endl;
    cin >> ID;
    cout << "Enter Job Title" << endl;
    cin.ignore();
    getline(cin, job);
    cout << "Enter Salary" << endl;
    cin >> salary;

    objStaff.setName(first,last);
    objStaff.setName(first,last);
    objStaff.setJobTitle(job);
    objStaff.setSalary(salary);
    objStaff.setID(ID);

    staff.push_back(objStaff);
}

/*
    Prompt user to enter staff id.
    Selected id if matched will be deleted.
    returns to menu
*/
void Staff::fireStaff(vector<Staff>& staff)
{
    int ID = 0;

    cout << "Enter ID for staff to fire" << endl;
    cin >> ID;
    for(unsigned int i = 0; i < staff.size(); i++)
    {
        if (staff[i].getID() == ID)
        {
            staff.erase (staff.begin()+i);
        }
    }
}

/*
    Prints out menu for staff.
    If user selects 7, will return to main menu.
*/
void Staff::printStafffMenu(vector<Staff>& staff)
{
	int selector = 0; // selects menu option menu
	do{
            std::cout << "Staff Menu\n\t" <<
			"1. Adjust Staff\n\t" <<
			"2. Print All Staff Information\n\t" <<
			"3. Print by ID number\n\t" <<
			"4. Print by Job type\n\t" <<
			"5. Hire New Staff\n\t" <<
			"6. Fire New Staff\n\t" <<
			"7. Return to Main Menu" <<
			endl;
			cin >> selector;

			switch(selector)
			{
				case 1:
				//call function to adjust staff members
				adjustStaff(staff);
				break;
				case 2:
				//call function print all staff
                printAllStaff(staff);
				break;
				case 3:
				//call function to print staff by ID
                printStaffJobID(staff);
				break;
				case 4:
				//call function to print staff by staff
				printStaffJobType(staff);
				break;
				case 5:
                //Function to prompt user to hire new staff
                hireNewStaff(staff);
				break;
				case 6:
				//function call to fire staff
				fireStaff(staff);
				break;
				default:
				    cout << "Please Enter a number from 1-6" << endl;
				break;
			}
		}
		while(selector!=7); // loops until we select option 6 to return to main menu
}
