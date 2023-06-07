#ifndef REGISTROVEHICULAR_H
#define REGISTROVEHICULAR_H

#include "Nodo.h"

class RegistroVehicular {
private:
    Nodo* first;
    Nodo* last;

public:
    RegistroVehicular();
    ~RegistroVehicular();
    void agregarRegistro(Persona<std::string>* persona, Auto* autoObj);
    void mostrarRegistros() const;
};

#endif  // REGISTROVEHICULAR_H
