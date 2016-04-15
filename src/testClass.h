/*
 * testClass.h
 *
 *  Created on: 11 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef TESTCLASS_H_
#define TESTCLASS_H_
#include "xObject.h"
#include "jsoncpp/json.h"
#include "xMemoryManagerFinal.h"

class TestClassA : public xObject  //Clase que hereda de xObject
{
public:

	void* operator new(size_t)
	{

		return xMemoryManagerFinal::xCalloc(sizeof(TestClassA));
	}

	void Serialize( Json::Value& root ) // Sobre escribe los metodos
	{
	   // serialize primitives
	   root["testintA"] = m_nTestInt;
	   root["testfloatA"] = m_fTestFloat;
	   root["teststringA"] = m_TestString;
	   root["testboolA"] = m_bTestBool;
	}

	void Deserialize( Json::Value& root )
	{
	   // deserialize primitives
	   m_nTestInt = root.get("testintA",0).asInt();
	   m_fTestFloat = root.get("testfloatA", 0.0).asDouble();
	   m_TestString = root.get("teststringA", "").asString();
	   m_bTestBool = root.get("testboolA", false).asBool();
	}


private:
   int           m_nTestInt;
   double        m_fTestFloat;
   std::string   m_TestString;
   bool          m_bTestBool;

};
#endif /* TESTCLASS_H_ */
