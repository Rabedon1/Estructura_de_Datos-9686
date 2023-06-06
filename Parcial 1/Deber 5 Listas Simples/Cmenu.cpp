/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 29/05/23 20:32
 * Fecha de modificacion: 06/06/23 13:30
 * Tema: Listas Simples 
 *******************************************************************************/ 

#include "Cmenu.h"
#include "Clista.cpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>

//Funciones para ingresar Datos
char* Cmenu::ingresarDatosEnteros(char *msj){ //Puntero sinónimo de arreglo
    char *dato=new char[10],c; //New instancia (fusionar o enlazar una clase con otra)
	int i=0; 
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}

char* Cmenu::ingresarDatosFlotantes(char *msj){
    char *dato=new char[10],c;
	int i=0, punto=0;
    printf("%s ",msj);
    while((c=getch())!=13){
        if(c>='0'&& c<='9'){
            printf("%c",c);
            dato[i++]=c;
        }
        else if(c=='.' && punto==0){
            printf("%c",c);
            punto--;
            dato[i++]=c;
        }
        else if(c==8 || c==127){
            printf("\b \b");
            punto=0;
            dato[i--]=0;
        }
	}
	dato[i]='\0';
	return dato;
}

char* Cmenu::ingresarChar(char *msj){
	char *dato=new char[20],c;
	int i=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>=97 && c<=122){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}

void Cmenu::menuPrincipal(){
    Clista listaCab,listaCol;
    do{
        menu:
        system("cls");
        printf("\t\tLISTA SIMPLE\n1)Ingreso por Cabeza\n2)Ingreso por Cola\n3)Mostrar Lista\n4)Eliminar por Cabeza\n5)Eliminar por Cola\n6)Buscar\n7)Sumar los componentes de las listas\n8)Salir");
        strcpy(dato,ingresarDatosEnteros("\n>Ingrese la opcion deseada: "));
        opcion=atoi(dato);
        switch (opcion)
        {
            case 1:
                {
                system("cls");
                printf("\t\tIngreso por Cabeza\n");
                strcpy(dato1,ingresarDatosEnteros("\n>Ingrese el valor a la lista: "));
                int valor=atoi(dato1);
                std::cout<<endl;
                listaCab.insertarCab(valor);
                listaCab.imprimir();
                std::cout<<endl;
                system("pause");
                goto menu;
                break;
                }
            case 2:
                {
                system("cls");
                printf("\t\tIngreso por Cola\n");
				//codigo
                strcpy(dato2,ingresarDatosEnteros("\n>Ingrese el valor a la lista: "));
                int valor2=atoi(dato2);
                std::cout<<endl;
                listaCol.insertarCol(valor2);
                listaCol.imprimir();
                std::cout<<endl;
                system("pause");
                goto menu;
                break;
                }
            case 3:
                {
				system("cls");
				printf("\t\tMostrar Lista\n");
				//codigo
                std::cout<<">La lista por Cabeza:"<<endl;
                listaCab.imprimir();
                std::cout<<">La lista por Cola:"<<endl;
                listaCol.imprimir();
				system("pause");
				goto menu;
				break;
                }
			case 4:
				{
				system("cls");
				printf("\t\tEliminar por Cabeza\n");
				//codigo
                listaCab.imprimir();
                strcpy(dato3,ingresarDatosEnteros("\n>Ingrese el numero de elementos a eliminar: "));
                int elimCab=atoi(dato3);
                std::cout<<endl;
                listaCab.eliminarCab(elimCab);
                listaCab.imprimir();
                std::cout<<endl;
                system("pause");
				break;
				}
            case 5:
				{
				system("cls");
				printf("\t\tEliminar por Cola\n");
				//codigo
                listaCol.imprimir();
                strcpy(dato4,ingresarDatosEnteros("\n>Ingrese el numero de elementos a eliminar: "));
                int elimCola=atoi(dato4);
                std::cout<<endl;
                listaCol.eliminarCol(elimCola);
                listaCol.imprimir();
                std::cout<<endl;
                system("pause");
				break;
				}
            case 6:
				{
				system("cls");
				printf("\t\tBuscar\n");
				std::cout<<">La lista por Cabeza:"<<endl;
                listaCab.imprimir();
                std::cout<<">La lista por Cola:"<<endl;
                listaCol.imprimir();
                std::cout<<endl;
                strcpy(dato5,ingresarDatosEnteros("\n>Ingrese el valor a buscar de la lista de datos ingresador por Cabeza: "));
                int busCab=atoi(dato5);
                std::cout<<endl;
                listaCab.buscar(busCab);
                std::cout<<endl;
                strcpy(dato6,ingresarDatosEnteros("\n>Ingrese el valor a buscar de la lista de datos ingresados por Cola: "));
                int busCola=atoi(dato6);
                std::cout<<endl;
                listaCol.buscar(busCola);
                std::cout<<endl;
				//codigo
                system("pause");
				break;
				}
			case 7:
				{
				system("cls");
                printf("\t\tSumar Componentes\n");
                std::cout << ">La lista por Cabeza:" << std::endl;
                listaCab.imprimir();
                std::cout << ">La lista por Cola:" << std::endl;
                listaCol.imprimir();
                std::cout << std::endl;
                int sumaCab = listaCab.sumarComponentes();
                std::cout << "Suma de los componentes en la lista por Cabeza: " << sumaCab << std::endl;
                int sumaCol = listaCol.sumarComponentes();
                std::cout << "Suma de los componentes en la lista por Cola: " << sumaCol << std::endl;
                std::cout << std::endl;
                system("pause");
                break;
				}
			case 8:
            	{
                
                exit(0);

        		}
        } 
    }while (opcion>0 || opcion<8);
    system("pause");
}