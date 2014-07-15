#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void myHeader(string name, int lab, string date, int question, string purpose);
void displayMenu();
void displayBusRoute(int list[5][5]);
int totalPassengers(int list[5][5], int inputDay);
int totalPassengersRoute(int list[5][5], int inputRoute);
void maxPassengers(int list[5][5]);
void minPassengers(int list[5][5]);
void inputBusRoute(int list[5][5]);


int main()
{
	// Program information
	myHeader("Daniel Au", 7, "November 26th", 1, "Bus Route");

	// Initialization variables0
	bool programContinue = true;
	int choice = 0;
	int busRoute[5][5] = { 0 };


	// Program loop
	while (programContinue)
	{

	// Display the menu and prompt for the choice
	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
	cout << "\n\n";

	// Program menu switch for menu

		switch (choice)
		{
			case 1:
			{
					  inputBusRoute(busRoute);
					  cout << "\n\nDone!\n";
					  break;

			}
			case 2:
			{
					  displayBusRoute(busRoute);
					  break;
			}
			case 3:
			{
					  int day;
					  cout << "Enter day: ";
					  cin >> day;
					  cout << "\nTotal number of passengers for day " << day << " is: " << totalPassengers(busRoute, day) << "\n\nDone!\n\n";
					  break;
			}
			case 4:
			{
					  int route;
					  cout << "Enter route: ";
					  cin >> route;
					  cout << "\nTotal number of passengers for route " << route << " is: " << totalPassengersRoute(busRoute, route) << "\n\nDone!\n\n";
					  break;
			}
			case 5:
			{
					  maxPassengers(busRoute);
					  break;
			}
			case 6:
			{
					  minPassengers(busRoute);
					  break;
			}

			case 7:
			{
					  programContinue = false;
					  cout << "Goodbye!\n\n";
					  break;
			}
		}
	}

}

// Display functions
void myHeader(string name, int lab, string date, int question, string purpose)
{
	cout << "*********************************************************" << endl;
	cout << "			" << name << endl;
	cout << "			Date: " << date << endl;
	cout << "			Lab " << lab << " Question " << question << endl;
	cout << "			Purpose " << purpose << endl;
	cout << "*********************************************************" << endl << endl;
}
void displayMenu()
{
	cout << "======================================================" << endl
		<< "1. Input bus data" << endl
		<< "2. Display bus route information" << endl
		<< "3. Print the total number of passengers in a day" << endl
		<< "4. Print the total number of passengers for a route" << endl
		<< "5. Print the max number of passengers" << endl
		<< "6. Print the min number of passengers" << endl
		<< "7. Exit" << endl << endl;

}

// Menu functions
void inputBusRoute(int list[5][5])
{
	for (int i = 0; i <= 4; i++)
	{
		cout << "Enter data for day " << i + 1 << ": ";
		for (int j = 0; j <= 4; j++)
		{
			cin >> list[i][j];
		}
		cout << endl;
	}
}

void displayBusRoute(int list[5][5])
{
	cout << endl;
	cout << "|-----------|-----------|-----------|-----------|-----------|-----------|" << endl;
	cout << "| Bus Route |    Mon    |    Tues   |    Wed    |   Thurs   |    Fri    |" << endl;
	cout << "|-----------|-----------|-----------|-----------|-----------|-----------|" << endl;
	for (int i = 0; i <= 4; i++)
	{
		cout << "| " << i + 1 << "         |";
		for (int j = 0; j <= 4; j++)
		{
			cout << setw(6) << list[i][j];
			cout.width(6);
			cout << "|";
		}
		cout << endl << "|-----------|-----------|-----------|-----------|-----------|-----------|" << endl;
	}
	cout << "\n\nDone!\n\n";
}
int totalPassengers(int list[5][5], int inputDay)
{
	int adjustedDay = inputDay - 1;
	int sum = 0;
	for (int i = 0; i <= 4; i++)
	{
		sum += list[i][adjustedDay];
	}
	return sum;
}
int totalPassengersRoute(int list[5][5], int inputRoute)
{
	int adjustedRoute = inputRoute - 1;
	int sum = 0;
	for (int i = 0; i <= 4; i++)
	{
		sum += list[adjustedRoute][i];
	}
	return sum;
}
void maxPassengers(int list[5][5])
{
	int max = list[0][0];
	int route = 0;
	int day = 0;

	for (int row = 0; row <= 4; row++)
	{
		for (int column = 0; column <= 4; column++)
		{
			if ((list[row][column]) > max)
			{
				max = list[row][column];
				route = row;
				day = column;
			}
		}
	}
	cout << "Max number of passengers is " << max << " on route " << route+1 << ", day " << day+1;
	cout << "\n\nDone!\n\n";

}
void minPassengers(int list[5][5])
{
	int min = list[0][0];
	int route = 0;
	int day = 0;

	for (int row = 0; row <= 4; row++)
	{
		for (int column = 0; column <= 4; column++)
		{
			if ((list[row][column]) < min)
			{
				min = list[row][column];
				route = row;
				day = column;
			}
		}
	}
	cout << "Min number of passengers is " << min << " on route " << route+1 << ", day " << day+1;
	cout << "\n\nDone!\n\n";
}
