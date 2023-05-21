/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Arias Sebastian, Bazurto Christopher, Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 16/05/23 10:01
 * Fecha de modificacion: 18/05/23 19:32
 * Enunciado:
 * Ejemplo de operadores sobrecargados
 * 
 *******************************************************************************/ 

#include <iostream>
#include "Operacion.h"
#include "Dato.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float fnum1, fnum2;
	
	std::cout << "Objeto 1 \nIngrese el primer decimal: " << std::endl;
	fnum1 = Dato::ingresarFloat();
	std::cout << "Ingrese el segundo decimal: " << std::endl;
	fnum2 = Dato::ingresarFloat();
	Operacion op1(fnum1, fnum2);
	
	std::cout << "Objeto 2 \nIngrese el primer decimal: " << std::endl;
	fnum1 = Dato::ingresarFloat();
	std::cout << "Ingrese el segundo decimal: " << std::endl;
	fnum2 = Dato::ingresarFloat();
	Operacion op2(fnum1, fnum2);
	
	//Uso del operador sobrecargado <<
	std::cout << "\nUso del operador sobrecargado <<" << std::endl;
	std::cout << op1 << std::endl;
	std::cout << op2 << std::endl;
	
	std::cout << "\nUso del operador sobrecargado +" << std::endl;
	//Uso del operador sobrecargado +
	std::cout << op1.getA() << " + " << op1.getB() << " + " << op2.getA() << " + " << op2.getB()
			<< " = " << op1 + op2 << std::endl; 
	
	//Uso del operador sobrecargado >=
	std::cout << "\nUso del operador sobrecargado >=" << std::endl;
	std::cout << "objeto1 >= objeto2 ?" << std::endl;
    if (op1 >= op2) {
        std::cout << "La suma de los valordes de objeto1 es mayor o igual que objeto2" << std::endl;
    } else {
        std::cout << "La suma de los valordes de objeto1 es menor que objeto2" << std::endl;
    }
    
    //Uso del operador sobrecargado ==
    std::cout << "\nUso del operador sobrecargado ==" << std::endl;
	std::cout << "objeto1 == objeto2 ?" << std::endl;
    if (op1 == op2){
		std::cout<<"El objeto 1 es igual al objeto 2";
	}else{
		std::cout<<"El objeto 1 NO es igual al objeto 2";
	}
	return 0;
}