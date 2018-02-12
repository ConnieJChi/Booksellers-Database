#define _CRT_SECURE_NO_WARNINGS

//Inventory Module
#include <iostream>

#include "inventory.h"
#include "Booklist.h"

using namespace std;
template<class T>
void getInput(T& var)
{
	cin >> var;
}
//overload function for strings, since virtual getInput function
//doesn't work for strings
void getInput(string& var)
{
	getline(cin, var);
}
/*
inventory function to be used in main, takes a booklist object b
create variables for userinteraction and a pointer for book array
set pointer pb equal to book array in b
print out welcome for inventory module
ask user for what they want to do
read user input
while user input not equal 5
if user input equals 1
	another while loop
	ask user for book title
	search for book title
	if title found ask user what they want to change 
	read into
	if i is between 1-8, ask user what they want to change the variable to and set the variable to the input
	if i equals 9
	exit while loop
if user input equals 2
	ask user for properties of new book
	create new book bk
	search the booklist array until an empty book is found
	set bk to the first empty book found in the array
if user input equals 3
	ask user for book title
	search for the book with the user-inputted book title
	if title is found 
		set the book equal to an empty book
		move over the other books in the array down
		set the book in the last index to new book
	else 
		print out error statement
		reprompt user for new book title
if user input equals 4
	ask user for book title
	search for book with user-inputted book title
	if title is found
		print book
	else
		print out error statement
		reprompt user for new book title
if user input equals 5
exit while loop

*/
Booklist inventory(Booklist bklist) {

	int userInteractionInventory;
	int userIntEdit;
	Book * pbklist;
	pbklist = bklist.getBooklist();

	cout << "Welcome to the Inventory Module" << endl;
	cout << "Please Choose an option:" << endl;
	cout << "1: Search for a book to edit" << endl;
	cout << "2: Add a book to Inventory" << endl;
	cout << "3: Delete a book from Inventory" << endl;
	cout << "4: Lookup a book" << endl;
	cout << "5: Exit Inventory Module" << endl;
	cin >> userInteractionInventory;

	while (userInteractionInventory != 5) {
		if (userInteractionInventory == 1) {
			string title;
			int index;
			cout << "Enter title of book: " << endl;
			cin.ignore();
			getline(cin, title);
			index = bklist.searchByTitle(title);
			while (index == -1) {
				cout << "Couldn't find the book in inventory, please enter title again: " << endl;
				getline(cin, title);
				index = bklist.searchByTitle(title);
			}
			cout << "What would you like to edit for book titled " << title << endl;
			cout << "1. ISBN" << endl;
			cout << "2. Title" << endl;
			cout << "3. Author" << endl;
			cout << "4. Publisher" << endl;
			cout << "5. Date Added" << endl;
			cout << "6. Quantity on Hand" << endl;
			cout << "7. Wholesale Cost" << endl;
			cout << "8. Retail Price" << endl;
			cout << "9. Finish Editing" << endl;
			cin >> userIntEdit;
			while (userIntEdit != 9) {
				if (userIntEdit == 1) {
					string i;
					cout << "Enter in the new ISBN" << endl;
					cin.ignore();
					getInput(i);
					(pbklist + index)->setIsbn(i);
				}
				else if (userIntEdit == 2) {
					string i;
					cout << "Enter in the new title" << endl;
					cin.ignore();
					getInput(i);
					(pbklist + index)->setTitle(i);
				}
				else if (userIntEdit == 3) {
					string i;
					cout << "Enter in the new author" << endl;
					cin.ignore();
					getInput(i);
					(pbklist + index)->setAuthor(i);
				}
				else if (userIntEdit == 4) {
					string i;
					cout << "Enter in the new publisher" << endl;
					cin.ignore();
					getInput(i);
					(pbklist + index)->setPublisher(i);
				}
				else if (userIntEdit == 5) {
					string i;
					cout << "Enter in the new date added (YYYY/MM/DD)" << endl;
					cin.ignore();
					getInput(i);
					(pbklist + index)->setDate(i);
				}
				else if (userIntEdit == 6) {
					int i;
					cout << "Enter in the new quantity" << endl;
					getInput(i);
					(pbklist + index)->setQuantity(i);
				}
				else if (userIntEdit == 7) {
					double i;
					cout << "Enter in the new wholesale cost" << endl;
					getInput(i);
					(pbklist + index)->setCost(i);
				}
				else if (userIntEdit == 8) {
					double i;
					cout << "Enter in the new retail price" << endl;
					getInput(i);
					(pbklist + index)->setPrice(i);
				}
				else {
					cout << "Error: Please enter a number between 1 and 9" << endl;
				}
				//(pbklist + index)->print();
				cout << "What would you like to edit for book titled " << (pbklist + index)->getTitle() << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Date Added" << endl;
				cout << "6. Quantity on Hand" << endl;
				cout << "7. Wholesale Cost" << endl;
				cout << "8. Retail Price" << endl;
				cout << "9. Finish Editing" << endl;
				cin >> userIntEdit;
			}
		}
		else if (userInteractionInventory == 2) {
			Book b;
			string fill;
			int i;
			double c;
			cout << "Enter book isbn: " << endl;
			cin.ignore();
			getline(cin, fill);
			b.setIsbn(fill);
			cout << "Enter book title: " << endl;
			getline(cin, fill);
			b.setTitle(fill);
			cout << "Enter book author: " << endl;
			getline(cin, fill);
			b.setAuthor(fill);
			cout << "Enter book publisher: " << endl;
			getline(cin, fill);
			b.setPublisher(fill);
			cout << "Enter today's date(YYYY/MM/DD): " << endl;
			getline(cin, fill);
			b.setDate(fill);
			cout << "Enter quantity: " << endl;
			cin >> i;
			b.setQuantity(i);
			cout << "Enter wholesale cost: " << endl;
			cin >> c;
			b.setCost(c);
			cout << "Enter retail price: " << endl;
			cin >> c;
			b.setPrice(c);
			for (i = 0; i < 100; i++) {
				if ((pbklist + i)->getEmpty()) {
					break;
				}
			}
			*(pbklist + i) = b;
		}
		else if (userInteractionInventory == 3) {
			// Prompt User for Book info
			string title;
			int index;
			cout << "Enter title of book: " << endl;
			cin.ignore();
			getline(cin, title);
			index = bklist.searchByTitle(title);
			while (index == -1) {
				cout << "Couldn't find the book in inventory, please enter title again: " << endl;
				getline(cin, title);
				index = bklist.searchByTitle(title);
			}
			cout << "Deleting book " << title << " from inventory" << endl;
			// Delete Book From Inventory
			*(pbklist + index) = Book();
			//(pbklist + index)->print();
			//shifting array because a random empty space looks nasty
			for (; index < 99; index++) {
				*(pbklist + index) = *(pbklist + index + 1);
			}
			*(pbklist + 99) = Book();
		}

		else if (userInteractionInventory == 4) {
			//Prompt user for title
			string title;
			int index;
			cout << "Enter title of book: " << endl;
			cin.ignore();
			getline(cin, title);
			index = bklist.searchByTitle(title);
			while (index == -1) {
				cout << "Couldn't find the book in inventory, please enter title again: " << endl;
				getline(cin, title);
				index = bklist.searchByTitle(title);
			}
			cout << "Printing out book information for book " << title << endl;
			(pbklist + index)->print();
		}
		else {
			cout << "Please enter a number between 1-5" << endl;
			
		}
		//while loop
		cout << "Welcome to the Inventory Module" << endl;
		cout << "Please Choose an option:" << endl;
		cout << "1: Search for a book to edit" << endl;
		cout << "2: Add a book to Inventory" << endl;
		cout << "3: Delete a book from Inventory" << endl;
		cout << "4: Lookup a book" << endl;
		cout << "5: Exit Inventory Module" << endl;
		cin >> userInteractionInventory;
	}
	
	return bklist;
	
	system("pause");
}

