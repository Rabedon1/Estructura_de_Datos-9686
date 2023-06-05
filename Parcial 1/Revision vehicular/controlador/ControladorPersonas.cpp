#include "ControladorPersonas.h"
#include "menu/Menu.h"
#include "misc/Utilidades.h"
#include "fort.hpp"

ControladorPersonas::ControladorPersonas(ControladorVehiculos *controladorAutomoviles) {
    _controladorAutomoviles = controladorAutomoviles;
    leerPersonas();
}

void ControladorPersonas::mostrarMenu() {
    Menu menu("Menu personas");

    menu.opcion("Ingresar persona", std::bind(&ControladorPersonas::crearPersona, this));
    menu.opcion("Buscar persona", std::bind(&ControladorPersonas::buscarPersona, this));
    menu.opcion("Listar personas", std::bind(&ControladorPersonas::listarPersonas, this));
    menu.opcion("Eliminar persona", std::bind(&ControladorPersonas::eliminarPersona, this));
    menu.opcion("Modificar persona", std::bind(&ControladorPersonas::modificarPersona, this));
    menu.opcion("Asignar automovil", std::bind(&ControladorPersonas::menuOpcionAsignarAutomovil, this));
    menu.opcionSalir("Regresar");
    menu.iniciar();
}

void ControladorPersonas::crearPersona() {
    std::string nombres;
    std::string apellidos;
    std::string cedula;
    std::string telefono;
    std::string direccion;
    std::string email;

    nombres = utilidades::leerCadena("Ingrese los nombres de la persona: ", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
    apellidos = utilidades::leerCadena("Ingrese los apellidos de la persona: ", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");

    leerPersonas();

    do {
        cedula = utilidades::leerCadena("Ingrese la cedula de la persona: ", "^[0-9]{10}$");

        if (!utilidades::cedula_valida(cedula)) {
            std::cout << std::endl << "[La cedula ingresada no es valida]" << std::endl;
        }

        auto existe = _personas.buscar([cedula](Persona persona) {
            return utilidades::recortarEspaciosCostados(persona.getCedula()) == utilidades::recortarEspaciosCostados(cedula);
        }) != nullptr;

        if (existe) {
            std::cout << std::endl << "[La cedula ingresada ya esta registrada]" << std::endl;
            continue;
        }
    } while (!utilidades::cedula_valida(cedula));

    telefono = utilidades::leerTelefono("Ingrese el telefono de la persona: ");
    direccion = utilidades::leerCadena("Ingrese la direccion de la persona: ");

    do {
        email = utilidades::leerCadena("Ingrese el email de la persona: ", R"(^([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))$)");

        auto encontrado = _personas.buscar([email](Persona p) {
            return utilidades::minusculas(p.getEmail()) == utilidades::minusculas(email);
        }) != nullptr;

        if (encontrado) {
            std::cout << std::endl << "[Ya existe una persona con ese email]" << std::endl;
            continue;
        }

        break;
    } while (true);

    int id = utilidades::obtenerUltimoId(_personas) + 1;
    Persona persona(id, nombres, apellidos, cedula, telefono, direccion, email);
    _personas.agregar(persona);
    utilidades::escribirCsv("personas.txt", _personas);
    std::cout << std::endl << "[Persona creada con exito]" << std::endl;
}

void ControladorPersonas::listarPersonas() {
    leerPersonas();

    if (_personas.estaVacia()) {
        std::cout << std::endl << "[No hay personas registradas]" << std::endl;
        return;
    }

    fort::char_table table;
    table.set_cell_text_align(fort::text_align::center);
    table << fort::header
        << "No"
        << "Nombres"
        << "Apellidos"
        << "Cedula"
        << "Telefono"
        << "Direccion"
        << "Email"
        << fort::endr;

    int posicion = 1;

    _personas.recorrer([&] (Persona persona) {
        table
            << posicion++
            << persona.getNombres()
            << persona.getApellidos()
            << persona.getCedula()
            << persona.getTelefono()
            << persona.getDireccion()
            << persona.getEmail()
            << fort::endr;
    });

    std::cout << table.to_string() << std::endl;
}

void ControladorPersonas::buscarPersona() {
    std::string termino;

    leerPersonas();

    if (_personas.estaVacia()) {
        std::cout << std::endl << "[No hay personas registradas]" << std::endl;
        return;
    }

    termino = utilidades::leerCadena("Ingrese un termino de busqueda: ");

    auto busqueda = _personas.buscarTodos([termino](Persona p) {
        return utilidades::minusculas(p.getNombres()).find(termino) != std::string::npos
           || utilidades::minusculas(p.getApellidos()).find(termino) != std::string::npos
           || utilidades::minusculas(p.getCedula()).find(termino) != std::string::npos;
    });

    if (busqueda.estaVacia()) {
        std::cout << std::endl << "[No se encontraron resultados]" << std::endl;
        return;
    }

    fort::char_table table;
    table.set_cell_text_align(fort::text_align::center);
    table << fort::header << "Nombres" << "Apellidos" << "Cedula" << "Telefono" << "Direccion" << "Email" << fort::endr;

    busqueda.recorrer([&] (Persona persona) {
        table << persona.getNombres() << persona.getApellidos() << persona.getCedula() << persona.getTelefono() << persona.getDireccion() << persona.getEmail() << fort::endr;
    });

    std::cout << table.to_string() << std::endl;
}

void ControladorPersonas::eliminarPersona() {
    fort::char_table tabla;
    int posicion = 1;

    leerPersonas();

    if (_personas.estaVacia()) {
        std::cout << std::endl << "[No hay personas registradas]" << std::endl;
        return;
    }

    tabla << fort::header
        << "No"
        << "Nombres"
        << "Apellidos"
        << "Cedula"
        << "Direccion"
        << "Telefono"
        << "Email"
        << fort::endr;

    _personas.recorrer([&](Persona persona) {
        tabla
                << posicion++
                << persona.getNombres()
                << persona.getApellidos()
                << persona.getCedula()
                << persona.getDireccion()
                << persona.getTelefono()
                << persona.getEmail()
                << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl << std::endl;

    int opcion = utilidades::leerEntero("Seleccione la persona a eliminar o 0 para cancelar: ", 0, _personas.total());

    if (opcion == 0) {
        return;
    }

    auto persona = _personas.obtener(opcion - 1);

    if (utilidades::confirmar("Esta seguro de eliminar el centro (" + persona.getCedula() +  ")?")) {
        _personas.eliminar(opcion - 1);
        utilidades::escribirCsv<Persona>("personas.txt", _personas);
        std::cout << "Persona eliminada" << std::endl;
    }
}

void ControladorPersonas::modificarPersona() {
    fort::char_table tabla;
    int posicion = 1;

    leerPersonas();

    if (_personas.estaVacia()) {
        std::cout << std::endl << "[No hay personas registradas]" << std::endl;
        return;
    }

    tabla << fort::header
        << "No"
        << "Nombres"
        << "Apellidos"
        << "Cedula"
        << "Direccion"
        << "Telefono"
        << "Email"
        << fort::endr;

    _personas.recorrer([&](Persona persona) {
        tabla
                << posicion++
                << persona.getNombres()
                << persona.getApellidos()
                << persona.getCedula()
                << persona.getDireccion()
                << persona.getTelefono()
                << persona.getEmail()
                << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl << std::endl;

    int opcion = utilidades::leerEntero("Seleccione la persona a modificar o 0 para cancelar: ", 0, _personas.total());

    if (opcion == 0) {
        return;
    }

    auto persona = _personas.obtener(opcion - 1);

    std::string nombres = utilidades::leerCadena("Ingrese los nombres de la persona: ");
    std::string apellidos = utilidades::leerCadena("Ingrese los apellidos de la persona: ");
    std::string cedula;

    do {
        cedula = utilidades::leerCadena("Ingrese la cedula de la persona: ");

        if (!utilidades::cedula_valida(cedula)) {
            std::cout << std::endl << "[La cedula ingresada no es valida]" << std::endl;
        }

        auto encontrado = _personas.buscar([cedula](Persona p) {
            return p.getCedula() == cedula;
        });

        if (encontrado != nullptr) {
            auto p = encontrado->getDato();

            if (p.getId() != persona.getId()) {
                std::cout << std::endl << "[Ya existe una persona con esa cedula]" << std::endl;
                continue;
            }
        }
    } while (!utilidades::cedula_valida(cedula));

    std::string telefono = utilidades::leerTelefono("Ingrese el telefono de la persona: ");
    std::string direccion = utilidades::leerCadena("Ingrese la direccion de la persona: ");

    std::string email;

    do {
        email = utilidades::leerCadena("Ingrese el email de la persona: ", R"(^([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))$)");

        auto encontrado = _personas.buscar([email](Persona p) {
            return utilidades::minusculas(p.getEmail()) == utilidades::minusculas(email);
        });

        if (encontrado) {
            auto p = encontrado->getDato();

            if (p.getId() != persona.getId()) {
                std::cout << std::endl << "[Ya existe una persona con ese email]" << std::endl;
                continue;
            }
        }

        break;
    } while (true);

    persona.setNombres(nombres);
    persona.setApellidos(apellidos);
    persona.setCedula(cedula);
    persona.setTelefono(telefono);
    persona.setDireccion(direccion);
    persona.setEmail(email);

    _personas.modificar(opcion - 1, persona);
    utilidades::escribirCsv<Persona>("personas.txt", _personas);
    std::cout << "Persona modificada" << std::endl;
}

void ControladorPersonas::menuOpcionAsignarAutomovil() {
    int seleccionado = 0;
    auto automoviles = _controladorAutomoviles->leerAutomoviles();

    if (automoviles.estaVacia()) {
        std::cout << std::endl << "[No hay automoviles registrados]" << std::endl;
        return;
    }

    if (_personas.estaVacia()) {
        std::cout << std::endl << "[No hay personas registradas]" << std::endl;
        return;
    }

    _controladorAutomoviles->menuOpcionListarAutomoviles();
    Automovil automovil;
    Persona persona;

    seleccionado = utilidades::leerEntero("Seleccione el automovil a asignar o 0 para cancelar: ", 0, automoviles.total());

    if (seleccionado == 0) {
        return;
    }

    automovil = automoviles.obtener(seleccionado - 1);

    std::cout << std::endl << std::endl;

    listarPersonas();

    seleccionado = utilidades::leerEntero("Seleccione la persona a asignar o 0 para cancelar: ", 0, _personas.total());

    if (seleccionado == 0) {
        return;
    }

    persona = _personas.obtener(seleccionado - 1);

    if (estaAsignado(persona, automovil)) {
        std::cout << std::endl << "[El automovil ya esta asignado a la persona]" << std::endl;
        return;
    }

    if (automovilOcupado(automovil)) {
        std::cout << std::endl << "[El automovil ya esta asignado a otra persona]" << std::endl;
        return;
    }

    asignarAutomovil(persona, automovil);
    std::cout << std::endl << "[Automovil asignado]" << std::endl;
}

void ControladorPersonas::asignarAutomovil(Persona persona, Automovil automovil) {
    auto lineas = utilidades::leerLineasCsv("persona_automovil.txt");
    lineas.agregar(std::to_string(persona.getId()) + "," + std::to_string(automovil.getId()));
    utilidades::escribirCsv("persona_automovil.txt", lineas);
}

bool ControladorPersonas::estaAsignado(Persona persona, Automovil automovil) {
    auto lineas = utilidades::leerCsv("persona_automovil.txt");
    bool asignado = false;

    lineas.recorrer([&](auto columnas) { // columna[0]: persona.id, columna[1]: automovil.id
        if (std::stoi(columnas.obtener(0).getContenido()) == persona.getId()
            && std::stoi(columnas.obtener(1).getContenido()) == automovil.getId()) {
            asignado = true;
        }
    });

    return asignado;
}

bool ControladorPersonas::automovilOcupado(Automovil automovil) {
    auto lineas = utilidades::leerCsv("persona_automovil.txt");
    bool ocupado = false;

    lineas.recorrer([&](auto columnas) { // columna[0]: persona.id, columna[1]: automovil.id
        if (std::stoi(columnas.obtener(1).getContenido()) == automovil.getId()) {
            ocupado = true;
        }
    });

    return ocupado;
}

bool ControladorPersonas::tieneAutomovilAsignado(Persona persona) {
    auto lineas = utilidades::leerCsv("persona_automovil.txt");
    bool tiene = false;

    lineas.recorrer([&](auto columnas) { // columna[0]: persona.id, columna[1]: automovil.id
        if (std::stoi(columnas.obtener(0).getContenido()) == persona.getId()) {
            tiene = true;
        }
    });

    return tiene;
}

ListaEnlazada<Automovil> ControladorPersonas::obtenerAutomovilesAsignados(Persona persona) {
    auto automoviles = _controladorAutomoviles->leerAutomoviles();
    auto lineas = utilidades::leerCsv("persona_automovil.txt");
    ListaEnlazada<Automovil> asignados;

    lineas.recorrer([&](auto columnas) { // columna[0]: persona.id, columna[1]: automovil.id
        if (std::stoi(columnas.obtener(0).getContenido()) == persona.getId()) {
            automoviles.recorrer([&](Automovil automovil) {
                if (automovil.getId() == std::stoi(columnas.obtener(1).getContenido())) {
                    asignados.agregar(automovil);
                }
            });
        }
    });

    return asignados;
}

ListaEnlazada<Persona> ControladorPersonas::leerPersonas() {
    _personas = utilidades::leerCsvModelo<Persona>("personas.txt", [](auto columnas) {
        Persona persona;

        columnas.recorrer([&](auto columna) {
            switch (columna.getIndice()) {
                case 0:
                    persona.setId(std::stoi(columna.getContenido()));
                    break;
                case 1:
                    persona.setNombres(columna.getContenido());
                    break;
                case 2:
                    persona.setApellidos(columna.getContenido());
                    break;
                case 3:
                    persona.setCedula(columna.getContenido());
                    break;
                case 4:
                    persona.setTelefono(columna.getContenido());
                    break;
                case 5:
                    persona.setDireccion(columna.getContenido());
                    break;
                case 6:
                    persona.setEmail(columna.getContenido());
                    break;
            }
        });

        return persona;
    });
    return _personas;
}