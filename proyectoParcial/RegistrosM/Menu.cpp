#include "Menu.h"
#include <iostream>
#include "Input.h"
using namespace std;
Menu::Menu() {}

void Menu::mostrarMenu() {
    char opcion;

    do {
        std::cout << "======= Menu =======\n";
        std::cout << "1. Agregar registro\n";
        std::cout << "2. Mostrar registros\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1':
                agregarRegistro();
                break;
            case '2':
                mostrarRegistros();
                break;
            case '3':
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción invalida. Intente nuevamente.\n";
        }

        std::cout << "\n";
    } while (opcion != '3');
}
bool Menu::validarPlaca(const std::string& placa) const {
    if (placa.length() != 6) {
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        if (!isalpha(placa[i])) {
            return false;
        }
    }

    for (int i = 3; i < 6; ++i) {
        if (!isdigit(placa[i])) {
            return false;
        }
    }

    return true;
}
void Menu::agregarRegistro() {
    Input *input = new Input();
    std::string nombre;
    int cedula;
    int telefono;
    std::string modelo, color, motor, marca, fechaMatriculacion, placa;
    char opcion = 's';
    bool bandera=0;

    while (opcion == 's' || opcion == 'S') {
        nombre=input->letters("Ingrese nombre: ",10);
        while(!bandera){
            	cedula=input->integerNumber("Ingrese Cedula: ",10);
            	std::string s = std::to_string(cedula);
            	bandera=input->isValid(s);
            	if(!bandera){
            		std::cout<<"Ingrese una cedula correcta"<<endl;
				}
			}
		telefono=input->integerNumber("Ingrese telefono: ",10);
        modelo=input->letters("Ingrese modelo del auto: ",10);
        color=input->letters("Ingrese color del auto: ",10);
        std::cout << "Ingrese motor del auto: ";
        std::cin >> motor;
        marca=input->letters("Ingrese marca del auto: ",10);
        std::cout << "Ingrese fecha de matriculación del auto: ";
        std::cin >> fechaMatriculacion;
        bandera=0;
        do {
        std::cout << "Ingrese placa del auto: ";
        std::cin >> placa;

        bandera = validarPlaca(placa);

        if (!bandera) {
            std::cout << "La placa ingresada no tiene el formato correcto. Debe ser de 3 letras seguidas de 3 números.\n";
        }
        } while (!bandera);

        Persona<std::string>* persona = new Persona<std::string>(nombre, cedula, telefono);
        Auto* autoObj = new Auto(modelo, color, motor, marca, fechaMatriculacion, placa);

        registro.agregarRegistro(persona, autoObj);

        std::cout << "¿Desea agregar otro registro? (s/n): ";
        std::cin >> opcion;
    }
}

void Menu::mostrarRegistros() {
    std::cout << "Registros almacenados:" << std::endl;
    registro.mostrarRegistros();
}

