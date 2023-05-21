	/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Arias Sebastian, Bazurto Christopher, Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 16/05/23 10:01
 * Fecha de modificacion: 18/05/23 19:32
 * Enunciado:
 * Ejemplo de operadores sobrecargados
 * 
 *******************************************************************************/ 
	
#include "Operacion.h"

Operacion::Operacion(){
}
Operacion::Operacion(float A, float B) {
	this-> a = A;
	this-> b = B;
}

Operacion::~Operacion() {
}

void Operacion::setA(float newA) {
	this->a = newA;
}

float Operacion::getA(void) {
	return a;
}

void Operacion::setB(float newB) {
	this->b = newB;
}

float Operacion::getB(void) {
	return b;
}

float Operacion::operator +(const Operacion& op) const {
	Operacion sumaTotal(a + op.a,  b + op.b);
	return (sumaTotal.a + sumaTotal.b);
}

std::ostream& operator<<(std::ostream& os, const Operacion& op) {
	os << "Tipo de Objeto: Operacion" << std::endl;
    os << "float a = " << op.a;
    os << ", float b = " << op.b << std::endl;	
	return os;
}

bool Operacion::operator>=(const Operacion& op) const {
    return a + b >= op.a + op.b;
}

bool Operacion::operator ==(const Operacion& op)const{
	(a == op.a && b == op.b)?true:false;
}