#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3
/*
Suma de matrices recursiva
*/

using namespace std;

void sumaRecursivaMatrices(int**, int**, int**, int, int);
void sumaRecursivaMatrices(int** mat1, int** mat2, int** matR, int f, int c) {
	if ((f >= 0) && (c >= 0)) {
		*(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
		sumaRecursivaMatrices(mat1, mat2, matR, f-1, c);
		sumaRecursivaMatrices(mat1, mat2, matR, f, c-1);
	}
}

int main(int argc, char** argv) {
	int** mat1 = nullptr;
	int** mat2 = nullptr;
	int** matR = nullptr;

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

	cout << "\nLa matriz 1 es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(mat1 + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\nLa matriz 2 es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(mat2 + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}

	cout << "Suma de Matrices es: ";
	sumaRecursivaMatrices(mat1, mat2, matR, 2, 2);
	//cout<<"Suma de Matrices es: "<< sumaRecursivaMatrices(mat1, mat2, matR, 2, 2);
	cout << "\nLa matriz R es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(matR + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}
	return 0;
}