#include "ConcessionStand.h"

ConcessionStand::ConcessionStand()
{

}

int ConcessionStand::getHotdogs()
{
    return m_hotdogs;
}

int ConcessionStand::getPeanuts()
{
    return m_peanuts;
}

int ConcessionStand::getBurgers()
{
    return m_burgers;
}

int ConcessionStand::getSoftDrinks()
{
    return m_softDrinks;
}

int ConcessionStand::getBeer()
{
    return m_beer;
}

int ConcessionStand::getJersey()
{
    return m_jersey;
}

double ConcessionStand::getHotdogPrices()
{
    return m_hotdogPrices;
}

double ConcessionStand::getPeanutPrices()
{
    return m_peanutPrices;
}

double ConcessionStand::getBurgerPrices()
{
    return m_burgerPrices;
}

double ConcessionStand::getSoftDrinkPrices()
{
    return m_softDrinkPrices;
}

double ConcessionStand::getBeerPrices()
{
    return m_beerPrices;
}

double ConcessionStand::getJerseyPrices()
{
    return m_jerseyPrices;
}


double ConcessionStand::getTotalSales()
{
    return m_totalSales;
}

void ConcessionStand::setHotdogs(int hotdog)
{
    m_hotdogs = hotdog;
}

void ConcessionStand::setPeanuts(int peanuts)
{
    m_peanuts = peanuts;
}

void ConcessionStand::setBurgers(int burger)
{
    m_burgers = burger;
}

void ConcessionStand::setSoftDrinks(int softDrinks)
{
    m_softDrinks = softDrinks;
}

void ConcessionStand::setBeer(int beer)
{
    m_beer = beer;
}

void ConcessionStand::setJersey(int jersey)
{
    m_jersey = jersey;
}

void ConcessionStand::setTotalSales(double totaleSales)
{
    m_totalSales = totaleSales;
}

void ConcessionStand::setHotdogPrices(double hotdogPrices)
{
    m_hotdogPrices = hotdogPrices;
}
void ConcessionStand::setPeanutPrices(double peanutPrices)
{
    m_peanutPrices = peanutPrices;
}
void ConcessionStand::setBurgerPrices(double burgerPrices)
{
    m_burgerPrices = burgerPrices;
}
void ConcessionStand::setSoftDrinkPrices(double softDrinkPrices)
{
    m_softDrinkPrices = softDrinkPrices;
}
void ConcessionStand::setBeerPrices(double beerPrices)
{
    m_beerPrices = beerPrices;
}
void ConcessionStand::setJerseyPrices(double jerseyPrices)
{
    m_jerseyPrices = jerseyPrices;
}

/*
    print total lifetime sales amount from the concession stand
*/
void ConcessionStand::printLifeTimeSales(vector<ConcessionStand>& stand)
{
    cout << "Life time sales is: $" << stand[0].getTotalSales()  << endl;
}


