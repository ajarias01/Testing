#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include "Nodo.h"
#include <functional>

template <typename T>
class ListaDoble {
public:
    ListaDoble(Nodo<T>* _cabeza);
    ListaDoble();
    ~ListaDoble();
    Nodo<T>* get_cabeza();
    void set_cabeza(Nodo<T>*);
    Nodo<T>* get_cola();
    void set_cola(Nodo<T>*);
    void insertar_cola(T valor);
    void imprimir();
    bool esta_vacia();
    void recorrer(std::function<void(T)> func);
    void filtrar(std::function<bool(const T&)> criterio, std::function<void(const T&)> accion);
    Nodo<T>* buscar(std::function<bool(T)> criterio);
    void eliminar(Nodo<T>* nodo);
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
};

#endif