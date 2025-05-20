#include "ListaDoble.h"
#include "Fecha.h"
#include "Movimiento.h"
#include "Cliente.h"
#include "Cuenta.h"

#include <iostream>

template <typename T>
ListaDoble<T>::ListaDoble(Nodo<T>* _cabeza) {
    cabeza = _cabeza;
    cola = _cabeza;
    if (cabeza) {
        cabeza->set_siguiente(cabeza);
        cabeza->set_anterior(cabeza);
    }
}

template <typename T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
ListaDoble<T>::~ListaDoble() {
    if (!esta_vacia()) {
        Nodo<T>* actual = cabeza;
        Nodo<T>* siguiente;
        do {
            siguiente = actual->get_siguiente();
            delete actual;
            actual = siguiente;
        } while (actual != cabeza);
    }
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cabeza() {
    return cabeza;
}

template <typename T>
void ListaDoble<T>::set_cabeza(Nodo<T>* nueva_cabeza) {
    cabeza = nueva_cabeza;
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cola() {
    return cola;
}

template <typename T>
void ListaDoble<T>::set_cola(Nodo<T>* nueva_cola) {
    cola = nueva_cola;
}

template <typename T>
void ListaDoble<T>::insertar_cola(T valor) {
    Nodo<T>* nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
    if (esta_vacia()) {
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
void ListaDoble<T>::imprimir() {
    if (esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        std::cout << aux->get_valor() << " ";
        aux = aux->get_siguiente();
    } while (aux != cabeza);
    std::cout << std::endl;
}

template <typename T>
bool ListaDoble<T>::esta_vacia() {
    return (cabeza == nullptr);
}

template <typename T>
void ListaDoble<T>::recorrer(std::function<void(T)> func) {
    if (esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        func(aux->get_valor());
        aux = aux->get_siguiente();
    } while (aux != cabeza);
}

template <typename T>
void ListaDoble<T>::filtrar(std::function<bool(const T&)> criterio, std::function<void(const T&)> accion) {
    if (esta_vacia()) return;
    Nodo<T>* aux = cabeza;
    do {
        if (criterio(aux->get_valor())) {
            accion(aux->get_valor());
        }
        aux = aux->get_siguiente();
    } while (aux != cabeza);
}
template <typename T>
Nodo<T>* ListaDoble<T>::buscar(std::function<bool(T)> criterio) {
    if (esta_vacia()) return nullptr;
    Nodo<T>* aux = cabeza;
    do {
        if (criterio(aux->get_valor())) {
            return aux;
        }
        aux = aux->get_siguiente();
    } while (aux != cabeza);
    return nullptr;
}

template <typename T>
void ListaDoble<T>::eliminar(Nodo<T>* nodo) {
    if (!nodo || esta_vacia()) return;
    if (nodo == cabeza && cabeza == cola) {
        cabeza = nullptr;
        cola = nullptr;
        delete nodo;
        return;
    }
    Nodo<T>* anterior = nodo->get_anterior();
    Nodo<T>* siguiente = nodo->get_siguiente();
    anterior->set_siguiente(siguiente);
    siguiente->set_anterior(anterior);
    if (nodo == cabeza) cabeza = siguiente;
    if (nodo == cola) cola = anterior;
    delete nodo;
}

template class ListaDoble<int>;
template class ListaDoble<double>;
template class ListaDoble<Fecha>;
template class ListaDoble<Cuenta>;
template class ListaDoble<Movimiento>;
template class ListaDoble<Cliente>;