#include "RegistroVehicular.h"
#include <iostream>

RegistroVehicular::RegistroVehicular() : first(nullptr), last(nullptr) {}

RegistroVehicular::~RegistroVehicular() {
    Nodo* current = first;
    while (current != nullptr) {
        Nodo* next = current->next;
        delete current;
        current = next;
    }
}

void RegistroVehicular::agregarRegistro(Persona<std::string>* persona, Auto* autoObj) {
    Nodo* nuevoNodo = new Nodo(persona, autoObj);
    if (first == nullptr) {
        first = nuevoNodo;
        last = nuevoNodo;
    } else {
        last->next = nuevoNodo;
        nuevoNodo->prev = last;
        last = nuevoNodo;
    }
}

void RegistroVehicular::mostrarRegistros() const {
    Nodo* current = first;
    while (current != nullptr) {
        std::cout << "Nombre: " << current->persona->getNombre() << std::endl;
        std::cout << "Cédula: " << current->persona->getCedula() << std::endl;
        std::cout << "Teléfono: " << current->persona->getTelefono() << std::endl;
        std::cout << "Modelo: " << current->autoObj->getModelo() << std::endl;
        std::cout << "Color: " << current->autoObj->getColor() << std::endl;
        std::cout << "Motor: " << current->autoObj->getMotor() << std::endl;
        std::cout << "Marca: " << current->autoObj->getMarca() << std::endl;
        std::cout << "Fecha de matriculación: " << current->autoObj->getFechaMatriculacion() << std::endl;
        std::cout << "Placa: " << current->autoObj->getPlaca() << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        current = current->next;
    }
}
