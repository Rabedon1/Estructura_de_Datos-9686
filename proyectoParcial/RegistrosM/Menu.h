#ifndef MENU_H
#define MENU_H

#include "RegistroVehicular.h"

class Menu {
private:
    RegistroVehicular registro;

public:
    Menu();
    void mostrarMenu();
    void agregarRegistro();
    void mostrarRegistros();
    bool validarPlaca(const std::string& placa) const;
};

#endif  // MENU_H
