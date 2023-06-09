/*************************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  main.cpp
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: lunes, 8 de mayo de 2023 10:15:36
 * Ultima modificación: martes, 9 de mayo de 2023 17:10:08
 * Enunciado: Crear una clase fraccion, donde resuelva la siguiente operacion matematica, 
 * (n1*d2)+(n2*d1)/(d1+d2), con TDA (Tipo de datos abstractos).
 *************************************************************************************************/

#include <iostream>
#include "Fraccion.cpp"

using namespace std;

int main(int argc, char** argv){
/*
  float a=18,b=3;
   Fraccion *obj1=new Fraccion(8,7);
   Fraccion *obj2=new Fraccion(15,5);
   Fraccion *obj3=new Fraccion(0,0);
*/
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

   
   system("pause");
   return 0;
}
