#pragma once
#include "MenuOpcion.h"
#include <string>
#include <functional>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/color.hpp>

class Menu {
public:
    explicit Menu(std::string titulo);
    Menu& opcion(std::string etiqueta, std::function<void()> accion = ACCION_VACIA, bool esperar = true);
    Menu& opcionSalir(std::string etiqueta = "Salir", bool esperar = false);
    void iniciar();
    void salir();

private:
    std::string _titulo;
    std::vector<MenuOpcion*> _opciones;
    bool _ejecutandose = false;
};
