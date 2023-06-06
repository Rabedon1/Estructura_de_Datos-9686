/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 22/05/23 20:32
 * Fecha de modificacion: 23/05/23 22:30
 * Enunciado: Realice operaciones con sobrecargas.
 * Tema: operadores sobrecargados
 *******************************************************************************/ 
#ifndef OPERACION_H
#define OPERACION_H
#include "Operador.h"

class Operacion: public Operador
{
	public:
		Operacion();
		Operacion(float, float);
		~Operacion();
		void setA(float);
		float getA(void);
		void setB(float);
		float getB(void);
		float operator +(const Operacion&) const override;
		friend std::ostream& operator<<(std::ostream&, const Operacion&);	
		bool operator>=(const Operacion&) const override;
		bool operator ==(const Operacion&)const override;
		
	private:
		float a;
		float b;
};

#endif