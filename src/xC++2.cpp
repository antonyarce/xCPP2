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
#include"xMemoryManagerFinal.h"
#include <iostream>
using namespace std;

int main() {

	int n=150;
	xMemoryManagerFinal::solicitarMemoria(n);//Solicita el bloque de memoria.
	cout<<"Espacio de "<<n<<" bytes solicitado al heap"<<endl;
	cout<<"Comienza en la dirección: "<<xMemoryManagerFinal::inicio<<endl;
	cout<<"Termina en la dirección: "<<xMemoryManagerFinal::final<<"\n\n\n";



	// Prueba
	xJson CJS;

	TestClassA* tc1 = new TestClassA();
	xPointer<TestClassA> xp1(tc1);
	cout<<"ClassName: "<<xp1.pData->getClassName()<<", ID: "<<xp1.pData->getId()<<endl;


	std::string input = "{ \"testintA\" : 42, \"testfloatA\" : 3.14159, \"teststringA\" : \"foo\", \"testboolA\" : true }\n";
	CJS.Deserialize( xp1.pData, input );

	std::string output;
	CJS.Serialize( xp1.pData, output);
	cout<<output<<endl;

	TestClassA* tc2 = new TestClassA();
	xPointer<TestClassA> xp2(tc2);

	TestClassA* tc3 = new TestClassA();
	xPointer<TestClassA> xp3(tc3);

	TestClassA* tc4 = new TestClassA();
	xPointer<TestClassA> xp4(tc4);



	return 0;
}
