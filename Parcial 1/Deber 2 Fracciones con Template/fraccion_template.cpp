/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Roberto Bedon, Jaime Reyes, Raul Silva.
 * Fecha de creacion: 13/05/23 10:32
 * Fecha de modificacion: 29/05/23 13:30
 * Tema: Operacion de fracciones con template
 *******************************************************************************/ 
#include "fraccion_template.h"


template <typename T>
void Operacion<T>::calculo(){
    std::cout <<"Numeros: " << numerador1 << "/" << denominador1<< " y " << numerador2 << "/" << denominador2 <<std::endl;
    std::cout <<"resultado (n1*d2+n2*d1)/(d1+d2): "<<numCalculo()<<"/"<<denCalculo()<<std::endl;
    
}

template <typename T>
T Operacion<T>::numCalculo() { return ((numerador1 * denominador2)+(numerador2 * denominador1)); }

template <typename T>
T Operacion<T>::denCalculo() { return denominador1 + denominador2; }




