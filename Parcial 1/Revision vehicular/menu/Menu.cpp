#include "Menu.h"

Menu::Menu(std::string titulo) {
    _titulo = titulo;
}

Menu &Menu::opcion(std::string etiqueta, std::function<void()> accion, bool esperar) {
    _opciones.push_back(new MenuOpcion(etiqueta, accion, esperar));
    return *this;
}

Menu &Menu::opcionSalir(std::string etiqueta, bool esperar) {
    _opciones.push_back(new MenuOpcion(etiqueta, [this](){
        salir();
    }, esperar));

    return *this;
}

void Menu::iniciar() {
    auto ventana = ftxui::ScreenInteractive::TerminalOutput();
    ftxui::MenuOption configuracionMenu;
    int seleccionado = 0;

    _ejecutandose = true;

    std::vector<std::string> opciones;

    for (auto opcion : _opciones) {
        opciones.push_back(opcion->getEtiqueta());
    }

    configuracionMenu.on_enter = ventana.ExitLoopClosure();
    auto menu = ftxui::Menu(&opciones, &seleccionado, &configuracionMenu);

    // Display together the menu with a border
    auto renderer = Renderer(menu, [&] {
        return ftxui::vbox({
            hbox(ftxui::text(_titulo)),
            ftxui::separator(),
            menu->Render() | ftxui::frame,
        }) | ftxui::border | ftxui::borderEmpty | ftxui::bgcolor(ftxui::Color::Black);
    });

    do {
        system("cls");
        ventana.ResetPosition(true);
        ventana.SetCursor({0, 0 });
        ventana.Loop(renderer);

        if (seleccionado < 0 || seleccionado >= _opciones.size()) {
            continue;
        }

        auto opcion = _opciones[seleccionado];
        opcion->ejecutar();

        if (opcion->debeEsperar()) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (_ejecutandose);
}

void Menu::salir() {
    _ejecutandose = false;
}
