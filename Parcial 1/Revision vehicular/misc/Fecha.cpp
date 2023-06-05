#include "fecha.h"
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <regex>
#include <iostream>
#include <cstring>

Fecha::Fecha() {
	auto now = std::chrono::system_clock::now();
	date::year_month_day ymd = date::year_month_day{ date::floor<date::days>(now) };

	dia_ = (unsigned int)ymd.day();
	mes_ = (unsigned int)ymd.month();
	anio_ = (int)ymd.year();
}

Fecha::Fecha(int dia, int mes, int anio) {
	dia_ = dia;
	mes_ = mes;
	anio_ = anio;
}

bool Fecha::es_valida(Fecha fecha) {
	using namespace std::literals;
	std::tm tm;

	if (fecha.dia() < 0 || fecha.dia() > 31
		|| fecha.mes() < 1 || fecha.mes() > 12) {
		return false;
	}

	memset(&tm, 0, sizeof(tm));

	tm.tm_mday = fecha.dia();
	tm.tm_mon = fecha.mes() - 1;
	tm.tm_year = fecha.anio() - 1900;
	time_t tt = mktime(&tm);

	if (tt == (time_t)-1) {
		return false;
	}

	std::chrono::time_point tp = std::chrono::system_clock::from_time_t(tt);
	date::year_month_day ymd = date::year{ fecha.anio() } / fecha.mes() / fecha.dia();

    return ymd.ok();
}

Fecha Fecha::ingresar(std::string label) {
	Fecha fecha;
	std::string input;

	std::regex pattern("^(0[1-9]|[12][0-9]|3[01])[- \\/.](0[1-9]|1[012])[- \\/.]((19|20)\\d\\d)$");
	std::smatch matches;
	
	do {
		std::cout << (label.empty() ? "Ingrese una fecha" : label) + " (dd/mm/yyyy): ";
		std::cin >> input;

		if (!std::regex_match(input, matches, pattern)) {
			std::cout << std::endl
					  << "[fecha invalida 1]"
					  << std::endl;
			continue;
		}

		int dia = std::stoi(matches[1]);
		int mes = std::stoi(matches[2]);
		int anio = std::stoi(matches[3]);

		fecha = Fecha(dia, mes, anio);

		if (!Fecha::es_valida(fecha)) {
			std::cout << std::endl
					  << "[fecha invalida 2]" 
					  << std::endl;
			continue;
		}

		break;
	} while (true);

    return fecha;
}

int Fecha::dia() {
	return dia_;
}

int Fecha::mes() {
	return mes_;
}

int Fecha::anio() {
	return anio_;
}

bool Fecha::antes_de(Fecha fecha) {
	date::year_month_day actual = date::year{ anio() } / mes() / dia();
	date::year_month_day ymd = date::year{ fecha.anio() } / fecha.mes() / fecha.dia();

	auto diferencia = date::sys_days{ ymd } - date::sys_days{ actual };
	int dias = diferencia.count();

	return dias < 0;
}

std::string Fecha::formatear(std::string formato) {
	date::year_month_day ymd = date::year{ anio() } / mes() / dia();
	return date::format(formato, ymd);
}

int Fecha::diferencia(Field campo, Fecha objetivo) {
	auto ymd = date::year{ anio() } / mes() / dia();
	auto ymd2 = date::year{ objetivo.anio() } / objetivo.mes() / objetivo.dia();
	auto sys_days = date::sys_days{ ymd2 };
	auto sys_days2 = date::sys_days{ ymd };

	auto major = (sys_days > sys_days2 ? sys_days : sys_days2);
	auto minor = (sys_days < sys_days2 ? sys_days : sys_days2);

	auto anios = date::floor<date::years>(major - minor);
	auto meses = date::floor<date::months>(major - minor);
	auto dias = date::floor<date::days>(major - minor);

	if (campo == Field::Anio) {
		return anios.count();
	} else if (campo == Field::Mes) {
		return meses.count();
	} else if (campo == Field::Dia) {
		return dias.count();
	}

	return -1;
}

Fecha Fecha::parse(std::string fecha) {
    std::regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])[- \/.](0[1-9]|1[012])[- \/.]((19|20)\d\d)$)");
    std::smatch matches;

    if (!std::regex_match(fecha, matches, pattern)) {
        return Fecha();
    }

    int dia = std::stoi(matches[1]);
    int mes = std::stoi(matches[2]);
    int anio = std::stoi(matches[3]);

    return Fecha(dia, mes, anio);
}