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
        Elemento * aux = p.tope;
        Elemento * nuevoTope = new Elemento (aux->valor);
        tope = nuevoTope;
        aux = aux->siguiente;

        while (aux != nullptr) {
            nuevoTope->siguiente = new Elemento (aux->valor);
            nuevoTope = nuevoTope->siguiente;
            aux = aux->siguiente;
        }
    }
    *this = p;
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p){
    if (this != &p){
        Vaciar();
        if(p.tope != nullptr){
            Elemento * aux1 = p.tope;
            Elemento * aux2 = new Elemento(aux1 -> valor);
            tope = aux2;
            aux1 = aux1 -> siguiente;

            while(aux1 != nullptr){
                aux2 -> siguiente = new Elemento(aux1 -> valor);
                aux2 = aux2 -> siguiente;
                aux1 = aux1 -> siguiente;
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
