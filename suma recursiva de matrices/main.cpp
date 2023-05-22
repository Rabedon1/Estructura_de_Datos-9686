#include <iostream>
#include "Suma.cpp"
using namespace std;

int main(int argc, char** argv) {
    Matrices matrices;

    cout << "La matriz 1 es:\n";
    matrices.imprimirMatriz(matriz.12 );
    cout << "\n";

    cout << "La matriz 2 es:\n";
    matrices.imprimirMatriz(matrices.mat2);

    cout << "Suma de Matrices es: ";
    matrices.sumaRecursivaMatrices(2, 2);
    cout << "\nLa matriz R es:\n";
    matrices.imprimirMatriz();
	cout << "\nLa matriz R es:\n";
    matrices.imprimirMatriz(matrices.matR);

    return 0;
}