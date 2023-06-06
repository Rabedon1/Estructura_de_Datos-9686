/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 15/11/2022
	Enunciado: Lista Simple
	Nivel.- 3   NRC: 7999
*/

#pragma once
#include "Cnodo.h"
#include <iostream>

class Clista{
    private:
        Cnodo *referencial;
        Cnodo *origen;
        bool ListaVacia(){
            return (this->origen==NULL);
        }
    public:
        Clista();
        virtual void insertarCab(int);
        virtual void insertarCol(int);
        virtual void imprimir();
        virtual void eliminarCab(int);
        virtual void eliminarCol(int);
        virtual void buscar(int);
        virtual int tamanioLista();
        int sumarComponentes();

};