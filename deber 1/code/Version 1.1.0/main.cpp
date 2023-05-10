#include <iostream>
#include "Fraccion.cpp"
int main(int argc, char** argv){

   int a=18,b=3;
   Fraccion *obj1=new Fraccion(a,b);
   Fraccion *obj2=new Fraccion(15,5);
   Fraccion *obj3=new Fraccion(0,0);


   obj3->proceso_1(*obj1,*obj2);
   obj1->imprimir(*obj1);
   obj1->imprimir(*obj2);
   obj1->imprimir(*obj3);
   cin.get();
   
    return 0;
}
