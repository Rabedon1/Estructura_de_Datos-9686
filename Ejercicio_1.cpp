//Encontrar el mayor de dos numeros

#include <iostream> //operaciones de entrada y de salida 
#include<conio.h>


using namespace std;

//Prototipo
int numMayor(int x, int y);

int main(){
    
    int num1,num2,mayor;
    cout<<"Digite 2 numeros: ";
    cin>>num1>>num2;

   mayor = numMayor(num1,num2);
   cout<<"El mayor de los dos numeros es:" << mayor;

    return 0;
}

//Definicion de funcion



int numMayor(int x, int y){
    int numMax;
    if(x>y){
        numMax = x;
    }
    else{
        numMax = y;
    }

    return numMax;
}