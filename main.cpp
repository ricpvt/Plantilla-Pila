#include <iostream>
#include <cmath>
#include "Pila.hpp"

using namespace std;

double EcuacionPolacaInversa(string cadena);

int main(){
	Pila<int> p, p2;
	p.Agregar(2);
	p.Agregar(5);
	p.Agregar(4312);
	p2 = p;
	p.Imprimir();
	p2.Eliminar();
	p2.Imprimir();

	cout << EcuacionPolacaInversa("5;7+6*4+2;3-4//2^"); // {[(5 + 7) * 6 + 4] / [(2 - 3) / 4]} ^ 2

	system("pause");
	return 0;
}

double EcuacionPolacaInversa(string cadena){
	Pila<double> p;
	double a,b; 
	int i=0;
	while(cadena[i]!='\0') {
	    if(cadena[i] == '+' || cadena[i] == '-' || cadena[i] == '*' || cadena[i] == '/' || cadena[i] == '^'){
	    	b = p.ObtenerTope();
	    	p.Eliminar();
	    	a = p.ObtenerTope();
	    	p.Eliminar();
	    }
	    switch (cadena[i]){
	    case '+':
	    	p.Agregar(a + b);
	    	break;
	    case '-':
	    	p.Agregar(a - b);
	    	break;
	    case '*':
	    	p.Agregar(a * b);
	    	break;
	    case '/':
	    	p.Agregar(a / b);
	    	break;
	    case '^':
	    	p.Agregar(pow(a, b));
	    	break;
	    case ';':
	    	
	    	break;
	    default:
	    	p.Agregar(cadena[i]-48);
	    }//Fin switch
	    i++;
	}
	return p.ObtenerTope();
}