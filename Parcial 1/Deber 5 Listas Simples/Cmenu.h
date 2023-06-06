/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 15/11/2022
	Enunciado: Lista Simple
	Nivel.- 3   NRC: 7999
*/

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