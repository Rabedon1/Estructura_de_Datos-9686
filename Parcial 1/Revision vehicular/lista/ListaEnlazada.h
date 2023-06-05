#pragma once
#include "Nodo.h"
#include <functional>
#include <iostream>

template <typename T>
class ListaEnlazada {
public:
    void agregar(T elemento);
    void agregar(T elemento, int indice);
    void eliminar(int indice);
    void eliminar(std::function<bool(T)> comparador);
    void modificar(int indice, T elemento);
    void modificar(std::function<bool(T)> comparador, T elemento);
    Nodo<T>* buscar(std::function<bool(T)> comparador);
    ListaEnlazada<T> buscarTodos(std::function<bool(T)> comparador);
    T obtener(int indice);
    void recorrer(std::function<void(T)> funcion);
    int total() const;
    bool estaVacia() const;

private:
    Nodo<T>* _cabeza = nullptr;
    int _cantidad = 0;
};

template <typename T>
void ListaEnlazada<T>::agregar(T elemento) {
    agregar(elemento, _cantidad);
}

template <typename T>
void ListaEnlazada<T>::agregar(T elemento, int indice) {
    if (indice < 0 || indice > _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = new Nodo<T>(elemento);

    if (indice == 0) {
        nodo->setSiguiente(_cabeza);
        _cabeza = nodo;
    } else {
        Nodo<T>* anterior = _cabeza;

        for (int i = 0; i < indice - 1; i++) {
            anterior = anterior->getSiguiente();
        }

        nodo->setSiguiente(anterior->getSiguiente());
        anterior->setSiguiente(nodo);
    }

    _cantidad++;
}

template <typename T>
void ListaEnlazada<T>::eliminar(int indice) {
    if (indice < 0 || indice >= _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = _cabeza;

    if (indice == 0) {
        _cabeza = _cabeza->getSiguiente();
    } else {
        Nodo<T>* anterior = _cabeza;

        for (int i = 0; i < indice - 1; i++) {
            anterior = anterior->getSiguiente();
        }

        nodo = anterior->getSiguiente();
        anterior->setSiguiente(nodo->getSiguiente());
    }

    delete nodo;
    _cantidad--;
}

template <typename T>
void ListaEnlazada<T>::eliminar(std::function<bool(T)> comparador) {
    Nodo<T>* nodo = _cabeza;
    Nodo<T>* anterior = nullptr;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            if (anterior == nullptr) {
                _cabeza = nodo->getSiguiente();
                delete nodo;
                nodo = _cabeza;
                anterior = nodo;
            } else if (nodo->getSiguiente() == nullptr) {
                anterior->setSiguiente(nullptr);
                delete nodo;
                nodo = nullptr;
            } else {
                anterior->setSiguiente(nodo->getSiguiente());
                delete nodo;
                nodo = anterior->getSiguiente();
            }

            _cantidad--;
        } else {
            anterior = nodo;
            nodo = nodo->getSiguiente();
        }
    }
}

template <typename T>
void ListaEnlazada<T>::modificar(int indice, T elemento) {
    if (indice < 0 || indice >= _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = _cabeza;

    for (int i = 0; i < indice; i++) {
        nodo = nodo->getSiguiente();
    }

    nodo->setDato(elemento);
}

template <typename T>
void ListaEnlazada<T>::modificar(std::function<bool(T)> comparador, T elemento) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            nodo->setDato(elemento);
        }

        nodo = nodo->getSiguiente();
    }
}

template <typename T>
Nodo<T>* ListaEnlazada<T>::buscar(std::function<bool(T)> comparador) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            return nodo;
        }

        nodo = nodo->getSiguiente();
    }

    return nullptr;
}

template <typename T>
T ListaEnlazada<T>::obtener(int indice) {
    if (indice < 0 || indice >= _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = _cabeza;

    for (int i = 0; i < indice; i++) {
        nodo = nodo->getSiguiente();
    }

    return nodo->getDato();
}

template <typename T>
void ListaEnlazada<T>::recorrer(std::function<void(T)> funcion) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        funcion(nodo->getDato());
        nodo = nodo->getSiguiente();
    }
}

template<typename T>
int ListaEnlazada<T>::total() const {
    return _cantidad;
}

template<typename T>
bool ListaEnlazada<T>::estaVacia() const {
    return _cantidad == 0;
}

template<typename T>
ListaEnlazada<T> ListaEnlazada<T>::buscarTodos(std::function<bool(T)> comparador) {
    ListaEnlazada<T> lista;
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            lista.agregar(nodo->getDato());
        }

        nodo = nodo->getSiguiente();
    }

    return lista;
}
