#include "matrices.h"

int** multiplicarMatrices(int** matriz1, int** matriz2) {
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

void mostrarMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
