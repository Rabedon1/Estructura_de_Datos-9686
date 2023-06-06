/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 29/05/23 20:32
 * Fecha de modificacion: 06/06/23 13:30
 * Tema: Listas Simples 
 *******************************************************************************/ 

#ifndef CNODO_H
#define CNODO_H
#include <iostream>
using namespace std;

class Cnodo{
    private:
        int entrada;
        Cnodo *siguiente;
    public:
        Cnodo(int, Cnodo *siguiente);
        Cnodo();
        ~Cnodo();
        int getEntrada();
        Cnodo *getSiguiente();
        void setEntrada(int);
        void setSiguiente(Cnodo *siguiente);
};
#endif