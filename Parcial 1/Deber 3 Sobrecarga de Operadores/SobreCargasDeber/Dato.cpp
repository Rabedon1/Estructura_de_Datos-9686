/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 22/05/23 20:32
 * Fecha de modificacion: 23/05/23 22:30
 * Enunciado: Realice operaciones con sobrecargas.
 * Tema: operadores sobrecargados
 *******************************************************************************/ 
#include "Dato.h"
#include <iostream>
#include <cstdlib> //funcion atoi()
#include <conio.h> //getch()

using namespace std;

//Ingresar numeros de menu
int Dato::ingresoMenu(char cnum1, char cnum2) {		
	char *entrada = new char[30];
	char tipoope;
	int i = 0;
	
	while (true) {
		tipoope = getch(); // lee la tipoope ingresada por el usuario sin mostrarla en la consola
		
		if (tipoope == '\r') { // si el usuario presiona Enter
		  cout << endl;
		  break;
		} else if (tipoope == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tipoope >= cnum1 && tipoope <= cnum2 && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tipoope;
			  cout << tipoope; // muestra el caracter ingresado en la consola
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
}

//Ingresar numeros enteros
int Dato::ingresoEntero() {		
	char *entrada = new char[30];
	char tipoope;
	int i = 0;
	
	while (true) {
		tipoope = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tipoope == '\r') { // si el usuario presiona Enter
		  cout << endl;
		  break;
		} else if (tipoope == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tipoope) && i<12) { // si el usuario ingresa un dígito
			  entrada[i++] = tipoope;
			  cout << tipoope; // muestra el caracter ingresado en la consola
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
}


float Dato::ingresosFloat() {
	char *entrada = new char[30];
	char tipoope;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tipoope = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tipoope == '\r') { // si el usuario presiona Enter
		  cout << endl;
		  break;
		} else if (tipoope == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tipoope) && i < 15) { // si el usuario ingresa un dígito
			  entrada[i++] = tipoope;
			  cout << tipoope; // muestra el caracter ingresado en la consola
		} else if (tipoope == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			  entrada[i++] = tipoope;
			  punto = true; // marca que se ha ingresado un punto
			  cout << tipoope;
		} else if (tipoope == '-' && i == 0) { // si el usuario ingresa un signo menos al principio
			  entrada[i++] = tipoope;
			  signoMenosPos = i - 1; // marca la posición del signo menos
			  cout << tipoope;
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
  
}