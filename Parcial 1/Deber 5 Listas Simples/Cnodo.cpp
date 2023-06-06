/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 29/05/23 20:32
 * Fecha de modificacion: 06/06/23 13:30
 * Tema: Listas Simples 
 *******************************************************************************/ 

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