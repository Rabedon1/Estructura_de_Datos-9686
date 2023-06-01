#pragma once
#include <iostream>
class Matriz{
	private:
		int **matriz;
		int dim;
	public:
		Matriz();
		Matriz(int** ,int);
		int getDim();
		void setDim(int);
		int **getMatriz();
		void setMatriz(int **);
};