#include <iostream>

template <typename T>
Pila<T>::Pila() : tope(nullptr){
    tam = 0;
}

template <typename T>
Pila<T>::~Pila(){
    Vaciar();
}

template <typename T>
Pila<T>::Pila(const Pila<T>& p) : tope(nullptr){
    if (p.tope) {
        Elemento * actual = p.tope;
        Elemento * nuevoTope = new Elemento (actual->valor);
        tope = nuevoTope;
        actual = actual->siguiente;

        while (actual != nullptr) {
            nuevoTope->siguiente = new Elemento (actual->valor);
            nuevoTope = nuevoTope->siguiente;
            actual = actual->siguiente;
        }
    }
    *this = p;
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p){
    if (this != &p){
        Vaciar();
        if(p.tope != nullptr){
            Elemento * actualPila = p.tope;
            Elemento * nuevoTope = new Elemento(actualPila -> valor);
            tope = nuevoTope;
            actualPila = actualPila -> siguiente;

            while(actualPila  != nullptr){
                nuevoTope -> siguiente = new Elemento(actualPila -> valor);
                nuevoTope = nuevoTope -> siguiente;
                actualPila = actualPila -> siguiente;
            }
        }
    }

    return *this;
}

template <typename T>
void Pila<T>::Agregar(T valor){
    Elemento * nuevo = new Elemento(valor);
    nuevo -> siguiente = tope;
    tope = nuevo;
    tam++;
}

template <typename T>
void Pila<T>::Eliminar(){
    if(EstaVacia()) throw "Error: ta vacia";
    Elemento * aux = tope;
    tope = tope -> siguiente;
    delete aux;
    tam--;
}

template <typename T>
T Pila<T>::ObtenerTope() const{
    if(EstaVacia()) throw "Error: ta vacia";
    return tope -> valor;
}

template <typename T>
void Pila<T>::Vaciar(){
    while(!EstaVacia()) Eliminar();
}

template <typename T>
int Pila<T>::ObtenerTam() const{
    return tam;
}

template <typename T>
bool Pila<T>::EstaVacia() const{
    return tope == nullptr;
}

template <typename T>
void Pila<T>::Imprimir() const{
    if(EstaVacia()) throw "Error: ta vacia";
        Elemento* actual = tope;
        std::cout << "Pila: ";
        while (actual != nullptr) {
            std::cout << actual -> valor << ", ";
            actual = actual -> siguiente;
        }
        std::cout << "\b\b<-- tope" << std::endl;
}
