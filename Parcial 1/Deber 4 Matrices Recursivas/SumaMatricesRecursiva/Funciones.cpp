#include <iostream>
#include "Funciones.h"

Funciones::Funciones(){
	mat1 = nullptr;
	mat2 = nullptr;
	matR = nullptr;
	mat1=(int **)malloc (MAX*sizeof(int*));
	mat2=(int **)malloc (MAX*sizeof(int*));
	matR=(int **)malloc (MAX*sizeof(int*));
}

void Funciones::encerar(){
	for(int j=0;j<3;j++){
		*(mat1+j)=(int*)malloc(3*sizeof(int*));
		*(mat2+j)=(int*)malloc(3*sizeof(int*));
		*(matR+j)=(int*)malloc(3*sizeof(int*));
	}
}

void Funciones::llenarRandom(){
	srand (time(NULL));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*(*(mat1+i)+j)=(int)((rand()/32768.1)*1000);
			*(*(mat2+i)+j)=(int)((rand()/32768.1)*1000);
			*(*(matR+i)+j)=0;
		}
	}
}

void Funciones::imprimirMatrices(){
	cout<<"\n La matriz 1 es :\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(mat1+i)+j));
			printf("%*s",j+5,"");
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"\n La matriz 2 es :\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(mat2+i)+j));
			printf("%*s",j+5,"");
		}
		cout<<"\n";
	}
}

void Funciones::resultado(){
	cout<<"\n";
	cout<<"\n La matriz R es :\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(matR+i)+j));
			printf("%*s",j+5,"");
		}
		cout<<"\n";
	}
}


Funciones::~Funciones(){
	
}

void Funciones::sumaRecursivaMatrices ( int **mat1, int **mat2, int **matR, int f, int c){
	if ((f>=0) && (c>=0)){
		*(*(matR+f)+c)=*(*(mat1+f)+c) + *(*(mat2 +f)+c);
		sumaRecursivaMatrices( mat1,mat2,matR,f-1,c);
		sumaRecursivaMatrices( mat1,mat2,matR,f,c-1);
	}
}
void Funciones::multiplicacionRecursivaMatrizA(int **mat1, int **mat2, int **matR, int f){
    if (f<3)
       {
           multiplicacionRecursivaMatrizB(mat1,mat2,matR,f,0);
           multiplicacionRecursivaMatrizA(mat1,mat2,matR,f+1);
       }
}
void Funciones::multiplicacionRecursivaMatrizB(int** mat1,int** mat2,int** matR, int i, int j){
 	if(j<3){
 			multiplicacionRecursiva(mat1,mat2,matR,i,j,0);
           	multiplicacionRecursivaMatrizB(mat1,mat2,matR,i,j+1);
	 }
 }

void Funciones::multiplicacionRecursiva(int** mat1,int** mat2,int** matR,int i,int j,int k){
	if(k<3){
	(*(*(matR+i)+j)) +=(*(*(mat1+i)+k)) * (*(*(mat2+k)+j)); //	C[i][j]+=A[i][k]*B[k][j];	
	multiplicacionRecursiva(mat1,mat2,matR,i,j,k+1);
	}
}

//GETTERS
int** Funciones::getMat1(){
	return mat1;
}

int** Funciones::getMat2(){
	return mat2;
}

int** Funciones::getMatR(){
	return matR;
}

