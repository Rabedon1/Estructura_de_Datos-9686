#include "Funciones.cpp"

using namespace std;

int main(int argc, char** argv) {
	Funciones f;
	f.encerar();
	f.llenarRandom();
	f.imprimirMatrices();
	f.sumaRecursivaMatrices(f.getMat1(),f.getMat2(),f.getMatR(), 2, 2);
	std::cout<<endl;
	std::cout<<"El resultado de la suma es:"<<endl;
	f.resultado();
	f.multiplicacionRecursivaMatrices(f.getMat1(), f.getMat2(), f.getMatR(), MAX - 1, MAX - 1, MAX - 1);
	std::cout<<endl;
	std::cout<<"El resultado de la multiplicacion es:"<<endl;
    f.resultado();
	system("PAUSE");
	return 0;
}