#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
private:
    std::string modelo;
    std::string color;
    std::string motor;
    std::string marca;
    std::string fechaMatriculacion;
    std::string placa;

public:
    Auto(const std::string& modelo, const std::string& color, const std::string& motor, const std::string& marca,
         const std::string& fechaMatriculacion, const std::string& placa);
    std::string getModelo() const;
    std::string getColor() const;
    std::string getMotor() const;
    std::string getMarca() const;
    std::string getFechaMatriculacion() const;
    std::string getPlaca() const;
};

#endif  // AUTO_H
