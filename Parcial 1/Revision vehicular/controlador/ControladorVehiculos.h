#pragma once
#include "lista/ListaEnlazada.h"
#include "modelo/Automovil.h"

class ControladorVehiculos {
public:
    ControladorVehiculos();
    void mostrarMenu();

    void menuOpcionIngresarAutomovil();
    void menuOpcionBuscarAutomovil();
    void menuOpcionListarAutomoviles();
    void menuOpcionEliminarAutomovil();
    void menuOpcionModificarAutomovil();

    ListaEnlazada<Automovil> leerAutomoviles();

private:
    ListaEnlazada<Automovil> _automoviles;

    void guardarAutomoviles();

    std::string leerPlaca();
    std::string leerChasis();
};
