/*************************************************************************************************
 *              Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.h
 * Materia: Estructura de datos
 * Integrantes: Alexander Bedon, Jaime Reyes, Raúl Silva
 * Fecha de creacion: lunes, 8 de mayo de 2023 10:15:36
 * Ultima modificación: martes, 9 de mayo de 2023 17:10:08
 * Enunciado: Crear una clase fraccion, donde resuelva la siguiente operacion matematica, 
 * (n1*d2)+(n2*d1)/(d1+d2), con TDA (Tipo de datos abstractos).
 *************************************************************************************************/

#if !defined(__Practica_Fraccion_Fraccion_h)
#define __Practica_Fraccion_Fraccion_h

class Fraccion
{
public:
   Fraccion(float num, float den);
   ~Fraccion();
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion();
   float proceso(Fraccion obj1, Fraccion obj2);
   Fraccion proceso_1(Fraccion obj1, Fraccion obj2);
   Fraccion proceso_2(float obj1, float obj2);
   void imprimir(Fraccion obj);

protected:
private:
  float Numerador;
  float Denominador;


};

#endif
