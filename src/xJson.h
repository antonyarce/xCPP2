/*
 * xJson.h
 *
 *  Created on: 12 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef XJSON_H_
#define XJSON_H_
#include "jsoncpp/json.h"
#include <iostream>
using namespace std;

class xJson
{
public:
	bool Serialize( xObject* pObj, std::string output )
	{
	   if (pObj == NULL)
	      return false;

	   Json::Value serializeRoot;
	   pObj->Serialize(serializeRoot);

	   Json::StyledWriter writer;
	   output = writer.write( serializeRoot );
	   cout<<"Serialize: \n"<<output <<endl;

	   return true;
	}

	bool Deserialize( xObject* pObj, std::string input )
	{
	   if (pObj == NULL)
	      return false;

	   Json::Value deserializeRoot;
	   Json::Reader reader;

	   if ( !reader.parse(input, deserializeRoot) )
	      return false;

	   pObj->Deserialize(deserializeRoot);

	   cout<<"Deserialize: \n"<<input<<endl;

	   return true;
	}

};

#endif /* XJSON_H_ */
