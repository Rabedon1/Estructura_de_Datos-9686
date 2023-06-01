/*************************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  main.cpp
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: 21 de mayo de 2023 10:30:36
 * Enunciado: Realizar la suma de matrices con memoria dinamica, donde resuelva la siguiente operacion matematica, 
 *************************************************************************************************/

#include <iostream>
#include "deberMatriz.cpp"

int main() {
    int rows = 2;
    int cols = 2;

    Matrix<int>* matrix1 = new Matrix<int>(rows, cols);
    Matrix<int>* matrix2 = new Matrix<int>(rows, cols);
    Matrix<int>* result = new Matrix<int>(rows, cols);

    // Llenar la primera matriz
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1->setData(i, j, value++);
        }
    }

    // Llenar la segunda matriz
    value = 10;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2->setData(i, j, value++);
        }
    }

    // Sumar las matrices
    *result = matrix1->sum(*matrix2);

    // Imprimir las matrices y el resultado
    std::cout << "Matriz 1:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix1->getData(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matriz 2:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix2->getData(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Resultado de la suma es :" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << result->getData(i, j) << " ";
        }
        std::cout << std::endl;
    }

    delete matrix1;
    delete matrix2;
    delete result;

    return 0;
}
