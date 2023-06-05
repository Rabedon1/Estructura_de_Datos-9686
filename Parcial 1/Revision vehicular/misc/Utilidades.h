#pragma once

#include "lista/ListaEnlazada.h"
#include "Csv.h"
#include "modelo/Modelo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <regex>
#include "Windows.h"

namespace utilidades {
    ListaEnlazada<ListaEnlazada<ColumnaCsv>> leerCsv(std::string archivo);
    ListaEnlazada<std::string> leerLineasCsv(std::string archivo);
    void escribirCsv(std::string archivo, ListaEnlazada<std::string> lineas);

    template <typename T, typename = typename std::enable_if<std::is_base_of<Modelo, T>::value, T>::type>
    ListaEnlazada<T> leerCsvModelo(std::string archivo, std::function<T(ListaEnlazada<ColumnaCsv>)> transformador);

    template <typename T,typename = typename std::enable_if<std::is_base_of<Modelo, T>::value, T>::type>
    void escribirCsv(std::string archivo, ListaEnlazada<T> datos);

    template <typename T,typename = typename std::enable_if<std::is_base_of<Modelo, T>::value, T>::type>
    int obtenerUltimoId(ListaEnlazada<T> datos);

    int leerEntero(std::string mensaje, int minimo = INT_MIN, int maximo = INT_MAX);
    std::string leerCadena(std::string mensaje, std::string patron = "");
    std::string recortarEspaciosCostados(std::string cadena);
    std::string minusculas(std::string cadena);
    bool cadenasIguales(std::string cadena1, std::string cadena2);
    bool confirmar(std::string mensaje);
    std::string leerTelefono(std::string mensaje);
    bool cedula_valida(const std::string cedula);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline ListaEnlazada<std::string> leerLineasCsv(std::string archivo) {
        std::ifstream archivoCsv(archivo);
        std::string linea;
        ListaEnlazada<std::string> lineas;

        while (std::getline(archivoCsv, linea)) {
            lineas.agregar(linea);
        }

        return lineas;
    }

    inline ListaEnlazada<ListaEnlazada<ColumnaCsv>> leerCsv(std::string archivo) {
        std::ifstream archivoCsv(archivo);
        ListaEnlazada<ListaEnlazada<ColumnaCsv>> datos;

        if (archivoCsv.is_open()) {
            std::string linea;

            while (std::getline(archivoCsv, linea)) {
                ListaEnlazada<ColumnaCsv> fila;
                std::string valor;
                std::stringstream ss(linea);
                int indice = 0;

                if (linea.empty()) {
                    continue;
                }

                while (std::getline(ss, valor, ',')) {
                    auto columna = ColumnaCsv(valor, indice++);
                    fila.agregar(columna);
                }

                datos.agregar(fila);
            }
        }

        return datos;
    }

    template <typename T, typename>
    inline ListaEnlazada<T> leerCsvModelo(std::string archivo, std::function<T(ListaEnlazada<ColumnaCsv>)> transformador) {
        ListaEnlazada<T> lista;
        ListaEnlazada<ListaEnlazada<ColumnaCsv>> lineas = leerCsv(archivo);

        lineas.recorrer([&] (ListaEnlazada<ColumnaCsv> columnas) {
            lista.agregar(transformador(columnas));
        });

        return lista;
    }

    inline void escribirCsv(std::string archivo, ListaEnlazada<std::string> lineas) {
        std::ofstream archivoCsv(archivo, std::ios::out | std::ios::trunc);

        if (archivoCsv.is_open()) {
            lineas.recorrer([&] (std::string linea) {
                archivoCsv << linea << std::endl;
            });
        }

        archivoCsv.close();
    }

    template <typename T, typename>
    inline void escribirCsv(std::string archivo, ListaEnlazada<T> datos) {
        ListaEnlazada<std::string> lineas;

        datos.recorrer([&] (T modelo) {
            lineas.agregar(modelo.csv());
        });

        escribirCsv(archivo, lineas);
    }

