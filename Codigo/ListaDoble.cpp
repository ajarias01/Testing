/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.cpp
 * Author:  Joan Cobe�a, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Implementacion de clase ListaDoble
 ***********************************************************************/

#include "ListaDoble.h"

template <typename T>
ListaDoble<T>::ListaDoble(Nodo<T>* _cabeza){
    cabeza = _cabeza;
    cola = _cabeza;
    if(cabeza){
        cabeza->set_siguiente(cabeza);
        cabeza->set_anterior(cabeza);
    }
}

template <typename T>
ListaDoble<T>::ListaDoble(){
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cabeza(){
    return cabeza;
}

template <typename T>
void ListaDoble<T>::set_cabeza(Nodo<T>* nueva_cabeza){
    cabeza = nueva_cabeza;
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cola(){
    return cola;
}

template <typename T>
void ListaDoble<T>::set_cola(Nodo<T>* nueva_cola){
    cola = nueva_cola;
}

template <typename T>
void ListaDoble<T>::insertar_cola(T valor){
    Nodo<T>* nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
    if(esta_vacia()){
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
        cabeza->set_siguiente(cabeza);
        cabeza->set_anterior(cabeza);
    } else {
        nuevo_nodo->set_anterior(cola);
        nuevo_nodo->set_siguiente(cabeza);
        cola->set_siguiente(nuevo_nodo);
        cabeza->set_anterior(nuevo_nodo);
        cola = nuevo_nodo;
    }
}

template <typename T>
void ListaDoble<T>::imprimir(){
    if(esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        // Para tipos double, int, etc.
        std::cout << aux->get_valor() << " ";
        aux = aux->get_siguiente();
    } while(aux != cabeza);
    std::cout << std::endl;
}

template <typename T>
bool ListaDoble<T>::esta_vacia(){
    return (cabeza == nullptr);
}

// NUEVO: Recorrer con lambda
template <typename T>
void ListaDoble<T>::recorrer(std::function<void(T)> func){
    if(esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        func(aux->get_valor());
        aux = aux->get_siguiente();
    } while(aux != cabeza);
}

// NUEVO: Filtrar con lambda
template <typename T>
void ListaDoble<T>::filtrar(std::function<bool(T)> criterio, std::function<void(T)> accion){
    if(esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        if(criterio(aux->get_valor())){
            accion(aux->get_valor());
        }
        aux = aux->get_siguiente();
    } while(aux != cabeza);
}