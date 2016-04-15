/*
 * xObject.h
 *
 *  Created on: 12 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef XOBJECT_H_
#define XOBJECT_H_
#include "jsoncpp/json.h"
#include "testClass.h"


class xObject // Clase padre de las clases prueba
{
public:
   virtual ~xObject( void ) {};
   virtual void Serialize( Json::Value& root ) =0;
   virtual void Deserialize( Json::Value& root) =0;

};

#endif /* XOBJECT_H_ */
