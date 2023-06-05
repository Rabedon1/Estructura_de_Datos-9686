#pragma once
#include <string>
#include <functional>

static const std::function<void()> ACCION_VACIA = []() {};

class MenuOpcion {
public:
    MenuOpcion(std::string etiqueta, std::function<void()> accion = ACCION_VACIA, bool esperar = true);
    virtual ~MenuOpcion() = default;
    void ejecutar();
    const std::string &getEtiqueta() const;
    void setEtiqueta(const std::string &etiqueta);
    const std::function<void()> &getAccion() const;
    void setAccion(const std::function<void()> &accion);
    bool debeEsperar() const;
    void setEsperar(bool esperar);

private:
    std::string _etiqueta;
    std::function<void()> _accion = ACCION_VACIA;
    bool _esperar = true;
};

class MenuOpcionSalir : public MenuOpcion {
public:
    MenuOpcionSalir(std::string etiqueta = "Salir", std::function<void()> accion = ACCION_VACIA, bool esperar = false)
        : MenuOpcion(etiqueta, accion, esperar) {}
    ~MenuOpcionSalir() override = default;
};
