#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

using namespace std;

class Funciones{
private:
    int ** mat1;
	int ** mat2;
	int ** matR;
public:
	void sumaRecursivaMatrices( int **, int **, int **, int, int);
    void multiplicacionRecursivaMatrices(int **mat1, int **mat2, int **matR, int f1, int c1, int c2);
    Funciones();
    ~Funciones();
    void encerar();
    void llenarRandom();
    void imprimirMatrices();
    void resultado();
    int** getMat1();
    int** getMat2();
    int** getMatR();
};


