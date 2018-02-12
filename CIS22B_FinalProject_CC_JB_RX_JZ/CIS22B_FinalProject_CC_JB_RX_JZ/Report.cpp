#define _CRT_SECURE_NO_WARNINGS
#include "report.h"
#include "Booklist.h"
#include "Book.h"

#include <iostream>

using namespace std;
/*
Pseudocode
have report function that accepts booklist bkl as parameter
print out menu
ask for userinput to chose an option
while loop while userinput not equal to 7
	if userinput equals 1
		create module pointer
		set module pointer to bkl
		call print function using module pointer
	if userinput equals 2
		call print by cost using bkl
	if userinput equals 3
		call print by price using bkl
	if userinput equals 4
		create booklist a
		set booklist a to booklist bkl
		call sortByQuantity using a
		print a
	if userinput equals 5
		create booklist a
		set booklist a to booklist bkl
		call sortByCost using a
		print a
	if userinput equals 6
		create booklist a
		set booklist a to booklist bkl
		call sortByAge using a
		print a
	if user input equals 7
		break from while loop
break from function
	
*/
void report(Booklist bklist) {
	int userInteractionReport;
	//Report Module
	cout << "Serendpity Booksellers" << endl;
	cout << "Book information" << endl << endl;
	cout << "Welcome to the Report Module" << endl;
	cout << "1: Inventory Listing" <<  endl;    
	cout << "2: Inventory Wholesale Value" << endl;
	cout << "3: Inventory Retail Value" << endl;
	cout << "4: Listing by Quantity" << endl;
	cout << "5: Listing by Cost" << endl;
	cout << "6: Listing by Age" << endl;;
	cout << "7: Return to Main Menu" << endl;

	cout << "Please Enter a number to choose which reports to receive" << endl;
	cin >> userInteractionReport;

	while (userInteractionReport != 7) {
		if (userInteractionReport == 1) {
			cout << "Printing entire inventory" << endl;
			//Polymorphism demonstration
			Module * pb;
			pb = &bklist;
			//yay for print functions!
			pb->print();
		}
		else if (userInteractionReport == 2) {
			//more print functions!
			bklist.printByCost();
		}
		else if (userInteractionReport == 3) {
			//print, print, print!
			bklist.printByPrice();
		}
		else if (userInteractionReport == 4) {
			Booklist a;
			a = bklist;
			a.sortByQuantity();
			
			cout << "Printing by Quantity" << endl;
			a.print();
		}
		else if (userInteractionReport == 5) {
			Booklist a;
			a = bklist;

			a.sortByCost();
			cout << "Printing by Cost" << endl;
			a.print();
		}
		else if (userInteractionReport == 6) {
			Booklist a;
			a = bklist;

			a.sortByAge();
			cout << "Printing by Age" << endl;
			a.print();
		}
		else {
			cout << "Error: Please enter a number between 1-7" << endl;
		}
		cout << "Welcome to the Report Module" << endl;
		cout << "1: Inventory Listing" << endl;
		cout << "2: Inventory Wholesale Value" << endl;
		cout << "3: Inventory Retail Value" << endl;
		cout << "4: Listing by Quantity" << endl;
		cout << "5: Listing by Cost" << endl;
		cout << "6: Listing by Age" << endl;;
		cout << "7: Return to Main Menu" << endl;

		cout << "Please Enter a number to choose which reports to receive" << endl;
		cin >> userInteractionReport;
	}
}
