	/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Arias Sebastian, Bazurto Christopher, Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 16/05/23 10:01
 * Fecha de modificacion: 18/05/23 19:32
 * Enunciado:
 * Ejemplo de operadores sobrecargados
 * 
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