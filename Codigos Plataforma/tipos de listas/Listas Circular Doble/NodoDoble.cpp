#include "NodoDoble.h"
NodoDoble::NodoDoble(int dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}
NodoDoble::~NodoDoble()
{
}

void NodoDoble::setDato(int dato)
{
	this->dato = dato;
}

int NodoDoble::getDato()
{
	return this->dato;
}

void NodoDoble::setSiguiente(NodoDoble* siguiente)
{
	this->siguiente = siguiente;
}

NodoDoble* NodoDoble::getSiguiente()
{
	return this->siguiente;
}

void NodoDoble::setAnterior(NodoDoble* anterior)
{
	this->anterior = anterior;
}

NodoDoble* NodoDoble::getAnterior()
{
	return this->anterior;
}


