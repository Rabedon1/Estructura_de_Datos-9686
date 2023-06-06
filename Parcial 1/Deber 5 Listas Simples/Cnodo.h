/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 15/11/2022
	Enunciado: Lista Simple
	Nivel.- 3   NRC: 7999
*/

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