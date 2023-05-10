#include <iostream>
#include "Fraccion.cpp"
using namespace std;

int main(int argc, char** argv){

   float num1, den1, num2, den2;

   cout << "Ingrese el numerador y el denominador de la primera fraccion: ";
   cin >> num1 >> den1;

   cout << "Ingrese el numerador y el denominador de la segunda fraccion: ";
   cin >> num2 >> den2;

   Fraccion *obj1 = new Fraccion(num1, den1);
   Fraccion *obj2 = new Fraccion(num2, den2);
   Fraccion *obj3 = new Fraccion();

   obj3->proceso_1(*obj1, *obj2);
   obj1->imprimir(*obj1);
   obj1->imprimir(*obj2);
   obj1->imprimir(*obj3);

   delete obj1;
   delete obj2;
   delete obj3;

   cin.get();
   return 0;
}