    inline int leerEntero(std::string mensaje, int minimo, int maximo) {
        int valor;

        while (true) {
            std::cout << mensaje;
            std::cin >> valor;

            bool failed = std::cin.fail();

            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

            if (failed) {
                std::cout << "\nEl valor ingresado no es un número entero." << std::endl;
                continue;
            }

            if (valor < minimo || valor > maximo) {
                std::cout << "\nEl valor ingresado no está dentro del rango permitido." << std::endl;
                continue;
            }

            break;
        }

        return valor;
    }

    inline std::string leerCadena(std::string mensaje, std::string patron) {
        std::string valor;

        while (true) {
            std::cout << mensaje;
            std::getline(std::cin, valor);
            valor = recortarEspaciosCostados(valor);

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                continue;
            }

            if (!patron.empty() && !std::regex_match(valor, std::regex(patron))) {
                std::cout << "\nEl valor ingresado tiene un formato incorrecto ." << std::endl;
                continue;
            }

            break;
        }

        return valor;
    }

    inline bool cadenasIguales(std::string cadena1, std::string cadena2) {
        // Convierte las cadenas a minúsculas
        std::transform(cadena1.begin(), cadena1.end(), cadena1.begin(), ::tolower);
        std::transform(cadena2.begin(), cadena2.end(), cadena2.begin(), ::tolower);

        // remover espacios en blanco al inicio y al final
        cadena1.erase(0, cadena1.find_first_not_of(' '));
        cadena1.erase(cadena1.find_last_not_of(' ') + 1);

        cadena2.erase(0, cadena2.find_first_not_of(' '));
        cadena2.erase(cadena2.find_last_not_of(' ') + 1);

        return cadena1 == cadena2;
    }

    inline std::string recortarEspaciosCostados(std::string cadena) {
        cadena.erase(0, cadena.find_first_not_of(' '));
        cadena.erase(cadena.find_last_not_of(' ') + 1);
        return cadena;
    }

    inline std::string minusculas(std::string cadena) {
        std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
        return cadena;
    }

    inline bool confirmar(std::string mensaje) {
        std::string respuesta = leerCadena(mensaje + " (s/n): ", "^([sS]|[nN])$");
        return cadenasIguales(minusculas(respuesta), "s");
    }

    inline std::string leerTelefono(std::string mensaje) {
        return leerCadena(mensaje, "^(09[0-9]{8}|(02)?[0-9]{7})$");
    }

    inline bool archivo_existe(std::string ruta) {
        GetFileAttributesA(ruta.c_str());
        return !(INVALID_FILE_ATTRIBUTES == GetFileAttributesA(ruta.c_str()) && GetLastError() == ERROR_FILE_NOT_FOUND);
    }

    template <typename T, typename>
    inline int obtenerUltimoId(ListaEnlazada<T> datos) {
        int ultimoId = 0;

        datos.recorrer([&] (T modelo) {
            if (modelo.getId() > ultimoId) {
                ultimoId = modelo.getId();
            }
        });

        return ultimoId;
    }

    inline bool cedula_valida(const std::string cedula) {
        if (cedula.length() != 10) {
            return false;
        }

        int sum_par = 0;
        int sum_impar = 0;
        int sum;
        int i = 1;

        std::string digits = cedula.substr(0, cedula.size() - 1);

        for (char& c : digits) {
            int digit = c - '0';

            if (i % 2 == 0) {
                sum_par += digit;
            } else {
                if ((digit * 2) > 9) {
                    sum_impar += (digit * 2) - 9;
                } else {
                    sum_impar += (digit * 2);
                }
            }

            i++;
        }

        sum = sum_par + sum_impar;

        int verifier = cedula.at(cedula.size() - 1) - '0';
        int higher = (10 - (sum % 10)) + sum;

        if (sum % 10 == 0) {
            return verifier == 0;
        }

        return (higher - sum) == verifier;
    }
}
