/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  alexa
 * Modified: martes, 9 de mayo de 2023 17:10:08
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(float num, float den)
{
   this -> Numerador=num;
   this -> Denominador=den;
}



Fraccion::~Fraccion()
{
   // TODO : implement
}



float Fraccion::getNumerador(void)
{
   return Numerador;
}



void Fraccion::setNumerador(float newNumerador)
{
   Numerador = newNumerador;
}



float Fraccion::getDenominador(void)
{
   return Denominador;
}



void Fraccion::setDenominador(float newDenominador)
{
   Denominador = newDenominador;
}



Fraccion::Fraccion()
{
}



float Fraccion::proceso(Fraccion obj1, Fraccion obj2)
{
	
	

}



Fraccion Fraccion::proceso_1(Fraccion obj1, Fraccion obj2)
{
   this -> setNumerador(((obj1.getNumerador()*obj2.getDenominador())+(obj2.getNumerador()*obj1.getDenominador())));
   this -> setDenominador(((obj1.getDenominador()+obj2.getDenominador())));
   return *this;
}



Fraccion Fraccion::proceso_2(float obj1, float obj2)
{
   // TODO : implement
}



void Fraccion::imprimir(Fraccion obj)
{
   cout<<obj.getNumerador()<<"/"<<obj.getDenominador()<<endl;	
   
}
