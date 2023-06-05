#pragma once
#include "Nodo.h"
#include <functional>

template <typename T>
class ListaEnlazadaDoble {
public:
    void agregar(T elemento, int indice);
    void agregar(T elemento);
    void eliminar(int indice);
    void eliminar(std::function<bool(T)> comparador);
    void modificar(int indice, T elemento);
    void modificar(std::function<bool(T)> comparador, T elemento);
    Nodo<T>* buscar(std::function<bool(T)> comparador);
    T obtener(int indice);
    void recorrer(std::function<void(T)> funcion);
    int total() const;
    bool estaVacia() const;

private:
    Nodo<T>* _cabeza = nullptr;
    int _cantidad = 0;
};

template <typename T>
void ListaEnlazadaDoble<T>::agregar(T elemento, int indice) {
    if (indice < 0 || indice > _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = new Nodo<T>(elemento);

    if (_cantidad == 0) {
        _cabeza = nodo;
    } else if (indice == 0) {
        nodo->setSiguiente(_cabeza);
        _cabeza->setAnterior(nodo);
        _cabeza = nodo;
    } else {
        Nodo<T>* anterior = _cabeza;

        for (int i = 0; i < indice - 1; i++) {
            anterior = anterior->getSiguiente();
        }

        nodo->setSiguiente(anterior->getSiguiente());
        nodo->setAnterior(anterior);
        anterior->setSiguiente(nodo);

        if (nodo->getSiguiente() != nullptr) {
            nodo->getSiguiente()->setAnterior(nodo);
        }
    }

    _cantidad++;
}

template <typename T>
void ListaEnlazadaDoble<T>::agregar(T elemento) {
    agregar(elemento, _cantidad);
}

template <typename T>
void ListaEnlazadaDoble<T>::eliminar(int indice) {
    if (indice < 0 || indice >= _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = _cabeza;

    if (indice == 0) {
        _cabeza = _cabeza->getSiguiente();
        _cabeza->setAnterior(nullptr);
    } else {
        Nodo<T>* anterior = _cabeza;

        for (int i = 0; i < indice - 1; i++) {
            anterior = anterior->getSiguiente();
        }

        nodo = anterior->getSiguiente();
        anterior->setSiguiente(nodo->getSiguiente());

        if (nodo->getSiguiente() != nullptr) {
            nodo->getSiguiente()->setAnterior(anterior);
        }
    }

    delete nodo;
    _cantidad--;
}

template <typename T>
void ListaEnlazadaDoble<T>::eliminar(std::function<bool(T)> comparador) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            Nodo<T>* anterior = nodo->getAnterior();
            Nodo<T>* siguiente = nodo->getSiguiente();

            if (anterior == nullptr) {
                _cabeza = siguiente;
                delete nodo;
                nodo = siguiente;
            } else if (siguiente == nullptr) {
                anterior->setSiguiente(nullptr);
                delete nodo;
                nodo = nullptr;
            } else {
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
                delete nodo;
                nodo = siguiente;
            }

            _cantidad--;
        } else {
            nodo = nodo->getSiguiente();
        }
    }
}

template <typename T>
void ListaEnlazadaDoble<T>::modificar(int indice, T elemento) {
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
void ListaEnlazadaDoble<T>::modificar(std::function<bool(T)> comparador, T elemento) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        if (comparador(nodo->getDato())) {
            nodo->setDato(elemento);
        }

        nodo = nodo->getSiguiente();
    }
}

template <typename T>
void ListaEnlazadaDoble<T>::recorrer(std::function<void(T)> funcion) {
    Nodo<T>* nodo = _cabeza;

    while (nodo != nullptr) {
        funcion(nodo->getDato());
        nodo = nodo->getSiguiente();
    }
}

template <typename T>
Nodo<T>* ListaEnlazadaDoble<T>::buscar(std::function<bool(T)> comparador) {
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
T ListaEnlazadaDoble<T>::obtener(int indice) {
    if (indice < 0 || indice >= _cantidad) {
        throw "Indice fuera de rango";
    }

    Nodo<T>* nodo = _cabeza;

    for (int i = 0; i < indice; i++) {
        nodo = nodo->getSiguiente();
    }

    return nodo->getDato();
}

template<typename T>
int ListaEnlazadaDoble<T>::total() const {
    return _cantidad;
}

template<typename T>
bool ListaEnlazadaDoble<T>::estaVacia() const {
    return _cantidad == 0;
}
