//============================================================================
// Name        : xC++2.cpp
// Author      : Antony Arce
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "xPointer.h"
#include <iostream>
#include "testClass.h"
using namespace std;

int main() {

	xPointer<testClass> xP1(new testClass(1)); // Se define un xPointer a una clase de prueba
	   {
		xPointer<testClass> q = xP1;


	    xPointer<testClass> r;
	    r = xP1;

	    }

	cout << "Works" << endl; // prints !!!Hello World!!!
	return 0;
}