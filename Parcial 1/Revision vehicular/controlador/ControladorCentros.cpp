#include "ControladorCentros.h"
#include "menu/Menu.h"
#include "misc/Utilidades.h"
#include "fort.hpp"
#include <iostream>

ControladorCentros::ControladorCentros() {
    if (!utilidades::archivo_existe("centros.txt")) {
        _centros.agregar(Centro(1, "Centro Mixto Guamani", "Guamani", "0932537113"));
        _centros.agregar(Centro(2, "Centro Livianos Via Chillos", "Chillos", "0900421700"));
        _centros.agregar(Centro(3, "Centro Livianos San Isidro Del Inca", "San Isidro del Inca", "0902482591"));
        _centros.agregar(Centro(4, "Centro Mixto Carapungo", "Carapungo", "026111522"));
        _centros.agregar(Centro(5, "Centro Livianos Guajalo", "Guaquilo", "0911108556"));
        _centros.agregar(Centro(6, "Centro Livianos Florida Alta", "Florida Alta", "0920854793"));
        _centros.agregar(Centro(7, "Centro Quitumbe", "Quitumbe", "025912137"));
        _centros.agregar(Centro(8, "Centro Bicentenario", "Parque Bicentenario", "023227816"));
        utilidades::escribirCsv("centros.txt", _centros);
    }

    leerCentros();
}

void ControladorCentros::mostrarMenu() {
    Menu menu("Gestionar Centros");
    menu.opcion("Crear Centro", std::bind(&ControladorCentros::crearCentro, this));
    menu.opcion("Buscar Centro", std::bind(&ControladorCentros::buscarCentro, this));
    menu.opcion("Listar Centros", std::bind(&ControladorCentros::listarCentros, this));
    menu.opcion("Eliminar Centro", std::bind(&ControladorCentros::eliminarCentro, this));
    menu.opcion("Modificar Centro", std::bind(&ControladorCentros::modificarCentro, this));
    menu.opcionSalir("Regresar");
    menu.iniciar();
}

