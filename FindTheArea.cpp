#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
void myHeader(string name, int lab, string date, int question, string purpose)
{
	cout << "*********************************************************" << endl;
	cout << "			" << name << endl;
	cout << "			Date: " << date << endl;
	cout << "			Lab " << lab << " Question " << question << endl;
	cout << "			Purpose " << purpose << endl;
	cout << "*********************************************************" << endl << endl;
}
double area(double radius)
{
	return (radius * 3.14159);
}
double area(double width, double height)
{
	return (width*height);
}
double area(double base, double height, double half)
{
	return (base*height*half);
}
double area(double base1, double base2, double height, double half)
{
	return ((base1 + base2)*height*half);
}
void displayMenu()
{
	cout << "--------------------" << endl
		<< "1. Area of a circle" << endl
		<< "2. Area o a rectangle" << endl
		<< "3. Area of a triangle" << endl
		<< "4. Area of a trapezoid" << endl
		<< "5. Exit\n\n";
}

int main()
{
	// Program header
	myHeader("Daniel Au", 7, "November 26th", 3, "Find the area");

	// Variable initialization
	int choice = 0;
	bool programContinue = true;
	
	// Start
	while (programContinue)
	{
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		// Switch menu
		switch (choice)
		{
			case 1:
			{
					  double radius = 0;
					  cout << "Enter the radius of the circle: ";
					  cin >> radius;
					  cout << "\nThe area of the circle is " << area(radius);
					  cout << endl << endl;
					  break;
			}
			case 2:
			{
					  double width = 0;
					  double height = 0;
					  cout << "Enter the width of the rectangle: ";
					  cin >> width;
					  cout << "Enter the height of the rectangle: ";
					  cin >> height;
					  cout << "\nThe area of the rectangle is " << area(width, height);
					  cout << endl << endl;
					  break;
			}
			case 3:
			{
					  double base = 0;
					  double height = 0;
					  cout << "Enter the base of the triangle: ";
					  cin >> base;
					  cout << "Enter the height of the triangle: ";
					  cin >> height;
					  cout << "\nThe area of the triangle is " << area(base, height, 0.5);
					  cout << endl << endl;
					  break;
			}
			case 4:
			{
					  double base1 = 0;
					  double base2 = 0;
					  double height = 0;
					  cout << "Enter the first base length of the trapezoid: ";
					  cin >> base1;
					  cout << "Enter the second base length of the trapezoid: ";
					  cin >> base2;
					  cout << "Enter the height of the trapezoid: ";
					  cin >> height;
					  cout << "\nThe area of the trapezoid is " << area(base1, base2, height, 0.5);
					  cout << endl << endl;
					  break;
			}
			case 5:
			{
					  cout << "Goodbye!\n\n";
					  programContinue = false;
					  break;
			}
		}
	}
}
