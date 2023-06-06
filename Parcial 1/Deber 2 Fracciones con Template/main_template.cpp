/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 13/05/23 10:32
 * Fecha de modificacion: 29/05/23 13:30
 * Tema: Operacion de fracciones con template
 *******************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include "fraccion_template.cpp"



int main() {
	
	float a, b, c, d;
	std::cout<<"Ingrese el primer numerador: ";
	std::cin>>a;
	std::cout<<"Ingrese el primer denominador: ";
	std::cin>>b;
	std::cout<<"Ingrese el segundo numerador: ";
	std::cin>>c;
	std::cout<<"Ingrese el segundo denominador: ";
	std::cin>>d;
	

    Operacion<float> floatCalcu(a,b,c,d);


    floatCalcu.calculo();

   
    system("pause");

 
}
