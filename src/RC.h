/*
 * RC.h
 *
 *  Created on: 11 de abr. de 2016
 *      Author: tonylinux
 */

#ifndef RC_H_
#define RC_H_

class RC // Clase para llevar la cuenta de referencias
{
    private:
    int count; // Contador

    public:
    void AddRef()
    {
        // Incrementa el contador
        count++;
    }

    int Release()
    {
        // Decrementa el contador
        // Retorna el contador
        return --count;
    }
};

#endif /* RC_H_ */
