#pragma once
#include "lista/ListaEnlazada.h"
#include "ControladorVehiculos.h"
#include "modelo/Persona.h"

class ControladorPersonas {
public:
    ControladorPersonas(ControladorVehiculos *controladorAutomoviles);

    void mostrarMenu();
    ListaEnlazada<Persona> leerPersonas();
    void crearPersona();
    void listarPersonas();
    void buscarPersona();
    void eliminarPersona();
    void modificarPersona();
    void menuOpcionAsignarAutomovil();
    void asignarAutomovil(Persona persona, Automovil automovil);
    bool estaAsignado(Persona persona, Automovil automovil);
    bool tieneAutomovilAsignado(Persona persona);
    bool automovilOcupado(Automovil automovil);
    ListaEnlazada<Automovil> obtenerAutomovilesAsignados(Persona persona);
    void guardarPersonas();

private:
    ControladorVehiculos* _controladorAutomoviles;
    ListaEnlazada<Persona> _personas;
};

