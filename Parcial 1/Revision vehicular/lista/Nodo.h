#pragma once

template <typename T>
class Nodo {
public:
    Nodo(T dato);

    T getDato();
    void setDato(T dato);

    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T>* siguiente);

    Nodo<T>* getAnterior();
    void setAnterior(Nodo<T>* anterior);

private:
    T _dato;
    Nodo<T>* _siguiente = nullptr;
    Nodo<T>* _anterior = nullptr;
};

template <typename T>
Nodo<T>::Nodo(T dato) {
    _dato = dato;
}

template <typename T>
T Nodo<T>::getDato() {
    return _dato;
}

template <typename T>
void Nodo<T>::setDato(T dato) {
    _dato = dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return _siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    _siguiente = siguiente;
}

template <typename T>
Nodo<T>* Nodo<T>::getAnterior() {
    return _anterior;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo<T>* anterior) {
    _anterior = anterior;
}
