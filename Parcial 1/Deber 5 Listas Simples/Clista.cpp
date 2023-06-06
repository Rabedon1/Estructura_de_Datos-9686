/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 15/11/2022
	Enunciado: Lista Simple
	Nivel.- 3   NRC: 7999
*/

#pragma once
#include "Clista.h"
#include "Cnodo.cpp"
#include <cstring>
#include <istream>
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

Clista::Clista(){
    this->referencial=NULL;
    this->origen=NULL;
}

void Clista::insertarCab(int _entrada){
    Cnodo *nuevo = new Cnodo(_entrada,NULL);
    if(ListaVacia()){
        this->origen=nuevo;
    }else{
        nuevo->setSiguiente(origen);
        origen=nuevo;
    }
}
void Clista::insertarCol(int _entrada){
    Cnodo *nuevo=new Cnodo(_entrada,NULL);
    if(ListaVacia()){
        this->origen=nuevo;
    }else{
        this->referencial->setSiguiente(nuevo);
    }
    this->referencial=nuevo;
}
void Clista::buscar(int val){
    int aux = 0;
	Cnodo* num = new Cnodo(val, NULL);
	Cnodo* tmp = this->origen;
	if(this->ListaVacia()){
		cout<<"\nLa lista se encuentra vacia por lo que no existe el dato"<<endl;
	}else{
		while (tmp->getSiguiente()){
		if (tmp->getEntrada() == num->getEntrada()){
			cout<<"\nEl dato se encuentra en la posicion: "<<aux+1<<endl;
			imprimir();
			break;
		}
		tmp = tmp->getSiguiente();
		aux++;
	}
	if (tmp->getSiguiente()==NULL){
     if(tmp->getEntrada()== num->getEntrada()){
        cout<<"\nEl dato se encuentra en la ultima posicion"<<endl;
    }else
		cout << "\nEl numero no existe\n";
	}
	}
}
void Clista::imprimir(){
	Cnodo *tmp=this->origen;
		while(tmp){
			cout<<tmp->getEntrada()<<"-->";
			tmp=tmp->getSiguiente();
		}
			cout<<"NULL\n";
}	
int Clista:: tamanioLista(){
    Cnodo* aux = this-> origen;
        int tamanio = 0;
        while (aux != nullptr){
            tamanio++;
            aux = aux->getSiguiente();
        }
        return tamanio;
}
void Clista::eliminarCab(int eliminar){
    Cnodo* aux;
    if(ListaVacia()){
        cout<<"\nLa lista esta vacia" << endl;
    }else{  
        if(eliminar<=tamanioLista()){ 
        for (int i=0; i<eliminar;i++){
            aux= this->origen;
            this->origen = this->origen-> getSiguiente();
            aux -> setSiguiente(NULL);
            delete aux;      
        }cout<<"\n";imprimir();
        }else{
             printf("\nNo se puede eliminar mas del tamanio de la lista\n");
        }
    }
}
void Clista::eliminarCol(int eliminar){
    int i=0;
    Cnodo* aux= this->origen;
    Cnodo* aux2;
    if (ListaVacia()){
        cout<< "\nLa lista se encuentra vacia" <<endl;
    }else{
        if (eliminar <= tamanioLista()){
            while (aux->getSiguiente()){
                aux2= aux;
                aux= aux->getSiguiente();
            }
            if(eliminar==tamanioLista()){
				origen= nullptr;
			}else{
        	   do{
            	aux2->setSiguiente(NULL);
                delete aux;
                aux= origen;
                aux2=nullptr;
                while (aux->getSiguiente()){
                aux2= aux;
                aux= aux->getSiguiente();
            	}
                i++;
               }while (i!=eliminar);
            }cout<<"\n";imprimir();
        }else{
			 printf("\nNo se puede eliminar mas del tamanio de la lista\n");
		}
    }
}

int Clista::sumarComponentes() {
    Cnodo* tmp = origen;
    int suma = 0;
    while (tmp) {
        suma += tmp->getEntrada();
        tmp = tmp->getSiguiente();
    }
    return suma;
}