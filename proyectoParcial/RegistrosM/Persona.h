
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
template <typename T>
class Persona {
private:
    T nombre;
    int cedula;
    int telefono;

public:
    Persona(const T& nombre, const int& cedula, const int& telefono);
    T getNombre() const;
    int getCedula() const;
    int getTelefono() const;
};

#endif  // PERSONA_H
