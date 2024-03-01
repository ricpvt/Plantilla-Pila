#ifndef PILA_HPP
#define PILA_HPP

template <typename T>
class Pila{
	public:
        Pila();
        ~Pila();
        Pila(const Pila& p);
        Pila& operator=(const Pila& p);
        void Agregar(T valor);
        void Eliminar();
        T ObtenerTope() const;
        void Vaciar();
        int ObtenerTam() const;
        bool EstaVacia() const;

        void Imprimir() const;

	private:
		struct Elemento{
			T valor;
			Elemento * siguiente;
			Elemento(T val) : valor(val), siguiente(nullptr) {}
		} * tope;
		int tam;
};

#include "Pila.tpp"

#endif // PILA_HPP
