#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream> 


#include "Book.h"
#include "Booklist.h"
#include "cashier.h"
#include "report.h"
#include "inventory.h"
#include "search.h"

using namespace std;
//template class for reading
template<class T>
void getInput(T& var)
{
	cin >> var;
}

/*
Psuedocode
create variables for size of array and integer for user input
print out welcome statement
read booklist.txt from project directive into Booklist object bkl
using fstream and string manipulation in a while loop
while loop
print out menu for choosing module
for userinput equals 1 
go to cash register
for userinput equals 2
go to inventory module
for userinput equals 3
go to report module
for userinput equals 4
end while loop

create new file output.txt
read bkl object into output.txt
print out exit statements
return 0
*/
int main() {
	//Create Variables
	const int TOTAL_SIZE = 100;
	int userInteraction;

	//title~author~publishor~isbn~quantity~cost~price~date will be how it's read
	cout << "Welcome to the Serendipity POS System" << endl;
	
	//Read in Inventory File
	cout << "Reading Booklist.txt(inventory) file" << endl;
	ifstream booklist;
	booklist.open("Booklist.txt");
	if (booklist.fail()) {
		cout << "Could not find Booklist.txt, please create it" << endl;
		system("pause");
		return 0;
	}
	Booklist b;
	Book * pb;
	pb = b.getBooklist();

	string line;
	int i1 = 0;
	int i2 = 0;
	int counter = 0;
		
	while (getline(booklist, line)) {
		i1 = line.find("~");
		i2 = line.find("~", i1 + 1);
		(pb+counter)->setTitle(line.substr(0, i1));
		(pb + counter)->setAuthor(line.substr(i1 + 1, i2 - i1 - 1));
		i1 = i2;
		i2 = line.find("~", i1 + 1);
		(pb + counter)->setPublisher(line.substr(i1 + 1, i2 - i1 - 1));
		i1 = i2;
		i2 = line.find("~", i1 + 1);
		(pb + counter)->setIsbn(line.substr(i1 + 1, i2 - i1 - 1));
		i1 = i2;
		i2 = line.find("~", i1 + 1);
		(pb + counter)->setQuantity(atoi(line.substr(i1 + 1, i2 - i1 - 1).c_str()));
		i1 = i2;
		i2 = line.find("~", i1 + 1);
		(pb + counter)->setCost(atof(line.substr(i1 + 1, i2 - i1 - 1).c_str()));
		i1 = i2;
		i2 = line.find("~", i1 + 1);
		(pb + counter)->setPrice(atof(line.substr(i1 + 1, i2 - i1 - 1).c_str()));
		i1 = i2;
		i2 = line.length();
		(pb + counter)->setDate(line.substr(i1 + 1, i2 - i1 - 1));
		counter++;
	}
	cout << "Serendpity Booksellers" << endl << endl;
	
	cout << "1: Cash Register" << endl;
	cout << "2: Inventory Module" << endl;
	cout << "3: Report Module" << endl;
	cout << "4: Exit Program" << endl;
	getInput(userInteraction);
	//exception catching
	try {
		if (cin.fail()) {
			throw "error";
		}
	}
	catch(char* error){
		cout << "Error: please enter an integer" << endl;
		cout << "Restart program" << endl;

		system("pause");
		return 0;
	}
	while (userInteraction != 4) {
		if (userInteraction == 1) {
			b = cashier(b);
			//Cash Register Module
		}
		else if (userInteraction == 2) {
			//Inventory Module
			b = inventory(b);
		}
		else if (userInteraction == 3) {
			//Report Module
			report(b);
		}
		else {
			cout << "Error: Please enter a number between 1 and 4" << endl;
		}
		//while loop
		cout << "Serendpity Booksellers" << endl << endl;
		cout << "1: Cash Register" << endl;
		cout << "2: Inventory Module" << endl;
		cout << "3: Report Module" << endl;
		cout << "4: Exit Program" << endl;
		cout << "Please Enter a number to choose a Module to utilize:" << endl;
		getInput(userInteraction);
		//exception catching
		try {
			if (cin.fail()) {
				throw "error";
			}
		}
		catch (char* error) {
			cout << "Error: please enter an integer" << endl;
			cout << "Restart program" << endl;

			system("pause");
			return 0;
		}
	}
	//writing inventory back into file writing into output b/c error checking
	ofstream output("output.txt");
	for (int i = 0; i < 100; i++) {
		if (!(pb + i)->getEmpty()) {
			output << (pb + i)->getTitle() << "~";
			output << (pb + i)->getAuthor() << "~";
			output << (pb + i)->getPublisher() << "~";
			output << (pb + i)->getIsbn() << "~";
			output << (pb + i)->getQuantity() << "~";
			output << (pb + i)->getCost() << "~";
			output << (pb + i)->getPrice() << "~";
			output << (pb + i)->getDate();
		}
		output << "\n";
	}
	cout << "Thank you for using the Serendipity POS system" << endl;
	cout << "Exporting the changed inventory.txt into output.txt" << endl;
	cout << "Press any key to Exit" << endl;

	output.close();
	booklist.close();
	system("pause");
	return 0;
}


