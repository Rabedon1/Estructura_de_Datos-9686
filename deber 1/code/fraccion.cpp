/***********************************************************************
 * Module:  fraccion.cpp
 * Author:  raul2
 * Modified: lunes, 8 de mayo de 2023 20:37:05
 * Purpose: Implementation of the class fraccion
 ***********************************************************************/

#include "fraccion.h"

fraccion::fraccion(fraccion num, fraccion den)
{
   this->numerador=numerador;
   this->denominador=denominador;
}

fraccion::fraccion()
{
}

fraccion::~fraccion()
{
   // TODO : implement
}

float fraccion::getNumerador(void)
{
   return numerador;
}

void fraccion::setNumerador(float newNumerador)
{
   numerador = newNumerador;
}

float fraccion::getDenominador(void)
{
   return denominador;
}


void fraccion::setDenominador(float newDenominador)
{
   denominador = newDenominador;
}

fraccion fraccion::proceso(fraccion obj1, fraccion obj2)
{
	fraccion resultado1 = obj1.getNumerador() * obj2.getDenominador();
	fraccion resultado2 = obj2.getNumerador() * obj1.getDenominador();
	flofraccionat num = resultado1 + resultado2;
	fraccion den = obj1.getDenominador() + obj2.getDenominador();
	return fraccion;
}