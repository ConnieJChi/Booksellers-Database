#pragma once

#include "Module.h"
#include "Booklist.h"
/*
Psuedocode
Module class (made for inhertance for booklist)
virtual public print function which prints a stub
*/
class Module {
public:
	virtual void print() {
		std::cout << "This is module" << endl;
	}
};