/*
    User will be prompt to select which product to order
    Once user select which product to order. User will enter the amount to order.
    If stand doesn't have enough inventory for user to order. Switch will exit prompting user with message
    If user has enough to order inventory, user will complete transaction.
    All data for vector will be updated. Such as total sells, deduct total inv from vector.
*/
void ConcessionStand::orderNewInventory(vector<ConcessionStand>& stand, vector<BankAccount>& bankAccount)
{
    int selector = 0, orderAmount = 0, invUpdate = 0;
    double totalSales = stand[0].getTotalSales(), cashOnHand = bankAccount[0].getCashOnHand();


    cout << "What item would you like to order" << endl;
    cout << "1. Hotdogs\n" << "2. Peanuts\n" << "3. Burgers\n" << "4. Soft Drinks\n" << "5. Beer\n" << "6. Jerseys" << endl;
    cin >> selector;
    switch(selector)
    {
    case 1:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getHotdogPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);

            invUpdate = stand[0].getHotdogs() + orderAmount;

            stand[0].setHotdogs(invUpdate);
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    case 2:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getPeanutPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Peanuts. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);

            invUpdate = stand[0].getPeanuts() + orderAmount; // math to get total inv updated

            stand[0].setPeanuts(invUpdate); // updates vector inv
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    case 3:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getBurgerPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Burgers. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);
            invUpdate = stand[0].getBurgers() + orderAmount;

            stand[0].setBurgers(invUpdate);
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    case 4:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getSoftDrinkPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Peanuts. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);
            invUpdate = stand[0].getSoftDrinks() + orderAmount;

            stand[0].setSoftDrinks(invUpdate);
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    case 5:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getBeerPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Peanuts. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);
            invUpdate = stand[0].getBeer() + orderAmount;

            stand[0].setBeer(invUpdate);
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    case 6:
        cout << "Enter Amount to order." << endl;
        cin >> orderAmount;

        totalSales = (orderAmount * stand[0].getJerseyPrices())/2;
        if(totalSales <= cashOnHand)
        {
            cout << "You ordered " << orderAmount << " Peanuts. Your total is $" << totalSales << "."  << endl;
            cashOnHand -= totalSales;
            cout << "You have $" << cashOnHand << " cash on hand left." << endl;
            bankAccount[0].setCashOnHand(cashOnHand);
            invUpdate = stand[0].getJersey() + orderAmount;

            stand[0].setJersey(invUpdate);
        }else
        {
            cout << "You don't have enough cash on hand" << endl;
        }
        break;
    default:
        cout << "Please select a number 1-6" << endl;
        break;
    }
}


/*
    Functions allows user to sell items.
    User will select what to sell from a list of items.
    Once the item is picked, user will select the number of items to sell.
    If item isnt on hand, user will get an error message and go back to main menu.
    after the sell, bank account will change.
*/
void ConcessionStand::sellInventory(vector<ConcessionStand>& stand, vector<BankAccount>& bankAccount)
{
    int selector = 0, orderAmount = 0, invUpdate = 0;
    double totalSales, cashOnHand = bankAccount[0].getCashOnHand();


    cout << "What item would you like to order" << endl;
    cout << "1. Hotdogs\n" << "2. Peanuts\n" << "3. Burgers\n" << "4. Soft Drinks\n" << "5. Beer\n" << "6. Jerseys" << endl;
    cin >> selector;
    switch(selector)
    {
    case 1:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getHotdogs() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getHotdogPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getHotdogs() - orderAmount;

        stand[0].setHotdogs(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }else
    {
        cout << "You don't have enough invtory to sell this item!" << endl;
    }
        break;
    case 2:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getPeanuts() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getPeanutPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getPeanuts() - orderAmount;

        stand[0].setPeanuts(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }
        break;
    case 3:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getBurgers() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getBurgerPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getBurgers() - orderAmount;

        stand[0].setBurgers(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }
        break;
    case 4:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getSoftDrinks() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getSoftDrinkPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getSoftDrinks() - orderAmount;

        stand[0].setSoftDrinks(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }
        break;
    case 5:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getBeer() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getBeerPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getBeer() - orderAmount;

        stand[0].setBeer(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }
        break;
    case 6:
        cout << "Enter Amount to sell." << endl;
        cin >> orderAmount;
    if(stand[0].getJersey() >= orderAmount)
    {
        totalSales = orderAmount * stand[0].getJerseyPrices();

        cout << "You sold " << orderAmount << " Hotdogs. Your total is $" << totalSales << "."  << endl;
        cashOnHand += totalSales;
        cout << "You have $" << cashOnHand << " cash on hand." << endl;
        bankAccount[0].setCashOnHand(cashOnHand);

        invUpdate = stand[0].getJersey() - orderAmount;

        stand[0].setJersey(invUpdate);

        totalSales += stand[0].getTotalSales(); // addes our total sells to sells total we have stored in vector
        stand[0].setTotalSales(totalSales); // sets our total sells after user sell product into vector
    }
        break;
    default:
        cout << "Please select a number 1-6" << endl;
        break;
    }
}

