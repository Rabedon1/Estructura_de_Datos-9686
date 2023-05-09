/***********************************************************************
 * Module:  fraccion.h
 * Author:  raul2
 * Modified: lunes, 8 de mayo de 2023 20:37:05
 * Purpose: Declaration of the class fraccion
 ***********************************************************************/

#if !defined(__fraccion2_fraccion_h)
#define __fraccion2_fraccion_h

class fraccion
{
public:
   fraccion(fraccion num, fraccion den);
   fraccion();
   ~fraccion();
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   fraccion proceso(fraccion obj1, fraccion obj2);

protected:
private:
   float numerador;
   float denominador;


};

#endif