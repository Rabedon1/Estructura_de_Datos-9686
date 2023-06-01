/******************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.cpp
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: lunes, 8 de mayo de 2023 10:15:36
 * Ultima modificación: martes, 9 de mayo de 2023 17:10:08
 * Enunciado: Crear una clase fraccion, donde resuelva la siguiente operacion matematica, 
 * (n1*d2)+(n2*d1)/(d1+d2), con TDA (Tipo de datos abstractos).
 *****************************************************************************************/

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
   return *this;  //devuelve una referencia al objeto
}



Fraccion Fraccion::proceso_2(float obj1, float obj2)
{
   // TODO : implement
}



void Fraccion::imprimir(Fraccion obj)
{
   cout<<obj.getNumerador()<<"/"<<obj.getDenominador()<<endl;	
   
}
