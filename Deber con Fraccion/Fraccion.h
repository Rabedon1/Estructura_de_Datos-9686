/***********************************************************************
 * Module:  Fraccion.h
 * Author:  jaime
 * Modified: miércoles, 10 de mayo de 2023 10:36:02
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__class1_Fraccion_h)
#define __class1_Fraccion_h

class Fraccion
{
public:
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion(float numerador, float denominador);
   ~Fraccion();

protected:
private:
   float Numerador;
   float Denominador;


};

#endif