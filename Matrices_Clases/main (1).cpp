#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3
/*
Suma de matrices recursiva
*/

using namespace std;

int sumaRecursivaMatrices(int[MAX][MAX], int[MAX][MAX], int, int);
//int sumaRecursivaMatrices(int**, int**, int, int);

int sumaRecursivaMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int f, int c){
	if((f==0)&&(c==0))
		return mat1[f][c]+mat2[f][c];
	else{
		if(f>-1){
			c--;
			if(c>=-1)
				return mat1[f][c+1]+mat2[f][c+1]+sumaRecursivaMatrices(mat1, mat2, f, c);
			else
				return sumaRecursivaMatrices(mat1, mat2, f-1, 2);
		}
	}
	//return;
}

int main(int argc, char** argv) {
	int mat1[MAX][MAX], mat2[MAX][MAX];
	srand(time(NULL));
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			mat1[i][j]=(int)((rand()/32768.1)*1000);
			mat2[i][j]=(int)((rand()/32768.1)*1000);
		}
	}
	
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			cout<<mat1[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			cout<<mat2[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Suma de Matrices es: "<< sumaRecursivaMatrices(mat1, mat2, 2, 2);
	return 0;
}
