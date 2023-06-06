/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 29/05/23 20:32
 * Fecha de modificacion: 06/06/23 13:30
 * Tema: Listas Simples 
 *******************************************************************************/ 

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