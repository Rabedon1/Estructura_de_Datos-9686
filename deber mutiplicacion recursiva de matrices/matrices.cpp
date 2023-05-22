#include <iostream>

// Función para multiplicar dos matrices de 3x3
int** multiplicarMatrices(int** matriz1, int** matriz2) {
    // Crear una nueva matriz para almacenar el resultado
    int** resultado = new int*[3];
    for (int i = 0; i < 3; i++) {
        resultado[i] = new int[3];
    }

    // Calcular el producto de las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

// Función para mostrar una matriz
void mostrarMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Crear matrices
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