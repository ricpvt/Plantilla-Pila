#include <iostream>
#include "Pila.hpp"

using namespace std;

int main(){
	Pila<int> p, p2;
	p.Agregar(2);
	p.Agregar(5);
	p.Agregar(4312);
	p2 = p;
	p.Imprimir();
	p2.Eliminar();
	p2.Imprimir();

	system("pause");
	return 0;
}