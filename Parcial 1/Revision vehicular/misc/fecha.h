#pragma once
#include "date/date.h"
#include <string>

class Fecha {
public:
	enum class Field { Anio, Mes, Dia };
	
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	int dia();
	int mes();
	int anio();

	bool antes_de(Fecha fecha);
	std::string formatear(std::string formato);

	int diferencia(Field campo, Fecha objetivo = Fecha());

	static bool es_valida(Fecha fecha);
	static Fecha ingresar(std::string label = std::string());
    static Fecha parse(std::string fecha);

private:
	unsigned int dia_;
	unsigned int mes_;
	unsigned int anio_;
};
