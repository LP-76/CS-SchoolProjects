#ifndef ConcessionStand_h
#define ConcessionStand_h

#include "BankAccount.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

class ConcessionStand //This ADT contains all information related to the sale of food, drinks, and merchandise.
{
private:
	int m_hotdogs; //
    int m_peanuts; // $1
	int m_burgers; // $5
	int m_softDrinks; //1.50
	int m_beer; // $8
	int m_jersey; //$100

	double m_hotdogPrices; // $3
    double m_peanutPrices; // $1
	double m_burgerPrices; // $5
	double m_softDrinkPrices; //1.50
	double m_beerPrices; // $8
	double m_jerseyPrices; //$100
	double m_totalSales;

	void printLifeTimeSales(vector<ConcessionStand>&); // prints out out life time of sales to console
	void orderNewInventory(vector<ConcessionStand>&,vector<BankAccount>&); //prompts user to order new inv. changes bank account when ordering
	void printAllConcessionStandInfo(vector<ConcessionStand>&); // prints out all out concession stand info
    void sellInventory(vector<ConcessionStand>&,vector<BankAccount>&); // lets user sell inv to customers
public:
	ConcessionStand();
	void printConcessionStandMenu(vector<ConcessionStand>&,vector<BankAccount>&); // print out menu for concession Stand
	void loadConcessionStandData(vector<ConcessionStand>&); // loads in data from txt file


    int getHotdogs();
    int getPeanuts();
    int getBurgers();
    int getSoftDrinks();
    int getBeer();
    int getJersey();

    double getTotalSales();
    double getHotdogPrices();
    double getPeanutPrices();
    double getBurgerPrices();
    double getSoftDrinkPrices();
    double getBeerPrices();
    double getJerseyPrices();

    void setHotdogs(int);
    void setPeanuts(int);
    void setBurgers(int);
    void setSoftDrinks(int);
    void setBeer(int);
    void setJersey(int);

    void setTotalSales(double);
    void setHotdogPrices(double);
    void setPeanutPrices(double);
    void setBurgerPrices(double);
    void setSoftDrinkPrices(double);
    void setBeerPrices(double);
    void setJerseyPrices(double);
};
#endif
