#include "Funciones.cpp"

using namespace std;

int main(int argc, char** argv) {
	Funciones f;
	f.encerar();
	f.llenarRandom();
	f.imprimirMatrices();
	f.sumaRecursivaMatrices(f.getMat1(),f.getMat2(),f.getMatR(), 2, 2);
	std::cout<<endl;
	std::cout<<"Los resultados son:"<<endl;
	std::cout<<"suma: "<<endl;
	f.resultado();
	
	                    
	
	//Realizamos el calculo
	int i = 0;
	f.multiplicacionRecursivaMatrizA(f.getMat1(),f.getMat2(),f.getMatR(),i);
	std::cout<<endl;         
	std::cout<<"mutiplicacion: "<<endl;
	                                                   
	//imprimimos la matriz resultante	
	f.resultado();
	free(f.getMat1());
	free(f.getMat2());
	free(f.getMatR());
	system("PAUSE");
	return 0;
}