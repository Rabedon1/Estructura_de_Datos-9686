/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 29/05/23 20:32
 * Fecha de modificacion: 06/06/23 13:30
 * Tema: Listas Simples 
 *******************************************************************************/ 

#ifndef CMENU_H
#define CMENU_H
#include <iostream>
using namespace std;

class Cmenu{
    public:
        void menuPrincipal();
        char *ingresarDatosEnteros(char *msj);
        char *ingresarDatosFlotantes(char *);
        char *ingresarChar(char *msj);
    private:
        int opcion=0;
	    char dato[10],dato1[10],dato2[10],dato3[10],dato4[10],dato5[10],dato6[10];
};
#endif