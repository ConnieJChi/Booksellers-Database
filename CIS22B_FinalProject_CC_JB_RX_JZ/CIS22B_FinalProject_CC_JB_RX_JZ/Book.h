#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/*
Psuedocode
Book class
friend Booklist class
private variables:
create variables quantity, isbn, title, author, publisher, date
cost, price, and empty 
public methods:
default constructor setting everything to 0 or empty
overloaded = operator for setting on book equal to another book
print function for printing out every variable
getters for each variable
setters for each variable
end class
*/
class Book{
	friend class Booklist;
private:
	int quantity;
	string isbn, title, author, publisher,date;
	double cost, price;
	//check if book is empty so we don't go through all 100 of booklist
	bool empty;
public:
	//default constructor
	Book() {
		isbn = "";
		quantity = 0;
		title = "";
		author = "";;
		publisher = "";
		date = "";
		cost = 0;
		price = 0;
		empty = true;
	}
	//operator overloading
	Book& operator = (Book book) {
		quantity = book.getQuantity();
		isbn = book.getIsbn();
		title = book.getTitle();
		author = book.getAuthor();
		publisher = book.getPublisher();
		date = book.getDate();
		cost = book.getCost();
		price = book.getPrice();
		empty = book.getEmpty();
		return *this;
	}
	//print function for easy printing
	void print() {
		cout << "ISBN: " << isbn << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author<< endl;
		cout << "Publisher: " << publisher<< endl;
		cout << "Date Added: " << date << endl;
		cout << "Quantity on Hand: " << quantity << endl;
		cout << fixed << showpoint << right << setprecision(2);
		cout << "Wholesale Cost: " << cost << endl;
		cout << "Retail Price: " << price << endl;
		cout << "______________________________________" << endl;
	}
	//getters
	string getIsbn() {
		return isbn;
	}
	int getQuantity() {
		return quantity;
	}
	string getTitle() {
		return title;
	}
	string getAuthor() {
		return author;
	}
	string getPublisher() {
		return publisher;
	}
	string getDate() {
		return date;
	}
	double getCost() {
		return cost;
	}
	double getPrice() {
		return price;
	}
	bool getEmpty() {
		return empty;
	}
	//mutators
	void setIsbn(string i) {
		isbn = i;
		empty = false;
	}
	void setQuantity(int q) {
		quantity = q;
		empty = false;
	}
	void setTitle(string s) {
		title = s;
		empty = false;
	}
	void setAuthor(string s) {
		author = s;
		empty = false;
	}
	void setPublisher(string s) {
		publisher = s;
		empty = false;
	}
	void setDate(string s) {
		date = s;
		empty = false;
	}
	void setCost(double c) {
		cost = c;
		empty = false;
	}
	void setPrice(double c) {
		price = c;
		empty = false;
	}
	void setEmpty(bool b) {
		empty = b;
		empty = false;
	}
};