/*
    Function is called in main.cpp
    function reads in all out data store in concession.txt file.
*/
void ConcessionStand::loadConcessionStandData(vector<ConcessionStand>& stand)
{
    int NumHotDogs, NumPeanuts, NumBurger, NumDrinks, NumBeer, NumJersey;
    double HotDogPrice,PeanutsPrice, BurgerPrice, DrinkPrice, BeerPrice,JerseyPrice, TotalSales;

    ConcessionStand objConcessionStand;

	ifstream input("concession.txt");
	while(!input.eof()) // while loop will load in all data inside "ticket.txt file until end of file.
	{
		input >> NumHotDogs;
		objConcessionStand.setHotdogs(NumHotDogs);
		input >> HotDogPrice;
		objConcessionStand.setHotdogPrices(HotDogPrice);
		input >> NumPeanuts;
		objConcessionStand.setPeanuts(NumPeanuts);
		input >> PeanutsPrice;
		objConcessionStand.setPeanutPrices(PeanutsPrice);
		input >> NumBurger;
		objConcessionStand.setBurgers(NumBurger);
		input >> BurgerPrice;
		objConcessionStand.setBurgerPrices(BurgerPrice);
		input >> NumDrinks;
		objConcessionStand.setSoftDrinks(NumDrinks);
		input >> DrinkPrice;
		objConcessionStand.setSoftDrinkPrices(DrinkPrice);
		input >> NumBeer;
		objConcessionStand.setBeer(NumBeer);
		input >> BeerPrice;
		objConcessionStand.setBeerPrices(BeerPrice);
		input >> NumJersey;
		objConcessionStand.setJersey(NumJersey);
		input >> JerseyPrice;
		objConcessionStand.setJerseyPrices(JerseyPrice);
		input >> TotalSales;
		objConcessionStand.setTotalSales(TotalSales);

        stand.push_back(objConcessionStand); // stores all data inside vector obj

	}
    input.close(); // close our file after all data is loaded.
}


/*
    prints out all data stored in out vector to the console.
*/
void ConcessionStand::printAllConcessionStandInfo(vector<ConcessionStand>& stand)
{
    for(unsigned int i = 0; i < stand.size(); i++)
    {
        cout << "Number Hotdogs: " << stand[i].getHotdogs() << "\nHotdog Prices: $" << stand[i].getHotdogPrices()
        << "\nNumber Peanuts: " << stand[i].getPeanuts() << "\nPeanut Prices: $" << stand[i].getPeanutPrices()
        << "\nNumber Burgers: " << stand[i].getBurgers() << "\nBurger Prices: $" << stand[i].getBurgerPrices()
        << "\nNumber Soft Drinks: " << stand[i].getSoftDrinks() << "\nSoft Drink Prices: $" << stand[i].getSoftDrinkPrices()
        << "\nNumber Beer: " << stand[i].getBeer() << "\nBeer Prices: $" << stand[i].getBeerPrices()
        << "\nNumber Jerseys: " << stand[i].getJersey() << "\nJersey Prices $" << stand[i].getJerseyPrices()
        << "\nTotal Sales: " << stand[i].getTotalSales() << endl << endl;
    }
}




//Show all ticket’s info after after we generate a event name
void ConcessionStand::printConcessionStandMenu(vector<ConcessionStand>& stand, vector<BankAccount>& bankAccount)
{
	int selector = 0; // selects menu option menu
	do{
			cout << "Concession Stand Manager\n\t" <<
			"1. Show lifetime sales of Concession Stand\n\t" <<
			"2. Order new inventory\n\t" <<
			"3. Sell Items\n\t" <<
			"4. View Inventory\n\t" <<
			"5. Return to Main Menu\n\t" <<
			endl;
			cin >> selector;

			switch(selector)
			{
				case 1:
				//print total lifetime sales amount from the concession stand
				printLifeTimeSales(stand);
				break;
				case 2:
				//order new inventory and adjust the bank account
				orderNewInventory(stand,bankAccount);
				break;
				case 3:
				//sell items from the concession stand
				sellInventory(stand,bankAccount);
				break;
				case 4:
				//call function for able to sell/refund a ticket (adjust bank account accordingly)
				printAllConcessionStandInfo(stand);
				break;
				default:
				    cout << "Please enter a number 1-5" << endl;
				break;
			}
		}
		while(selector!=5); // loops until we select option 6 to return to main menu
}
