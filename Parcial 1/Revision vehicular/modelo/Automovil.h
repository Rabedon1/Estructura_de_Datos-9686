#pragma once
#include <string>
#include <ostream>
#include "Modelo.h"

class Automovil : public Modelo {
public:
    Automovil() : Modelo(0) {};
    Automovil(int id, std::string placa, std::string chasis, std::string marca, std::string color, int anio) : Modelo(id) {
        _placa = placa;
        _chasis = chasis;
        _marca = marca;
        _color = color;
        _anio = anio;
    }

    const std::string &getPlaca() const {
        return _placa;
    }

    void setPlaca(const std::string &placa) {
        _placa = placa;
    }

    const std::string &getChasis() const {
        return _chasis;
    }

    void setChasis(const std::string &chasis) {
        _chasis = chasis;
    }

    const std::string &getMarca() const {
        return _marca;
    }

    void setMarca(const std::string &marca) {
        _marca = marca;
    }

    const std::string &getColor() const {
        return _color;
    }

    void setColor(const std::string &color) {
        _color = color;
    }

    int getAnio() const {
        return _anio;
    }

    void setAnio(int anio) {
        _anio = anio;
    }

    std::string csv() override {
        return std::to_string(getId()) + "," + _placa + "," + _chasis + "," + _marca + "," + _color + "," + std::to_string(_anio);
    }

    void imprimir(std::ostream& os) override {
        os << "Placa: " << _placa << std::endl
           << "Chasis: " << _chasis << std::endl
           << "Marca: " << _marca << std::endl
           << "Color: " << _color << std::endl
           << "Año: " << _anio << std::endl;
    }

private:
    std::string _placa;
    std::string _chasis;
    std::string _marca;
    std::string _color;
    int _anio;
};

