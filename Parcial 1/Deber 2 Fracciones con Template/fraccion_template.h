/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 13/05/23 10:32
 * Fecha de modificacion: 29/05/23 13:30
 * Tema: Operacion de fracciones con template
 *******************************************************************************/ 
//#ifndef OPERACION_H
//#define OPERACION_H

#include <iostream>


template <typename T>
class Operacion {
	private:
		T numerador1 ,numerador2, denominador1,denominador2;
	public:
		Operacion(T num1,T den1,T num2,T den2) : numerador1(num1), numerador2(num2),denominador1(den1), denominador2(den2){};
	
		
		void calculo();
		T numCalculo();
		T denCalculo();
	
};

//#endif
