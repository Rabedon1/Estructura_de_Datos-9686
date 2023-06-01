#include "template.hpp"

// Definición
template <typename T>
void Calculadora<T>::operaciones() {
    std::cout << "Numeros: " << num1 << " y " << num2 << std::endl;
    std::cout << num1 << " + " << num2 << " = " << suma() << std::endl;
    std::cout << num1 << " - " << num2 << " = " << resta() << std::endl;
    std::cout << num1 << " * " << num2 << " = " << producto() << std::endl;
    std::cout << num1 << " / " << num2 << " = " << division() << std::endl;
}

template <typename T>
T Calculadora<T>::suma() { return num1 + num2; }

template <typename T>
T Calculadora<T>::resta() { return num1 - num2; }

template <typename T>
T Calculadora<T>::producto() { return num1 * num2; }

template <typename T>
T Calculadora<T>::division() { return num1 / num2; }
