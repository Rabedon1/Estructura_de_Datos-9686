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
