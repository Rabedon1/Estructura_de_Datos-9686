#pragma once
#include "lista/ListaEnlazada.h"
#include "modelo/Centro.h"

class ControladorCentros {
public:
    ControladorCentros();
    void mostrarMenu();
    void listarCentros();
    void buscarCentro();
    void eliminarCentro();
    void modificarCentro();
    void crearCentro();
    ListaEnlazada<Centro> leerCentros();

private:
    ListaEnlazada<Centro> _centros;
};
