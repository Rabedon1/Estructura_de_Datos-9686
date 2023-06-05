#pragma once
#include "ControladorVehiculos.h"
#include "ControladorCentros.h"
#include "ControladorPersonas.h"
#include "modelo/Cita.h"
#include "lista/ListaEnlazada.h"

class ControladorCitas {
public:
    ControladorCitas(ControladorVehiculos *controladorVehiculos, ControladorCentros *controladorCentros,
                     ControladorPersonas *controladorPersonas);
    void mostrarMenu();

    void crearCita();
    void listarCitas();
    void buscarCita();
    void eliminarCita();
    ListaEnlazada<Cita> leerCitas();
    void guardarCitas();

private:
    ControladorVehiculos* _controladorVehiculos;
    ControladorCentros* _controladorCentros;
    ControladorPersonas* _controladorPersonas;
    ListaEnlazada<Cita> _citas;

    void generarComprobante(Cita cita);
};
