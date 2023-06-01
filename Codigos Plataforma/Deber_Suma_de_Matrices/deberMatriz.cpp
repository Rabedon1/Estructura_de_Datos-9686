#include "deberMatriz.h"
#include <stdexcept>
#include <cstdlib>


/*************************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  deberMatriz.cpp
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: 21 de mayo de 2023 10:30:36
 * Enunciado: Realizar la suma de matrices con memoria dinamica, donde resuelva la siguiente operacion matematica, 
 *************************************************************************************************/

template <typename T>
Matrix<T>::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    data = (T**)malloc(rows * sizeof(T*));
    for (int i = 0; i < rows; i++) {
        data[i] = (T*)malloc(cols * sizeof(T));
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);
}

template <typename T>
int Matrix<T>::getRows() const {
    return rows;
}

template <typename T>
int Matrix<T>::getCols() const {
    return cols;
}

template <typename T>
void Matrix<T>::setData(int row, int col, T value) {
    data[row][col] = value;
}

template <typename T>
T Matrix<T>::getData(int row, int col) const {
    return data[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::sum(const Matrix<T>& other) const {
    if (rows != other.getRows() || cols != other.getCols()) {
        throw std::runtime_error("No se pueden sumar matrices de diferentes dimensiones.");
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.setData(i, j, data[i][j] + other.getData(i, j));
        }
    }

    return result;
}
