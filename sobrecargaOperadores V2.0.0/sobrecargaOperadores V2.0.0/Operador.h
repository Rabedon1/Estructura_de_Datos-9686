	/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Arias Sebastian, Bazurto Christopher, Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 16/05/23 10:01
 * Fecha de modificacion: 18/05/23 19:32
 * Enunciado:
 * Ejemplo de operadores sobrecargados
 * 
 *******************************************************************************/ 

#ifndef OPERADOR_H
#define OPERADOR_H

#include <iostream>

class Operacion;

class Operador{
	public:
		virtual float operator +(const Operacion&) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Operacion& op);
		virtual bool operator>=(const Operacion& op) const = 0;
		virtual bool operator ==(const Operacion&)const=0;
};

#endif