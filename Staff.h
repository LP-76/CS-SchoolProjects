#ifndef Staff_h
#define Staff_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;


class Staff //This ADT contains all information related to the management of staff
{
private:
	int m_id;
	string m_name;
	string m_jobTitle;
	double m_salary;
	// FOLLOWING MEMBER FUNCTIONS ARE PRIVATE. ONLY USED BY OTHER FUNCTION IN THIS CLASS.
    void adjustStaff(vector<Staff>&); // adjust staffs data members. Will not change ID.
    void printAllStaff(vector<Staff>&); // prints out all staff members on file
    void printStaffJobID(vector<Staff>&); // prints out staff with ID entered by the user
    void printStaffJobType(vector<Staff>&); //prints out staff with job title entered by the user
    void hireNewStaff(vector<Staff>&); // lets user enter new staff members
    void fireStaff(vector<Staff>&); // lets user delete staff member based on ID entered
public:
	Staff();
	void printStafffMenu(vector<Staff>&); //print out menu for staff.
	void loadStaffData(vector<Staff>&); // loads data into vectors when program starts

    //accessor functions
    int getID();
    string getName();
    string getJobTitle();
    double getSalary();

	//mutator functions
    void setID(int);
    void setName(string, string);
    void setJobTitle(string);
    void setSalary(double);
};
#endif
