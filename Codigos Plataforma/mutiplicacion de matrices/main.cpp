#include <iostream>
#include "matrices.cpp"

int main() {
    int** matriz1 = new int*[3];
    int** matriz2 = new int*[3];

    // Asignar memoria para las matrices
    for (int i = 0; i < 3; i++) {
        matriz1[i] = new int[3];
        matriz2[i] = new int[3];
    }

    // Solicitar al usuario los valores de la primera matriz
    std::cout << "Ingrese los valores de la primera matriz 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz1[i][j];
        }
    }

    // Solicitar al usuario los valores de la segunda matriz
    std::cout << "Ingrese los valores de la segunda matriz 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz2[i][j];
        }
    }

    // Multiplicar las matrices
    int** resultado = multiplicarMatrices(matriz1, matriz2);

    // Mostrar el resultado
    std::cout << "El resultado de la multiplicacion de las matrices es:" << std::endl;
    mostrarMatriz(resultado);

    // Liberar memoria de las matrices y el resultado
    for (int i = 0; i < 3; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] resultado[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;

    return 0;
}
