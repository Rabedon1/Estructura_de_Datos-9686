#include "ControladorCitas.h"
#include "menu/Menu.h"
#include "ControladorPersonas.h"
#include "misc/Utilidades.h"
#include "fort.hpp"
#include "misc/fecha.h"
#include <map>
#include "Windows.h"

ControladorCitas::ControladorCitas(ControladorVehiculos *controladorVehiculos, ControladorCentros *controladorCentros,
                                   ControladorPersonas *controladorPersonas) {
    _controladorVehiculos = controladorVehiculos;
    _controladorCentros = controladorCentros;
    _controladorPersonas = controladorPersonas;
    leerCitas();
}

void ControladorCitas::mostrarMenu() {
    Menu menu("Menu de citas");

    menu.opcion("Crear cita", std::bind(&ControladorCitas::crearCita, this));
    menu.opcion("Listar citas", std::bind(&ControladorCitas::listarCitas, this));
    menu.opcion("Buscar cita", std::bind(&ControladorCitas::buscarCita, this));
    menu.opcion("Eliminar cita", std::bind(&ControladorCitas::eliminarCita, this));
    menu.opcionSalir("Regresar");
    menu.iniciar();
}

void ControladorCitas::crearCita() {
    auto automoviles = _controladorVehiculos->leerAutomoviles();
    auto centros = _controladorCentros->leerCentros();
    auto personas = _controladorPersonas->leerPersonas();

    if (automoviles.estaVacia()) {
        std::cout << "No hay automoviles registrados" << std::endl;
        return;
    }

    if (centros.estaVacia()) {
        std::cout << "No hay centros registrados" << std::endl;
        return;
    }

    if (personas.estaVacia()) {
        std::cout << "No hay personas registradas" << std::endl;
        return;
    }

    _controladorPersonas->listarPersonas();
    int seleccionado;

    seleccionado = utilidades::leerEntero("Seleccione una persona o 0 para cancelar: ", 0, personas.total());

    if (seleccionado == 0) {
        return;
    }

    auto persona = personas.obtener(seleccionado - 1);

    if (!_controladorPersonas->tieneAutomovilAsignado(persona)) {
        std::cout << "La persona seleccionada no tiene un automovil asignado, por favor asignelo en personas > asignar automovil" << std::endl;
        return;
    }

    auto automovilesAsignados = _controladorPersonas->obtenerAutomovilesAsignados(persona);

    fort::char_table tabla;
    int posicion = 1;

    tabla << fort::header << "No" << "Placa" << "Chasis" << "Marca" << "Color" << "Anio" << fort::endr;

    automovilesAsignados.recorrer([&posicion, &tabla](Automovil automovil) {
        tabla
            << posicion++ << automovil.getPlaca() << automovil.getChasis() << automovil.getMarca()
            << automovil.getColor() << automovil.getAnio() << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl;

    seleccionado = utilidades::leerEntero("Seleccione un automovil o 0 para cancelar: ", 0, automovilesAsignados.total());

    if (seleccionado == 0) {
        return;
    }

    auto automovil = automovilesAsignados.obtener(seleccionado - 1);

    std::cout << std::endl  << std::endl;
    _controladorCentros->listarCentros();

    seleccionado = utilidades::leerEntero("Seleccione un centro o 0 para cancelar: ", 0, centros.total());

    if (seleccionado == 0) {
        return;
    }

    auto centro = centros.obtener(seleccionado - 1);

    Fecha fecha;
    Hora hora;

    do {
        fecha = Fecha::ingresar("Ingrese la fecha de la cita (dd/mm/aaaa): ");
        hora = Hora::ingresar("Ingrese la hora de la cita (hh:mm): ");
        bool fechaOcupada = false;

        _citas.recorrer([&](Cita cita) {
            Fecha fecha2 = cita.getFecha();
            Hora hora2 = cita.getHora();
            bool mismaFecha =
                    fecha.dia() == fecha2.dia() && fecha.mes() == fecha2.mes() && fecha.anio() == fecha2.anio();
            bool mismaHora = hora.getHora() == hora2.getHora() && hora.getMinuto() == hora2.getMinuto();
            bool mismoCentro = cita.getCentro().getId() == centro.getId();
            bool mismoAutomovil = cita.getAutomovil().getPlaca() == automovil.getPlaca();

            if (!fechaOcupada && (mismaFecha && mismaHora && mismoAutomovil)) {
                fechaOcupada = true;
                return;
            }
        });

        if (fechaOcupada) {
            std::cout << "Ya existe una cita en esa fecha y hora" << std::endl;
            continue;
        }

        break;
    } while (true);

    int id = utilidades::obtenerUltimoId(_citas) + 1;
    Cita cita(id, persona, automovil, centro, fecha, hora);
    _citas.agregar(cita);
    utilidades::escribirCsv("citas.txt", _citas);

    std::cout << "creando cita..." << std::endl;
    generarComprobante(cita);
    std::cout << "Cita creada con exito" << std::endl;

}

void ControladorCitas::listarCitas() {
    fort::char_table tabla;
    int posicion = 1;

    leerCitas();

    if (_citas.estaVacia()) {
        std::cout << "No hay citas registradas" << std::endl;
        return;
    }

    tabla << fort::header << "No" << "Persona" << "Automovil" << "Centro" << "Fecha" << "Hora" << fort::endr;

    _citas.recorrer([&posicion, &tabla](Cita cita) {
        auto fecha = cita.getFecha();
        auto hora = cita.getHora();

        tabla
            << posicion++
            << (cita.getPersona().getNombres() + " (" + cita.getPersona().getCedula() + ")")
            << cita.getAutomovil().getPlaca()
            << cita.getCentro().getNombre()
            << fecha.formatear("%d/%m/%Y")
            << hora.str()
            << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl;
}

void ControladorCitas::eliminarCita() {
    leerCitas();

    if (_citas.estaVacia()) {
        std::cout << "No hay citas registradas" << std::endl;
        return;
    }

    listarCitas();

    int seleccionado = utilidades::leerEntero("Seleccione una cita o 0 para cancelar: ", 0, _citas.total());

    if (seleccionado == 0) {
        return;
    }

    auto cita = _citas.obtener(seleccionado - 1);

    if (utilidades::confirmar("Esta seguro que desea eliminar la cita?")) {
        _citas.eliminar(seleccionado - 1);
        utilidades::escribirCsv("citas.txt", _citas);
        std::cout << "Cita eliminada con exito" << std::endl;
    }
}

void ControladorCitas::buscarCita() {
    std::string termino;

    leerCitas();

    if (_citas.estaVacia()) {
        std::cout << "No hay citas registradas" << std::endl;
        return;
    }

    termino = utilidades::leerCadena("Ingrese una cedula o placa: ");

    auto busqueda = _citas.buscarTodos([termino](Cita cita) {
        return utilidades::cadenasIguales(cita.getPersona().getCedula(), termino)
            || utilidades::cadenasIguales(cita.getAutomovil().getPlaca(), termino);
    });

    if (busqueda.estaVacia()) {
        std::cout << "No se encontraron resultados" << std::endl;
        return;
    }

    fort::char_table tabla;
    int posicion = 1;

    tabla << fort::header << "No" << "Persona" << "Automovil" << "Centro" << "Fecha" << "Hora" << fort::endr;

    busqueda.recorrer([&posicion, &tabla](Cita cita) {
        auto fecha = cita.getFecha();
        auto hora = cita.getHora();

        tabla
            << posicion++ << cita.getPersona().getNombres() << cita.getAutomovil().getPlaca()
            << cita.getCentro().getNombre() << fecha.formatear("%d/%m/%Y") << hora.str() << fort::endr;
    });

    std::cout << tabla.to_string() << std::endl;
}

ListaEnlazada<Cita> ControladorCitas::leerCitas() {
    auto lineas = utilidades::leerCsv("citas.txt");
    ListaEnlazada<Cita> citas;

    auto personas = _controladorPersonas->leerPersonas();
    auto centros = _controladorCentros->leerCentros();
    auto automoviles = _controladorVehiculos->leerAutomoviles();

    lineas.recorrer([&](ListaEnlazada<ColumnaCsv> columnas) {
        if (columnas.total() < 6) {
            return;
        }

        int id = std::stoi(columnas.obtener(0).getContenido());
        int personaId = std::stoi(columnas.obtener(1).getContenido());
        int automovilId = std::stoi(columnas.obtener(2).getContenido());
        int centroId = std::stoi(columnas.obtener(3).getContenido());
        Fecha fecha = Fecha::parse(columnas.obtener(4).getContenido());
        Hora hora = Hora::parse(columnas.obtener(5).getContenido());

        auto nodoPersona = personas.buscar([personaId](Persona p){ return p.getId() == personaId; });
        auto nodoCentro = centros.buscar([centroId](Centro c){ return c.getId() == centroId; });
        auto nodoAutomovil = automoviles.buscar([automovilId](Automovil a){ return a.getId() == automovilId; });

        if (nodoPersona != nullptr && nodoCentro != nullptr && nodoAutomovil != nullptr) {
            auto persona = nodoPersona->getDato();
            auto centro = nodoCentro->getDato();
            auto automovil = nodoAutomovil->getDato();

            citas.agregar(Cita(id, persona, automovil, centro, fecha, hora));
        }
    });

    _citas = citas;
    return _citas;
}

void ControladorCitas::generarComprobante(Cita cita) {
    std::ifstream plantilla("comprobante.html");
    std::ostringstream sstr;
    sstr << plantilla.rdbuf();
    std::string html = sstr.str();
    std::map<std::string, std::string> valores;

    Fecha fecha = cita.getFecha();
    Hora hora = cita.getHora();

    valores.insert({ "cita_id", std::to_string(cita.getId()) });
    valores.insert({ "cita_fecha", fecha.formatear("%d/%m/%Y") });
    valores.insert({ "cita_hora", hora.str() });
    valores.insert({ "cita_centro", cita.getCentro().getNombre() });

    valores.insert({ "persona_nombres", cita.getPersona().getNombres() });
    valores.insert({ "persona_apellidos", cita.getPersona().getApellidos() });
    valores.insert({ "persona_cedula", cita.getPersona().getCedula() });
    valores.insert({ "persona_telefono", cita.getPersona().getTelefono() });
    valores.insert({ "persona_email", cita.getPersona().getEmail() });

    valores.insert({ "automovil_placa", cita.getAutomovil().getPlaca() });
    valores.insert({ "automovil_chasis", cita.getAutomovil().getChasis() });
    valores.insert({ "automovil_marca", cita.getAutomovil().getMarca() });
    valores.insert({ "automovil_color", cita.getAutomovil().getColor() });
    valores.insert({ "automovil_anio", std::to_string(cita.getAutomovil().getAnio()) });

    for (auto const& [clave, valor] : valores) {
        size_t start_pos = 0;

        while((start_pos = html.find("{{" + clave + "}}", start_pos)) != std::string::npos) {
            html.replace(start_pos, clave.length() + 4, valor);
            start_pos += valor.length();
        }
    }

    std::string archivoEntrada = "comprobante-" + std::to_string(cita.getId()) + ".html";
    std::string archivoSalida = "comprobante-" + std::to_string(cita.getId()) + ".pdf";
    std::ofstream comprobante(archivoEntrada);
    comprobante << html;
    comprobante.close();

    std::string comando = "wkhtmltopdf/wkhtmltopdf.exe --load-media-error-handling ignore --load-error-handling ignore -q " + archivoEntrada + " " + archivoSalida;
    WinExec(comando.c_str(), SW_HIDE);

    // while true hasta que el archivo de salida se haya generado
    while (true) {
        std::ifstream f(archivoSalida);

        if (f.good()) {
            f.close();
            break;
        }

        f.close();
        Sleep(500);
    }

    Sleep(500);
    system(std::string("start " + archivoSalida).c_str());
    DeleteFileA(archivoEntrada.c_str());
}
