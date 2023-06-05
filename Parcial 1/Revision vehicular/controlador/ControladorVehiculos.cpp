#include "ControladorVehiculos.h"
#include "menu/Menu.h"
#include "misc/Utilidades.h"
#include "fort.hpp"

ControladorVehiculos::ControladorVehiculos() {
    leerAutomoviles();
}

void ControladorVehiculos::mostrarMenu() {
    Menu menu("Gestion de vehiculos");
    menu.opcion("Ingresar automovil", std::bind(&ControladorVehiculos::menuOpcionIngresarAutomovil, this));
    menu.opcion("Buscar automovil", std::bind(&ControladorVehiculos::menuOpcionBuscarAutomovil, this));
    menu.opcion("Listar automoviles", std::bind(&ControladorVehiculos::menuOpcionListarAutomoviles, this));
    menu.opcion("Eliminar automovil", std::bind(&ControladorVehiculos::menuOpcionEliminarAutomovil, this));
    menu.opcion("Modificar automovil", std::bind(&ControladorVehiculos::menuOpcionModificarAutomovil, this));
    menu.opcionSalir("Regresar");
    menu.iniciar();
}

void ControladorVehiculos::menuOpcionIngresarAutomovil() {
    Automovil automovil;

    automovil.setPlaca(leerPlaca());
    automovil.setChasis(leerChasis());
    automovil.setMarca(utilidades::leerCadena("Ingrese la marca del automovil: "));
    automovil.setColor(utilidades::leerCadena("Ingrese el color del automovil: "));
    automovil.setAnio(utilidades::leerEntero("Ingrese el anio del automovil: ", 1950, 2022));
    automovil.setId(utilidades::obtenerUltimoId(_automoviles) + 1);

    _automoviles.agregar(automovil);
    guardarAutomoviles();
    std::cout << "Automovil ingresado" << std::endl;
}

void ControladorVehiculos::menuOpcionBuscarAutomovil() {
    std::string termino = utilidades::minusculas(utilidades::leerCadena("Ingrese la placa o el chasis del automovil: "));

    Nodo<Automovil>* nodo = _automoviles.buscar([termino](Automovil a) {
        return utilidades::cadenasIguales(a.getPlaca(), termino)
            || utilidades::cadenasIguales(a.getChasis(), termino);
    });

    if (nodo) {
        Automovil automovil = nodo->getDato();
        std::cout << std::endl << "Automovil encontrado" << std::endl << std::endl;
        std::cout << automovil << std::endl;
    } else {
        std::cout << "Automovil no encontrado" << std::endl;
    }
}

void ControladorVehiculos::menuOpcionListarAutomoviles() {
    leerAutomoviles();

    std::cout << "Listado de automoviles" << std::endl << std::endl;

    if (_automoviles.estaVacia()) {
        std::cout << "No hay automoviles registrados" << std::endl;
        return;
    }

    fort::char_table tabla;
    int posicion = 1;

    tabla << fort::header << "No" << "Placa" << "Chasis" << "Marca" << "Color" << "Anio" << fort::endr;

    _automoviles.recorrer([&posicion, &tabla](Automovil automovil) {
        tabla
            << posicion++ << automovil.getPlaca() << automovil.getChasis() << automovil.getMarca()
            << automovil.getColor() << automovil.getAnio() << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl;
}

void ControladorVehiculos::menuOpcionEliminarAutomovil() {
    if (_automoviles.estaVacia()) {
        std::cout << "No hay automoviles registrados" << std::endl;
        return;
    }

    menuOpcionListarAutomoviles();

    int seleccionado = utilidades::leerEntero("Seleccione el automovil a eliminar (0 para cancelar): ", 0, _automoviles.total());

    if (seleccionado == 0) {
        return;
    }

    Automovil automovil = _automoviles.obtener(seleccionado - 1);

    if (utilidades::confirmar("Esta seguro de eliminar el automovil (" + automovil.getPlaca() + ") ?")) {
        _automoviles.eliminar(seleccionado - 1);
        guardarAutomoviles();
        std::cout << "Automovil eliminado" << std::endl;
    }
}

void ControladorVehiculos::menuOpcionModificarAutomovil() {
    if (_automoviles.estaVacia()) {
        std::cout << "No hay automoviles registrados" << std::endl;
        return;
    }

    menuOpcionListarAutomoviles();

    int seleccionado = utilidades::leerEntero("Seleccione el automovil a modificar (0 para cancelar): ", 0, _automoviles.total());

    if (seleccionado == 0) {
        return;
    }

    Automovil automovil = _automoviles.obtener(seleccionado - 1);

    std::cout << std::endl << "Automovil seleccionado" << std::endl << std::endl;
    std::cout << automovil << std::endl;

    if (utilidades::confirmar("Esta seguro de modificar el automovil (" + automovil.getPlaca() + ") ?")) {
        automovil.setPlaca(leerPlaca());
        automovil.setChasis(leerChasis());
        automovil.setMarca(utilidades::leerCadena("Ingrese la marca del automovil: "));
        automovil.setColor(utilidades::leerCadena("Ingrese el color del automovil: "));
        automovil.setAnio(utilidades::leerEntero("Ingrese el anio del automovil: ", 1950, 2022));

        _automoviles.modificar(seleccionado - 1, automovil);
        guardarAutomoviles();
        std::cout << "Automovil modificado" << std::endl;
    }
}

ListaEnlazada<Automovil> ControladorVehiculos::leerAutomoviles() {
    _automoviles = utilidades::leerCsvModelo<Automovil>("automoviles.txt", [](auto columnas) {
        Automovil automovil;

        columnas.recorrer([&](auto columna) {
            switch (columna.getIndice()) {
                case 0:
                    automovil.setId(std::stoi(columna.getContenido()));
                    break;
                case 1:
                    automovil.setPlaca(columna.getContenido());
                    break;
                case 2:
                    automovil.setChasis(columna.getContenido());
                    break;
                case 3:
                    automovil.setMarca(columna.getContenido());
                    break;
                case 4:
                    automovil.setColor(columna.getContenido());
                    break;
                case 5:
                    automovil.setAnio(std::stoi(columna.getContenido()));
                    break;
            }
        });

        return automovil;
    });

    return _automoviles;
}

void ControladorVehiculos::guardarAutomoviles() {
    utilidades::escribirCsv("automoviles.txt", _automoviles);
}

std::string ControladorVehiculos::leerPlaca() {
    std::string placa;
    placa = utilidades::leerCadena("Ingrese la placa del automovil (AAA-###): ", "^[a-zA-Z]{3}-[0-9]{3,4}$");
    return placa;
}

std::string ControladorVehiculos::leerChasis() {
    std::string chasis; // #AAAA##AAAA######
    chasis = utilidades::leerCadena("Ingrese el chasis del automovil (#AAAA##AAAA######): ", "^[0-9][a-zA-Z]{4}[0-9]{2}[a-zA-Z]{4}[0-9]{6}$");
    return chasis;
}
