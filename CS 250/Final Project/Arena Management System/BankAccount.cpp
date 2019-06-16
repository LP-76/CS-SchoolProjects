#include "BankAccount.h"

BankAccount::BankAccount()
{

}

double BankAccount::getTotalSales()
{
    return m_totalSales;
}

double BankAccount::getCashOnHand()
{
    return m_cashOnHand;
}

double BankAccount::getDebt()
{
    return m_debt;
}

void BankAccount::setTotalSales(double totalSales)
{
    m_totalSales = totalSales;
}

void BankAccount::setCashOnHand(double cashOnHand)
{
    m_cashOnHand = cashOnHand;
}

void BankAccount::setDebt(double debt)
{
    m_debt = debt;
}

void BankAccount::loadBankAccountData(vector<BankAccount>& bankAccount) // loads in all data from "staff.txt file when program starts
{
    double totalSales, cashOnHand, debt;

    BankAccount objBankAccount;

	ifstream input("bank.txt");
	while(!input.eof()) // while loop will load in all data inside "staff.txt file until end of file.
	{
		input >> totalSales;
		objBankAccount.setTotalSales(totalSales);
		input >> cashOnHand;
		objBankAccount.setCashOnHand(cashOnHand);
		input >> debt;
		objBankAccount.setDebt(debt);

        bankAccount.push_back(objBankAccount); // stores all data inside vector obj
	}
    input.close(); // close our file after all data is loaded.
}

void BankAccount::printBankAccountBalance(vector<BankAccount>& bankAccount)
{
    cout << "Total Sales: " << bankAccount[0].getTotalSales() << "\nCash On Hand: "
    << bankAccount[0].getCashOnHand() << "\nDebt: " << bankAccount[0].getDebt() << endl << endl;
}

/*
    Allows the user to update all values stored inside bank account.
*/
void BankAccount::adjustBankAccount(vector<BankAccount>& bankAccount)
{
    double totalSales, cashOnHand,debt;

    cout << "Enter Total Sales" << endl;
    cin >> totalSales;
    cout << "Enter Cash on Hand" << endl;
    cin >> cashOnHand;
    cout << "Enter total debt" << endl;
    cin >> debt;

    bankAccount[0].setTotalSales(totalSales);
    bankAccount[0].setCashOnHand(cashOnHand);
    bankAccount[0].setDebt(debt);
}

/*
    Cals and stores the number of tickets we sell inside bank account when called.
*/
void BankAccount::numTicketSales(vector<BankAccount>& bankAccount, int& total)
{
    int sales;

    sales = bankAccount[0].getTotalSales() + (total * 45);

    bankAccount[0].setTotalSales(sales);
}

void BankAccount::calculateMonthsTicketSales(vector<BankAccount>& bankAccount)
{
    cout << "Total Sales is: " << bankAccount[0].getTotalSales() << endl << endl;
}
/*
    Prompts user to enter amount of debt to pay.
    Takes the amount user enters and pays off debt.
*/
void BankAccount::payoffBankAccount(vector<BankAccount>& bankAccount)
{
    double cashToPay = 0;
    double cashOnHand = bankAccount[0].getCashOnHand();
    double debt = bankAccount[0].getDebt();

    do{
        cout << "Current debt is $" << bankAccount[0].getDebt() << "." << endl;
        cout << "You currently have $" << bankAccount[0].getCashOnHand() << "." << endl;
        cout << "How much debt would you like to pay?" << endl;
        cin >> cashToPay;

        if(cashToPay <= bankAccount[0].getCashOnHand())
        {
            debt -= cashToPay;
            cashOnHand -= cashToPay;
            cout << "You paid $" << cashToPay << "." << "\nRemaining debt is $" << debt << "." << endl;
            bankAccount[0].setDebt(debt); // sets the amount debt left back to vector
            bankAccount[0].setCashOnHand(cashOnHand); // set the amount cash on hand left back into vector
            break;
        }else
        {
            cout << "The amount paying exceeds cash on hand!" << endl;
        }
    }while(true);

}

void BankAccount::timeForPayoff(vector<BankAccount>& bankAccount) // calcs the payoff from dividing debt by cash on hand
{
    double cashOnHand = bankAccount[0].getCashOnHand();
    double debt = bankAccount[0].getDebt();
    double payoffTime = 0;

    payoffTime = debt/cashOnHand;

    cout << "It will take " << payoffTime << " months to pay off remaining debts" << endl << endl;
}

//Show all ticket’s info after after we generate a event name
void BankAccount::printBankAccountMenu(vector<BankAccount>& bankAccount)
{
	int selector = 0; // selects menu option menu
	do{
			cout << "Bank Account Manager\n\t" <<
			"1. Show Bank Account balance\n\t" <<
			"2. Adjust Bank Account Balance\n\t" <<
			"3. Show Monthly Sales\n\t" <<
			"4. Payoff Debts\n\t" <<
			"5. Show time to payoff debts\n\t" <<
			"6. Return to Main Menu\n\t" <<
			endl;
			cin >> selector;

			switch(selector)
			{
				case 1:
				//call function for show all ticket’s info
				printBankAccountBalance(bankAccount);
				break;
				case 2:
				//call function for show all available tickets
				adjustBankAccount(bankAccount);
				break;
				case 3:
				//show total ticket sales
                calculateMonthsTicketSales(bankAccount);
				break;
				case 4:
				//call function for paying off debt (adjust bank account accordingly)
				payoffBankAccount(bankAccount);
				break;
				case 5:
				//calculate pay off for debt
				timeForPayoff(bankAccount);
				break;
				default:
				    cout << "Please enter a number 1-6" << endl;
				break;
			}
		}
		while(selector!=6); // loops until we select option 6 to return to main menu
}
