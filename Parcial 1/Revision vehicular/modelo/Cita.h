#pragma once
#include "Automovil.h"
#include "Centro.h"
#include "misc/fecha.h"
#include "misc/Hora.h"
#include <string>

class Cita : public Modelo {
public:
    Cita() : Modelo(0) {};

    Cita(int id, Persona persona, Automovil automovil, Centro centro, Fecha fecha, Hora hora) : Modelo(id) {
        _persona = persona;
        _automovil = automovil;
        _centro = centro;
        _fecha = fecha;
        _hora = hora;
    }

    const Fecha getFecha() const {
        return _fecha;
    }

    void setFecha(const Fecha &fecha) {
        _fecha = fecha;
    }

    const Hora &getHora() const {
        return _hora;
    }

    void setHora(const Hora &hora) {
        _hora = hora;
    }

    const Centro &getCentro() const {
        return _centro;
    }

    void setCentro(const Centro &centro) {
        _centro = centro;
    }

    const Persona &getPersona() const {
        return _persona;
    }

    void setPersona(const Persona &persona) {
        _persona = persona;
    }

    const Automovil &getAutomovil() const {
        return _automovil;
    }

    void setAutomovil(const Automovil &automovil) {
        _automovil = automovil;
    }

    std::string csv() override {
        return std::to_string(getId()) + ","
            + std::to_string(_persona.getId()) + ","
            + std::to_string(_automovil.getId()) + ","
            + std::to_string(_centro.getId()) + ","
            + _fecha.formatear("%d/%m/%Y")
            + "," + _hora.str();
    }

    void imprimir(std::ostream& os) override {
        os << "Cita #" << getId() << std::endl;
        os << "Persona: " << _persona.getNombres() << " [" << _persona.getCedula() << "]" << std::endl;
        os << "Automovil: " << _automovil.getPlaca() << std::endl;
        os << "Centro: " << _centro.getNombre() << std::endl;
        os << "Fecha: " << _fecha.formatear("%d/%m/%Y") << std::endl;
        os << "Hora: " << _hora.str() << std::endl;
    }

private:
    Fecha _fecha;
    Hora _hora;
    Centro _centro;
    Persona _persona;
    Automovil _automovil;
};