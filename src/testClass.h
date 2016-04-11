/*
 * testClass.h
 *
 *  Created on: 11 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef TESTCLASS_H_
#define TESTCLASS_H_
#include <iostream>
using namespace std;

class testClass {
public:
	int number;

	testClass(int num){
		number = num;
	}

	void print(){
		cout<<number<<endl;
	}

};

#endif /* TESTCLASS_H_ */
