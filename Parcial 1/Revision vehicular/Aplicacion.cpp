#include "Aplicacion.h"

Aplicacion::Aplicacion() {
    _controladorVehiculos = new ControladorVehiculos();
    _controladorPersonas = new ControladorPersonas(_controladorVehiculos);
    _controladorCentros = new ControladorCentros();
    _controladorCitas = new ControladorCitas(_controladorVehiculos, _controladorCentros, _controladorPersonas);
    crearMenu();
}

void Aplicacion::crearMenu() {
    _menu = new Menu("Menu principal");

    _menu->opcion("Vehiculos", [this]() {
        _controladorVehiculos->mostrarMenu();
    }, false);

    _menu->opcion("Personas", [this]() {
        _controladorPersonas->mostrarMenu();
    }, false);

    _menu->opcion("Centros", [this]() {
        _controladorCentros->mostrarMenu();
    }, false);

    _menu->opcion("Citas", [this]() {
        _controladorCitas->mostrarMenu();
    }, false);

    _menu->opcionSalir();
}

void Aplicacion::iniciar() {
    _menu->iniciar();
}
