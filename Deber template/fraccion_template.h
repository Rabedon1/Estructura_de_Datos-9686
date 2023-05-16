#include <iostream>


template <typename T>
class Operacion {
	private:
		T numerador1,numerador2, denominador1,denominador2;
	public:
		Operacion(T num1,T num2,T den1,T den2) : numerador1(num1), numerador2(num2),denominador1(den1), denominador2(den2){};
		~Operacion() {};
		
		void calculo();
		T numCalculo();
		T denCalculo();
	
};

#endif
