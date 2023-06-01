#pragma once
class NodoDoble
{
private:
	int dato;
	NodoDoble* siguiente;
	NodoDoble* anterior;
public:
	NodoDoble(int);
	~NodoDoble();
	void setDato(int);
	int getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
};