void ControladorCentros::listarCentros() {
    leerCentros();

    std::cout << "Listado de Centros" << std::endl << std::endl;

    if (_centros.estaVacia()) {
        std::cout << "No hay Centros registrados" << std::endl;
        return;
    }

    fort::char_table tabla;

    tabla << fort::header
        << "No"
        << "Nombre"
        << "Direccion"
        << "Telefono"
        << fort::endr;

    int posicion = 1;

    _centros.recorrer([&](Centro centro) {
        tabla
            << posicion++
            << centro.getNombre()
            << centro.getDireccion()
            << centro.getTelefono()
            << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl;
}

void ControladorCentros::crearCentro() {
    Centro centro;

    centro.setId(utilidades::obtenerUltimoId(_centros) + 1);
    centro.setNombre(utilidades::leerCadena("Ingrese el nombre del centro: "));
    centro.setDireccion(utilidades::leerCadena("Ingrese la direccion del centro: "));
    centro.setTelefono(utilidades::leerTelefono("Ingrese el telefono del centro: "));

    _centros.agregar(centro);
    utilidades::escribirCsv<Centro>("centros.txt", _centros);
    std::cout << "Centro creado" << std::endl;
}

void ControladorCentros::buscarCentro() {
    std::string termino = utilidades::minusculas(utilidades::leerCadena("Ingrese el nombre del Centro: "));

    auto busqueda = _centros.buscarTodos([termino](Centro c) {
        return utilidades::minusculas(c.getNombre()).find(termino) != std::string::npos
            || utilidades::minusculas(c.getDireccion()).find(termino) != std::string::npos
            || utilidades::minusculas(c.getTelefono()).find(termino) != std::string::npos;
    });

    if (!busqueda.estaVacia()) {
        std::cout << std::endl << "Centros encontrados" << std::endl << std::endl;

        fort::char_table tabla;

        tabla << fort::header
            << "Nombre"
            << "Direccion"
            << "Telefono"
            << fort::endr;

        busqueda.recorrer([&](Centro centro) {
            tabla << centro.getNombre()
                << centro.getDireccion()
                << centro.getTelefono()
                << fort::endr;
        });

        std::cout << tabla.to_string() << std::endl;
    } else {
        std::cout << "No se encontraron resultados" << std::endl;
    }
}

void ControladorCentros::eliminarCentro() {
    fort::char_table tabla;
    int posicion = 1;

    leerCentros();

    if (_centros.estaVacia()) {
        std::cout << "No hay Centros registrados" << std::endl;
        return;
    }

    tabla << fort::header
        << "No"
        << "Nombre"
        << "Direccion"
        << "Telefono"
        << fort::endr;

    _centros.recorrer([&](Centro centro) {
        tabla
            << posicion++
            << centro.getNombre()
            << centro.getDireccion()
            << centro.getTelefono()
            << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl << std::endl;

    int opcion = utilidades::leerEntero("Seleccione el centro a eliminar o 0 para cancelar: ", 0, _centros.total());

    if (opcion == 0) {
        return;
    }

    auto centro = _centros.obtener(opcion - 1);

    if (utilidades::confirmar("Esta seguro de eliminar el centro (" + centro.getNombre() +  ")?")) {
        _centros.eliminar(opcion - 1);
        utilidades::escribirCsv<Centro>("centros.txt", _centros);
        std::cout << "Centro eliminado" << std::endl;
    }
}

void ControladorCentros::modificarCentro() {
    fort::char_table tabla;
    int posicion = 1;

    leerCentros();

    if (_centros.estaVacia()) {
        std::cout << "No hay Centros registrados" << std::endl;
        return;
    }

    tabla << fort::header
        << "No"
        << "Nombre"
        << "Direccion"
        << "Telefono"
        << fort::endr;

    leerCentros();
    _centros.recorrer([&](Centro centro) {
        tabla
            << posicion++
            << centro.getNombre()
            << centro.getDireccion()
            << centro.getTelefono()
            << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl << std::endl;

    int opcion = utilidades::leerEntero("Seleccione el centro a modificar o 0 para cancelar: ", 0, _centros.total());

    if (opcion == 0) {
        return;
    }

    auto centro = _centros.obtener(opcion - 1);

    std::cout << std::endl << "Centro seleccionado" << std::endl << std::endl;

    tabla = fort::char_table();

    tabla << fort::header
        << "Nombre"
        << "Direccion"
        << "Telefono"
        << fort::endr;

    tabla << centro.getNombre()
        << centro.getDireccion()
        << centro.getTelefono()
        << fort::endr;

    std::cout << tabla.to_string() << std::endl << std::endl;

    if (utilidades::confirmar("Esta seguro de modificar el centro (" + centro.getNombre() +  ")?")) {
        std::string nombre = utilidades::leerCadena("Ingrese el nombre del centro (" + centro.getNombre() + "): ");
        std::string direccion = utilidades::leerCadena("Ingrese la direccion del centro (" + centro.getDireccion() + "): ");
        std::string telefono = utilidades::leerTelefono("Ingrese el telefono del centro (" + centro.getTelefono() + "): ");

        if (nombre.empty()) {
            nombre = centro.getNombre();
        }

        if (direccion.empty()) {
            direccion = centro.getDireccion();
        }

        if (telefono.empty()) {
            telefono = centro.getTelefono();
        }

        centro.setNombre(nombre);
        centro.setDireccion(direccion);
        centro.setTelefono(telefono);

        _centros.modificar(opcion - 1, centro);
        utilidades::escribirCsv<Centro>("centros.txt", _centros);
        std::cout << "Centro modificado" << std::endl;
    }
}

ListaEnlazada<Centro> ControladorCentros::leerCentros() {
    _centros = utilidades::leerCsvModelo<Centro>("centros.txt", [](auto columnas) {
        Centro centro;

        columnas.recorrer([&](auto columna) {
            switch (columna.getIndice()) {
                case 0:
                    centro.setId(std::stoi(columna.getContenido()));
                    break;
                case 1:
                    centro.setNombre(columna.getContenido());
                    break;
                case 2:
                    centro.setDireccion(columna.getContenido());
                    break;
                case 3:
                    centro.setTelefono(columna.getContenido());
                    break;
            }
        });

        return centro;
    });

    return _centros;
}
