
#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <string>
#include "ListaCircularDoble.h"
#include <stdlib.h>
using namespace std;

bool esEntero(string);

int main() {
    ListaCircularDoble lista;
    int opcion, dato;
    string linea, i, b, e, m, s;
    bool rep = true;
    bool repite = true;
    bool repetir = true;

    do {
        system("cls");
        cout << "***********Listas Circulares Dobles***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        do {
            cout << "Opcion: ";
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 5 || opcion < 1) {
                    repetir = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);
        opcion = atoi(linea.c_str());
        switch (opcion) {
        case 1:
            do {
                cout << "Ingrese el dato a insertar: ";
                getline(cin, i);

                if (esEntero(i)) {
                    rep = false;
                    dato = atoi(i.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(i.c_str());
            lista.insertar(dato);
            break;
        case 2:
            do {
                cout << "Ingrese el dato a buscar: ";
                getline(cin, b);

                if (esEntero(b)) {
                    rep = false;
                    dato = atoi(b.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(b.c_str());
            if (lista.buscar(dato)) {
                cout << "El valor " << dato << " se encuentra en la lista." << endl;
            }
            else {
                cout << "El valor " << dato << " no se encuentra en la lista." << endl;
            }
            break;
        case 3:
            do {
                cout << "Ingrese el dato a eliminar: ";
                getline(cin, e);

                if (esEntero(e)) {
                    rep = false;
                    dato = atoi(e.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(e.c_str());
            lista.eliminar(dato);
            break;
        case 4:
            lista.mostrar();
            break;
        }
        system("pause");
    } while (opcion != 5);
    return 0;
}

bool esEntero(string linea) {
	int i = 0;
    if (linea[0] == '-') {
		i = 1;
	}
    for (; i < linea.length(); i++) {
        if (linea[i] < '0' || linea[i] > '9') {
			return false;
		}
	}
	return true;
}
