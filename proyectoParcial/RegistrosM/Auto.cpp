#include "Auto.h"

Auto::Auto(const std::string& modelo, const std::string& color, const std::string& motor, const std::string& marca,
           const std::string& fechaMatriculacion, const std::string& placa)
    : modelo(modelo), color(color), motor(motor), marca(marca), fechaMatriculacion(fechaMatriculacion), placa(placa) {}

std::string Auto::getModelo() const {
    return modelo;
}

std::string Auto::getColor() const {
    return color;
}

std::string Auto::getMotor() const {
    return motor;
}

std::string Auto::getMarca() const {
    return marca;
}

std::string Auto::getFechaMatriculacion() const {
    return fechaMatriculacion;
}

std::string Auto::getPlaca() const {
    return placa;
}
