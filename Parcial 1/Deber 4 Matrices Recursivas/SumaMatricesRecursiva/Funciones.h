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
	void multiplicacionRecursivaMatrizA(int **, int **, int **, int);
	void multiplicacionRecursivaMatrizB(int** ,int** ,int** , int , int );
	void multiplicacionRecursiva(int** ,int** ,int** ,int ,int ,int );
	Funciones();
    ~Funciones();
    void encerar();
  
    void llenarRandom();
    void imprimirMatrices();
    void resultado();

    int** getMat1(); 
    int** getMatR();
    int** getMat2();
};                  

