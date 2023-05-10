/***********************************************************************
 * Module:  Fraccion.h
 * Author:  alexander
 * Modified: martes, 9 de mayo de 2023 17:10:08
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

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
