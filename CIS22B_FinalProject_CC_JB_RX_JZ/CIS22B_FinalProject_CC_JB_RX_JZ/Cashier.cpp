#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>
#include "cashier.h"
#include <time.h> // display date
#include "Booklist.h"

using namespace std;
/*
Psuedocode
cashier function which accepts booklist object
create variables for sales tax, taxsum, and totalsum
variables for a title, isbn, quantity, price, date
using time.h module to read date
create book pointer and set it to book array in booklist object
print out welcome to cash module
ask user to chose an option
read userinput
while userinput not equal 2
if userinput 1
	ask user for title of book
	search for title of book
	if title not found
		print error message
		reprompt for book title
	else if title find
		ask for quantity to be sold
		use sell function in booklist 
		use sales_tax, quantity, and price to calculate taxsum
		calculate totalsum using taxsum and total
		print out results into menu
		use sell function in booklist
		reset book pointer to changed array in booklist
if userinput 2
	exit while loop

*/
Booklist cashier(Booklist bklist) {
	const double SALES_TAX = .06; //Set sales tax to .06
	double calcTax;
	double totalCash;
	
	int userInteractionCashReg;

	string isbn, title;
	int quantity, index;
	//default price for right now
	double price, sub, tax, total;
	char date[9];

	//create booklist to use in the module
	Book * pbklist;
	pbklist = bklist.getBooklist();

	_strdate(date); //read date
		
	cout << "Welcome to the Cash Register Module" << endl;
	
	//Inside Cash Register Module
	cout << "Please choose an option:" << endl;
	cout << "1: Sell a book" << endl;
	cout << "2: Exit Cash Register Module" << endl;
	cin >> userInteractionCashReg;
	while (userInteractionCashReg != 2) {
		if (userInteractionCashReg == 1) {
			cout << "Enter title of book: " << endl;
			cin.ignore();
			getline(cin, title);
			index = bklist.searchByTitle(title);
			while (index == -1) {
				cout << "Couldn't find the book in inventory, please enter title again: " << endl;
				getline(cin, title);
				index = bklist.searchByTitle(title);
			}
			cout << "Enter quantity of books: " << endl;
			cin >> quantity;
			while (quantity > (pbklist + index)->getQuantity()) {
				cout << "Quantity is greater than quantity in inventory! Please reenter quantity: " << endl;
				cin >> quantity;
			}
			//Calculations
			price = (pbklist + index)->getPrice();
			sub = price * quantity;
			tax = sub * SALES_TAX;
			total = sub + tax;

			isbn = (pbklist + index)->getIsbn();

			cout << "Serendipity Booksellers" << endl;
			cout << "Cashier Module" << endl << endl;
			cout << "Date: " << date << endl << endl;
			cout << "Qty\tISBN\t\tTitle\t\t\tPrice\t\tTotal" << endl;
			cout << "______________________________________________________________________________" << endl;
			cout << quantity << "\t";
			cout << left << setw(8) << isbn << "\t";
			cout << left << setw(16) << title << "\t$";
			cout << fixed << showpoint << right << setprecision(2);
			cout << left << setw(8) << price << "\t$";
			cout << setw(8) << sub;
			cout << endl << endl << endl;
			
			cout << "\t\tSubtotal\t\t\t\t\t$";
			cout << setw(6) << sub << endl;
			cout << "\t\tTax\t\t\t\t\t\t$" ;
			cout << setw(6) << tax << endl;
			cout << "\t\tTotal\t\t\t\t\t\t$" ;
			cout << setw(6) << total << endl << endl;
			
			bklist.sellBook(title, quantity);
			pbklist = bklist.getBooklist();
		}
		else {
			cout << "Error: Please enter a number between 1-2" << endl;
			// while loop
		}
		cout << "Please choose an option:" << endl;
		cout << "1: Sell a book" << endl;
		cout << "2: Exit Cash Register Module" << endl;
		cin >> userInteractionCashReg;
	}
	return bklist;
}
