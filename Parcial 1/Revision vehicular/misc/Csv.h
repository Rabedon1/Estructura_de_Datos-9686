#ifndef APPREVISIONVEHICULAR_CSV_H
#define APPREVISIONVEHICULAR_CSV_H

#include <sstream>
#include <fstream>
#include <iostream>
#include "lista/ListaEnlazada.h"

class ColumnaCsv {
public:
    ColumnaCsv() = default;
    ColumnaCsv(std::string contenido, int indice) {
        _contenido = contenido;
        _indice = indice;
    }

    std::string getContenido() const { return _contenido; }
    int getIndice() const { return _indice; }

private:
    std::string _contenido;
    int _indice;
};

#endif //APPREVISIONVEHICULAR_CSV_H
