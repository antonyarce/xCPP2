/*
 * xPointer.h
 *
 *  Created on: 11 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef XPOINTER_H_
#define XPOINTER_H_
#include "RC.h"

template < typename T > class xPointer
{
private:
    T*    pData;       // Puntero
    RC* reference; // Contador de referencias

public:
    xPointer() : pData(0), reference(0)
    {
        // Crea una nueva referencia
        reference = new RC();
        // Incrementa el contador
        reference->AddRef();
    }

    xPointer(T* pValue) : pData(pValue), reference(0)
    {
    	// Crea una nueva referencia
        reference = new RC();
        // Incrementa el contador
        reference->AddRef();
    }

    xPointer(const xPointer<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        // Copia el contructor
        // Copia los datos
    	// Incrementa el contador
        reference->AddRef();
    }

    ~xPointer()
    {
        // Destructor
        // Decrementa el contador
        // Si no tiene referencias borra el puntero
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }

    xPointer<T>& operator = (const xPointer<T>& sp)
    {
        // Operador de asignacion
        if (this != &sp) // Evita asignarse a si mismo
        {
            // Decrementa el contador
            // Si no tiene referencias borra el contador
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }

            // Copia los datos
            // Incrementa el contador
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};

#endif /* XPOINTER_H_ */
