#ifndef MATRIX_H
#define MATRIX_H

/*************************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  deberMatriz.h
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: 21 de mayo de 2023 10:30:36
 * Enunciado: Realizar la suma de matrices con memoria dinamica, donde resuelva la siguiente operacion matematica, 
 *************************************************************************************************/

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);
    ~Matrix();

    int getRows() const;
    int getCols() const;

    void setData(int row, int col, T value);
    T getData(int row, int col) const;

    Matrix<T> sum(const Matrix<T>& other) const;
};

#endif
