/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 22/05/23 20:32
 * Fecha de modificacion: 23/05/23 22:30
 * Enunciado: Realice operaciones con sobrecargas.
 * Tema: operadores sobrecargados
 *******************************************************************************/ 

#include <iostream>
#include "Operacion.h"
#include "Dato.h"

int main(int argc, char** argv) {
	float fnum1, fnum2;
	
	std::cout << "Objeto 1 \nIngresar el primer decimal: " << std::endl;
	fnum1 = Dato::ingresosFloat();
	std::cout << "Ingresar el segundo decimal: " << std::endl;
	fnum2 = Dato::ingresosFloat();
	Operacion op1(fnum1, fnum2);
	
	std::cout << "Objeto 2 \nIngresar el primer decimal: " << std::endl;
	fnum1 = Dato::ingresosFloat();
	std::cout << "Ingresar el segundo decimal: " << std::endl;
	fnum2 = Dato::ingresosFloat();
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
        std::cout << "La suma total del objeto1 es mayor o igual que objeto2" << std::endl;
    } else {
        std::cout << "La suma total del objeto1 es menor que objeto2" << std::endl;
    }
    
    //Uso del operador sobrecargado ==
    std::cout << "\nUso del operador sobrecargado ==" << std::endl;
	std::cout << "objeto1 == objeto2 ?" << std::endl;
    if (op1 == op2){
		std::cout<<"El objeto 1 es igual al objeto 2";
	}else{
		std::cout<<"El objeto 1 no es igual, al objeto 2";
	}
	return 0;
}