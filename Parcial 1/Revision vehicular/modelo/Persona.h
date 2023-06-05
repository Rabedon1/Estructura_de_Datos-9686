#pragma once
#include "Modelo.h"

class Persona : public Modelo {
public:
    Persona() : Modelo(0) {};

    Persona(
        int id, std::string nombres, std::string apellidos,
        std::string cedula, std::string telefono, std::string direccion, std::string email) : Modelo(id) {
        _nombres = nombres;
        _apellidos = apellidos;
        _cedula = cedula;
        _telefono = telefono;
        _direccion = direccion;
        _email = email;
    }

    const std::string &getCedula() const {
        return _cedula;
    }

    void setCedula(const std::string &cedula) {
        _cedula = cedula;
    }

    const std::string &getNombres() const {
        return _nombres;
    }

    void setNombres(const std::string &nombres) {
        _nombres = nombres;
    }

    const std::string &getApellidos() const {
        return _apellidos;
    }

    void setApellidos(const std::string &apellidos) {
        _apellidos = apellidos;
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

    const std::string &getEmail() const {
        return _email;
    }

    void setEmail(const std::string &email) {
        _email = email;
    }

    std::string csv() override {
        return std::to_string(getId()) + "," + _nombres + "," + _apellidos + "," + _cedula + "," + _telefono + "," + _direccion + "," + _email;
    }

    void imprimir(std::ostream& out) override {
        out << "Nombres: " << _nombres << std::endl;
        out << "Apellidos: " << _apellidos << std::endl;
        out << "Cedula: " << _cedula << std::endl;
        out << "Telefono: " << _telefono << std::endl;
        out << "Direccion: " << _direccion << std::endl;
        out << "Email: " << _email << std::endl;
    }

private:
    std::string _cedula;
    std::string _nombres;
    std::string _apellidos;
    std::string _direccion;
    std::string _telefono;
    std::string _email;
};