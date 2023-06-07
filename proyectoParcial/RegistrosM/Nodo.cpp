#include "Nodo.h"

Nodo::Nodo(Persona<std::string>* persona, Auto* autoObj)
    : persona(persona), autoObj(autoObj), prev(nullptr), next(nullptr) {}

Nodo::~Nodo() {
    delete persona;
    delete autoObj;
}
