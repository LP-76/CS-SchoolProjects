#ifndef BankAccout_h
#define BankAccout_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class BankAccount //This ADT contains all information related to the management of finances.
{
private:
	double m_totalSales;
	double m_cashOnHand;
	double m_debt;

    void printBankAccountBalance(vector<BankAccount>&); //prints out all bank account info
    void adjustBankAccount(vector<BankAccount>&); //allows user to edit bank account
    void calculateMonthsTicketSales(vector<BankAccount>&); // prints out total sells of tickets to console
    void payoffBankAccount(vector<BankAccount>&); // allows user to pay off bank account balance
    void timeForPayoff(vector<BankAccount>&); // calculate the amount of months to pay off debt
public:
	BankAccount();
	void printBankAccountMenu(vector<BankAccount>&); // prints out menu for Bank Account management
    void loadBankAccountData(vector<BankAccount>&); // loads data from bank.txt file into vector
    void numTicketSales(vector<BankAccount>&, int&); // gets total number of tickets sold, multi it by 45. add it into bankAccount vector

	double getTotalSales();
	double getCashOnHand();
	double getDebt();

	void setTotalSales(double);
	void setCashOnHand(double);
	void setDebt(double);

};
#endif
