#include "sumaMatricesRecursivas.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Matrices::Matrices() {
    mat1 = nullptr;
    mat2 = nullptr;
    matR = nullptr;

    mat1 = (int**)malloc(3 * sizeof(int*));
    mat2 = (int**)malloc(3 * sizeof(int*));
    matR = (int**)malloc(3 * sizeof(int*));
    for (int j = 0; j < 3; j++) {
        *(mat1 + j) = (int*)malloc(3 * sizeof(int*));
        *(mat2 + j) = (int*)malloc(3 * sizeof(int*));
        *(matR + j) = (int*)malloc(3 * sizeof(int*));
    }

    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(mat1 + i) + j) = (int)((rand() / 32768.1) * 1000);
            *(*(mat2 + i) + j) = (int)((rand() / 32768.1) * 1000);
            *(*(matR + i) + j) = 0;
        }
    }
}

Matrices::~Matrices() {
    for (int j = 0; j < 3; j++) {
        free(*(mat1 + j));
        free(*(mat2 + j));
        free(*(matR + j));
    }
    free(mat1);
    free(mat2);
    free(matR);
}

void Matrices::sumaRecursivaMatrices(int f, int c) {
    if ((f >= 0) && (c >= 0)) {
        *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
        sumaRecursivaMatrices(f - 1, c);
        sumaRecursivaMatrices(f, c - 1);
    }
}

void Matrices::imprimirMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", *(*(matriz + i) + j));
            printf("%*s", j + 5, "");
        }
        cout << "\n";
    }
}
