#include "Persona.h"
template <typename T>

Persona<T>::Persona(const T& nombre, const int& cedula, const int& telefono)
    : nombre(nombre), cedula(cedula), telefono(telefono) {}

template <typename T>
T Persona<T>::getNombre() const {
    return nombre;
}

template <typename T>
int Persona<T>::getCedula() const {
    return cedula;
}

template <typename T>
int Persona<T>::getTelefono() const {
    return telefono;
}
template class Persona<std::string>;
