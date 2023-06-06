/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 15/11/2022
	Enunciado: Lista Simple
	Nivel.- 3   NRC: 7999
*/

#include "Cnodo.h"
#include <iostream>

Cnodo::Cnodo(int ent, Cnodo *sig=NULL){
    this->entrada=ent;
    this->siguiente=sig;
}
Cnodo::~Cnodo(){
    delete siguiente;
}
int Cnodo::getEntrada(){
    return entrada;
}

Cnodo* Cnodo::getSiguiente(){
    return siguiente;
}
void Cnodo::setEntrada(int entr){
    this->entrada=entr;
}
void Cnodo::setSiguiente(Cnodo *sig){
    this->siguiente=sig;
}