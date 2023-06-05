#pragma once
#include "date/date.h"
#include <string>
#include <regex>
#include <iostream>

class Hora {
public:
    Hora() = default;

    Hora(int hora, int minuto) {
        this->_hora = hora;
        this->_minuto = minuto;

        if (!esValida()) {
            this->_hora = 0;
            this->_minuto = 0;
        }
    }

    int getHora() {
        return _hora;
    }

    int getMinuto() {
        return _minuto;
    }

    std::string str() {
        return std::to_string(_hora) + ":" + (_minuto == 0 ? "00" : std::to_string(_minuto));
    }

    static Hora parse(std::string hora) {
        std::regex re("([0-9]{1,2}):([0-9]{1,2})");
        std::smatch match;

        if (std::regex_search(hora, match, re)) {
            return Hora(std::stoi(match[1]), std::stoi(match[2]));
        }

        return Hora();
    }

    static Hora actual() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::tm* time = std::localtime(&in_time_t);
        return Hora(time->tm_hour, time->tm_min);
    }

    static Hora ingresar(std::string mensaje) {
        std::string hora;
        std::regex regex_hora("([0-1][0-9]|2[0-3]):[0-5][0-9]");

        do {
            std::cout << mensaje;
            std::cin >> hora;
        } while (!std::regex_match(hora, regex_hora));

        return Hora(std::stoi(hora.substr(0, 2)), std::stoi(hora.substr(3, 2)));
    }

private:
    int _hora = 0;
    int _minuto = 0;

    bool esValida() {
        return _hora >= 0 && _hora <= 23 && _minuto >= 0 && _minuto <= 59;
    }
};
