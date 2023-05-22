#pragma once

class Matrices {
private:
    int** mat1;
    int** mat2;
    int** matR;

public:
    Matrices();
    ~Matrices();
    void sumaRecursivaMatrices(int f, int c);
    void imprimirMatriz(int** matriz);
};
