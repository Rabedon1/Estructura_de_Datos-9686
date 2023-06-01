#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>

// Declaración
template <typename T>
class Calculadora {
	private:
		T num1, num2;
	public:
		Calculadora(T n1, T n2) : num1(n1), num2(n2){};
		void operaciones();
		T suma();
		T resta();
		T producto();
		T division();
};

#endif