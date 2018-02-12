#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>
#include "Book.h"
#include <string>
#include "Module.h"

using namespace std;
/*
Psuedocode
create booklist class that extends module
private:
	book array of 100 elements
public:
	default initializier setting all 100 elements to empty books
	overloading = operator function setting one booklist to other booklist
	getter function for book array
	print function for booklist
	print by price, going through each book and printing out
	the book's price and total price of all of that bok
	then printing out total price of inventory
	print by cost, going through each book and printing out
	the book's cost and total cost of all of that bok
	then printing out total cost of inventory
	sort by quantity, going through the booklist array
	and sorting the books in decreasing order of quantity
	sort by cost, going through the booklist array
	and sorting the books in decreasing order of cost
	sort by date, going through the booklist array
	and sorting the books in increasing order of date
	search by title with parameters of a string, going through the booklist array
	until a book with the same title as the parameter string 
	is found, and the book's index is returned
	selling function with parameters of a string and an integer,
	calling the search by title function to find the book, and
	then subtracting the from quantity the integer in the parameter
	if the quantity is less than 0,
		delete the book from booklist array and shift array over
	else
		set quantity to quantity minus integer in parameter
	end class
*/
class Booklist : public Module {
private:
	Book booklist[100]; //100 from const totalsize in main

public:
	//initializer
	Booklist() {
		for (int i = 0; i < 100; i++) {
			booklist[i] = Book();
		}
	}
	//overloading = operator
	Booklist& operator =(Booklist book) {
		Book * pbook;
		pbook = book.booklist;
		for (int i = 0; i < 100; i++) {
			booklist[i] = *(pbook+i);
		}
		return *this;
	}
	//getter
	Book * getBooklist() {
		return booklist;
	}
	//printing functions
	void print() {
		for (int i = 0; i < 100; i++) {
			if (!booklist[i].empty) {
				booklist[i].print();
			}
		}
	}
	void printByCost() {
		double sum = 0;
		for (int i = 0; i < 100; i++) {
			if (!booklist[i].empty) {
				sum += booklist[i].cost * booklist[i].quantity;
				cout << "Wholesale Value for book " << booklist[i].title << " is " << booklist[i].cost << endl;
				cout << "Total wholesale value for the " << booklist[i].quantity << " books of " << 
					booklist[i].title << " is " << booklist[i].cost * booklist[i].quantity << endl;
			}
		}
		cout <<endl << "Total wholesale value for inventory excluding tax is " << sum << endl;
	}
	void printByPrice() {
		double sum = 0;
		for (int i = 0; i < 100; i++) {
			if (!booklist[i].empty) {
				sum += booklist[i].price * booklist[i].quantity;
				cout << "Retail Price for book " << booklist[i].title << " is " << booklist[i].price << endl;
				cout << "Total retail price for the " << booklist[i].quantity << " books of " <<
					booklist[i].title << " is " << booklist[i].price * booklist[i].quantity << endl;
			}
		}
		cout << endl << "Total retail price for inventory excluding tax is " << sum << endl;
	}
	
	//sort functions for report module
	void sortByQuantity() {
		Book swap;
		for (int c = 0; c < 99; c++)
		{
			if (!booklist[c].empty) {
				for (int d = 0; d < (99 - c); d++)
				{
					if (booklist[d].quantity < booklist[d + 1].quantity) // For decreasing order use <
					{
						swap = booklist[d];
						booklist[d] = booklist[d + 1];
						booklist[d + 1] = swap;
					}
				}
			}
		}
		return;
	}
	void sortByCost() {
		Book swap;
		for (int c = 0; c < 99; c++)
		{
			if (!booklist[c].empty) {
				for (int d = 0; d < (99 - c); d++)
				{
					if (booklist[d].cost < booklist[d + 1].cost) // For decreasing order use <
					{
						swap = booklist[d];
						booklist[d] = booklist[d + 1];
						booklist[d + 1] = swap;
					}
				}
			}
		}
	}
	void sortByAge() {
		Book swap;
		for (int c = 0; c < 99; c++)
		{
			if (!booklist[c].empty) {
				for (int d = 0; d < (99 - c); d++)
				{
					if (booklist[d].date > booklist[d + 1].date) // For decreasing order use <
					{
						swap = booklist[d];
						booklist[d] = booklist[d + 1];
						booklist[d + 1] = swap;
					}
				}
			}
		}
	}
	//search functions
	int searchByTitle(string s) {
		for (int i = 0; i < 100; i++) {
			if (!booklist[i].empty) {
				if (booklist[i].title == s) {
					return i;
				}
			}
		}
		return -1;
	}
	//selling function for cashier module
	void sellBook(string t, int a) {
		int index = searchByTitle(t);
		if (booklist[index].quantity - a > 0) {
			//booklist[index].setQuantity(booklist[index].getQuantity() - a);
			booklist[index].quantity = booklist[index].quantity - a;
		}
		else {
			booklist[index] = Book();
			for (; index < 99; index++) {
				booklist[index] = booklist[index+1];
			}
			booklist[100] = Book();
		}
	}
};
