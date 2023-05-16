#include <iostream>
#include <stdlib.h>
#include "fraccion_template.cpp"

using namespace std;

int main() {
	
	float a, b, c, d;
	cout<<"Ingrese el primer numerador: ";
	cin>>a;
	cout<<"Ingrese el primer denominador: ";
	cin>>b;
	cout<<"Ingrese el segundo numerador: ";
	cin>>c;
	cout<<"Ingrese el segundo denominador: ";
	cin>>d;
	
	Operacion<float> numCalculo(a,b);
    Operacion<float> denCalculo(c,d);

    cout<<"\nOperaciones enteras\n";
    intCalc.operaciones();

    cout<<"\nOperaciones flotante";
    floatCalc.operaciones();

    system("pause");

 
}
