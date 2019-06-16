#include "Parking.h"
#include "BankAccount.h"


Parking::Parking()
{

}

int Parking::getSectionNumber()
{
    return m_sectionNumber;
}

int Parking::getParkingSpaceNumber()
{
    return m_parkingSpaceNumber;
}

double Parking::getPrice()
{
    return m_price;
}

bool Parking::getAvailable()
{
    return m_available;
}

void Parking::setSectionNumber(int section)
{
    m_sectionNumber = section;
}

void Parking::setParkingSpaceNumber(int parkingSpaceNumber)
{
    m_parkingSpaceNumber = parkingSpaceNumber;
}

void Parking::setPrice(double price)
{
    m_price = price;
}

void Parking::setAvailable(bool available)
{
    m_available = available;
}

//reads in all of our data and stores it.
void Parking::printParkingInfo(vector<Parking>& parking)
{
    for(unsigned int j = 0; j < parking.size(); j++)
    {
        cout << "Section Number: " << parking[j].getSectionNumber()
        << "\nParking Space Number: " << parking[j].getParkingSpaceNumber()
        << "\nPrice: " << parking[j].getPrice()
        << "\nAvailability: " << parking[j].getAvailable()
        << endl << endl;
    }
}

void Parking::loadParkingData(vector<Parking>& parking)
{
    int i = 0;
    int section, parkingSpaceNumber;
    double price;
    bool available;

    Parking objParking;

	ifstream input("parking.txt");
	while(!input.eof()) // while loop will load in all data inside "ticket.txt file until end of file.
	{
		input >> section;
		objParking.setSectionNumber(section);
		input >> parkingSpaceNumber;
		objParking.setParkingSpaceNumber(parkingSpaceNumber);
		input >> price;
		objParking.setPrice(price);
		input >> available;
		objParking.setAvailable(available);

        parking.push_back(objParking); // stores all data inside vector obj
		i++;
	}
    input.close(); // close our file after all data is loaded.
}

void Parking::printParkingSection(vector<Parking>& parking) //print the info of a certain parking section
{
    int parkingSection;

    cout << "Enter Parking Section" << endl;
    cin >> parkingSection;

    for(unsigned int i = 0; i < parking.size(); i++)
    {
        if(parking[i].getSectionNumber() == parkingSection)
        {
            cout << "Section Number: " << parking[i].getSectionNumber()
            << "\nParking Space Number: " << parking[i].getParkingSpaceNumber()
            << "\nPrice: " << parking[i].getPrice()
            << "\nAvailability: " << parking[i].getAvailable()
            << endl << endl;
        }
    }
}

void Parking::printAvailableParking(vector<Parking>& parking) // outputs parking spaces that are available
{
    for(unsigned int i = 0; i < parking.size(); i++)
    {
        if(parking[i].getAvailable() == 1) // if we have a 1 in out available variable, then we output its available
        {
            cout << "Section Number: " << parking[i].getSectionNumber()
            << "\nParking Space Number: " << parking[i].getParkingSpaceNumber()
            << "\nPrice: " << parking[i].getPrice()
            << "\nAvailability: " << parking[i].getAvailable()
            << endl << endl;
        }
    }
}

void Parking::adjustParkingAvailability(vector<Parking>& parking,vector<BankAccount>& bankAccount) // function will change available tickets. sell or refund
{
    int sectionNumber,parkingSpaceNumber, availableSelect = 0;
    double totalSales = bankAccount[0].getTotalSales();
    bool available = 0;

    cout << "Enter Section Number" << endl;
    cin >> sectionNumber;
    cout << "Enter Parking Space Number" << endl;
    cin >> parkingSpaceNumber;
    cout << "Please enter 1 or 2\n" << "1. Selling Ticket\n" << "2. Refund Ticket" << endl;
    cin >> availableSelect;

    if(availableSelect == 1) // selects if bool should be one or zero. one = sold, two = refund
    {
        available = 0;
        totalSales += 10;
    }else if(availableSelect == 2)
    {
        available = 1;
        totalSales -= 10;
    }

    for(unsigned int i = 0; i < parking.size(); i++)
    {
        if (sectionNumber == parking[i].getSectionNumber())
        {
            if(parkingSpaceNumber == parking[i].getParkingSpaceNumber())
            {
                parking[i].setAvailable(available);
            }
        }
    }

    bankAccount[0].setTotalSales(totalSales);
}

//Show all Parking info after after we generate a event name
void Parking::printParkingMenu(vector<Parking>& parking,vector<BankAccount>& bankAccount)
{
	int selector = 0; // selects menu option menu
	do{
			std::cout << "Parking Manager\n\t" <<
			"1. Show all Parking Information\n\t" <<
			"2. Show Parking space at certain parking section\n\t" <<
			"3. Show Parking space available\n\t" <<
			"4. Change Parking space availability\n\t" <<
			"5. Return to Main Menu\n\t" <<
			std::endl;
			cin >> selector;

			switch(selector)
			{
				case 1:
				//call function for show all Parking info
				printParkingInfo(parking);
				break;
				case 2:
				//call function for print the info of a certain parking section
				printParkingSection(parking);
				break;
				case 3:
				//call function for show all unavailable tickets
				printAvailableParking(parking);
				break;
				case 4:
				//call function for able to sell/refund a ticket (adjust bank account accordingly)
				adjustParkingAvailability(parking, bankAccount);
				break;
				default:
				    cout << "Please enter a number 1-4" << endl;
				break;
			}
		}
		while(selector!=5); // loops until we select option 6 to return to main menu
}
