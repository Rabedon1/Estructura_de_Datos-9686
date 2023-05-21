#pragma once
#include "Matriz.h"
class Operaciones{
	public:
		Operaciones();
		Operaciones(Matriz);
		void segmentar();
		void encerar();
		void generar();
		void procesarPot(int);
		void procesarMulti();
		void imprimir();
	private:
		Matriz _matriz;
};