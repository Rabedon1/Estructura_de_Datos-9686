/***********************************************************************
 * Module:  Operaciones.h
 * Author:  jaime
 * Modified: miércoles, 10 de mayo de 2023 10:36:46
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__class1_Operaciones_h)
#define __class1_Operaciones_h

#include <Fraccion.h>

class Operaciones
{
public:
   virtual Fraccion proceso(Fraccion obj1, Fraccion obj2)=0;
   virtual float proceso(float dato_1, float dato_2)=0;

protected:
private:

};

#endif