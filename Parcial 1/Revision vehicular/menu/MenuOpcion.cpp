#include "MenuOpcion.h"

MenuOpcion::MenuOpcion(std::string etiqueta, std::function<void()> accion, bool esperar) {
    _etiqueta = etiqueta;
    _accion = accion;
    _esperar = esperar;
}

const std::string &MenuOpcion::getEtiqueta() const {
    return _etiqueta;
}

void MenuOpcion::setEtiqueta(const std::string &etiqueta) {
    _etiqueta = etiqueta;
}

const std::function<void()> &MenuOpcion::getAccion() const {
    return _accion;
}

void MenuOpcion::setAccion(const std::function<void()> &accion) {
    _accion = accion;
}

bool MenuOpcion::debeEsperar() const {
    return _esperar;
}

void MenuOpcion::setEsperar(bool esperar) {
    _esperar = esperar;
}

void MenuOpcion::ejecutar() {
    if (_accion) {
        _accion();
    }
}
