#include "fraccion_template.h"


template <typename T>
void Operacion<T>::Operacion() {
    std::cout << "Numeros: " << num1 << "/" << den1<< " y " << num2 << "/" << den2 << std::endl;
    
}

template <typename T>
T Operacion<T>::numCalculo() { return ((num1 * den2)+(num2 * den1)); }

template <typename T>
T Calculadora<T>::denCalculo() { return den1 + den2; }




