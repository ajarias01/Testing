/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.h
 * Author:  Joan Cobe�a, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Declaracion de clase ListaDoble
 ***********************************************************************/
#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include "Nodo.h"

template <typename T>
class ListaDoble
{
public:
    ListaDoble<T>(Nodo<T>* _cabeza);
    ListaDoble<T>();
    Nodo<T>* get_cabeza();
    void set_cabeza(Nodo<T>*);
    Nodo<T>* get_cola();
    void set_cola(Nodo<T>*);
    void insertar_cola(T valor);
    void imprimir();
    bool esta_vacia();
    // NUEVO: Recorrido con lambda
    void recorrer(std::function<void(T)> func);
    // NUEVO: Filtrar por lambda
    void filtrar(std::function<bool(T)> criterio, std::function<void(T)> accion);
protected:
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
};

#endif // LISTADOBLE_H_INCLUDED
