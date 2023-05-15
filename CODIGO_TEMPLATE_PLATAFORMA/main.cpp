#include <iostream>
#include <stdlib.h>
#include "template.cpp"
#include "Imprimir.h"

using namespace std;

int main() {
	Validacion valido;
    
	cout<<"Ingrese el primer numero entero: ";
	int a = valido.ingresarDatosEnteros();
	cout<<"Ingrese el segundo numero entero: ";
	int b = valido.ingresarDatosEnteros();
	cout<<"Ingrese el primer numero flotante: ";
	float c = valido.ingresarDatosfloat();
	cout<<"Ingrese el segundo numero flotante: ";
	float d = valido.ingresarDatosfloat();
	
	Calculadora<int> intCalc(a,b);
    Calculadora<float> floatCalc(c,d);

    cout<<"\nOperaciones enteras\n";
    intCalc.operaciones();

    cout<<"\nOperaciones flotante";
    floatCalc.operaciones();

    system("pause");

 
}
