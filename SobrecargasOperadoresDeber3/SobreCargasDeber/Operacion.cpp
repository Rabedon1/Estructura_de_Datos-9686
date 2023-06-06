/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 22/05/23 20:32
 * Fecha de modificacion: 23/05/23 22:30
 * Enunciado: Realice operaciones con sobrecargas.
 * Tema: operadores sobrecargados
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
	Operacion sumatoriaTotal(a + op.a,  b + op.b);
	return (sumatoriaTotal.a + sumatoriaTotal.b);
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