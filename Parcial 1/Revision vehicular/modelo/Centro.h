#pragma once
#include <string>
#include <iostream>
#include "Modelo.h"

class Centro : public Modelo {
public:
    Centro() : Modelo(0) {};

    Centro(int id, std::string nombre, std::string direccion, std::string telefono) : Modelo(id) {
        _nombre = nombre;
        _direccion = direccion;
        _telefono = telefono;
    }

    const std::string &getNombre() const {
        return _nombre;
    }

    void setNombre(const std::string &nombre) {
        _nombre = nombre;
    }

    const std::string &getDireccion() const {
        return _direccion;
    }

    void setDireccion(const std::string &direccion) {
        _direccion = direccion;
    }

    const std::string &getTelefono() const {
        return _telefono;
    }

    void setTelefono(const std::string &telefono) {
        _telefono = telefono;
    }

    std::string csv() override {
        return std::to_string(getId()) + "," + _nombre + "," + _direccion + "," + _telefono;
    }

    void imprimir(std::ostream& os) override {
        os << "Nombre: " << _nombre << std::endl;
        os << "Direccion: " << _direccion << std::endl;
    }

private:
    std::string _nombre;
    std::string _direccion;
    std::string _telefono;
};
