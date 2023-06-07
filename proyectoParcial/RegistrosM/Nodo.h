#ifndef NODO_H
#define NODO_H

#include "Persona.h"
#include "Auto.h"

class Nodo {
public:
    Persona<std::string>* persona;
    Auto* autoObj;
    Nodo* prev;
    Nodo* next;

    Nodo(Persona<std::string>* persona, Auto* autoObj);
    ~Nodo();
};

#endif  // NODO_H
