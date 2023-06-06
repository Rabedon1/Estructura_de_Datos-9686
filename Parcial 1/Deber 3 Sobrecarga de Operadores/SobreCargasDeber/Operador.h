/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 22/05/23 20:32
 * Fecha de modificacion: 23/05/23 22:30
 * Enunciado: Realice operaciones con sobrecargas.
 * Tema: operadores sobrecargados
 *******************************************************************************/ 

#ifndef OPERADOR_H
#define OPERADOR_H

#include <iostream>

class Operacion;

class Operador{
	public:
		virtual float operator +(const Operacion&) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Operacion& op);//clase amiga permite a una clase tener acceso miembros privados y protegidos de otra clase
		virtual bool operator>=(const Operacion& op) const = 0;
		virtual bool operator ==(const Operacion&)const=0;
};

#endif