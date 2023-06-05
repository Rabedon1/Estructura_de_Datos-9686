#pragma once
#include "menu/Menu.h"
#include "controlador/ControladorVehiculos.h"
#include "controlador/ControladorCentros.h"
#include "controlador/ControladorCitas.h"
#include "controlador/ControladorPersonas.h"

class Aplicacion {
public:
    Aplicacion();
    void crearMenu();
    void iniciar();

private:
    Menu* _menu;
    ControladorVehiculos* _controladorVehiculos;
    ControladorPersonas* _controladorPersonas;
    ControladorCentros* _controladorCentros;
    ControladorCitas* _controladorCitas;
};
