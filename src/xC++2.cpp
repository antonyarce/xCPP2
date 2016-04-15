//============================================================================
// Name        : xC++2.cpp
// Author      : Antony Arce
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jsoncpp/json.h"
#include "testClass.h"
#include "xObject.h"
#include "xJson.h"
#include "xPointer.h"
#include <iostream>
using namespace std;

int main() {

	// Prueba xJson y xPointer

	xJson CJS;

	TestClassA testClass;
	//TestClassA* pTc = &testClass;
	xPointer<TestClassA> xp(&testClass);

	cout<<xp.pData<<endl;

	std::string input = "{ \"testintA\" : 42, \"testfloatA\" : 3.14159, \"teststringA\" : \"foo\", \"testboolA\" : true }\n";
	CJS.Deserialize( xp.pData, input );

	std::string output;
	CJS.Serialize( xp.pData, output);



	return 0;
}
