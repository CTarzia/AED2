#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero = NULL;
    ultimo = NULL;
    _longitud = 0;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } //?????????

template <typename T>
Lista<T>::~Lista() {
    Nodo* p = primero;
    while (p != NULL){
        Nodo* q = p -> siguiente;
        delete p;
        p = q;
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    while (_longitud != 0){
        eliminar(0);
    }
    if (l._longitud > 0) {
        Nodo *p = l.primero;
        while (p != l.ultimo) {
            agregarAtras(p -> valor);
            p = p->siguiente;
        }
        agregarAtras(p -> valor);
    }
    /*p = p-> siguiente;
    while (p != NULL){
        Nodo* q = p -> siguiente;
        delete p;
        p = q;
    }*/
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    if (_longitud == 0){
        Nodo* n = new Nodo(NULL, elem, NULL);
        ultimo = n;
        primero = n;
    } else {
        Nodo* n = new Nodo(NULL, elem, primero);
        primero -> anterior = n;
        primero = n;
    }
    _longitud++;
    /*
    Nodo* n = new Nodo;
    n -> valor = elem;
    n -> anterior = NULL;

    if (_longitud == 0){
        n -> siguiente = NULL;
        ultimo = n;
    } else {
        primero -> anterior = n;
        n -> siguiente = primero;
    }
    primero = n;
    _longitud++;
     */
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    if (_longitud == 0){
        Nodo* n = new Nodo(NULL, elem, NULL);
        primero = n;
        ultimo = n;
    } else {
        Nodo* n = new Nodo(ultimo, elem, NULL);
        ultimo -> siguiente = n;
        ultimo = n;
    }
    _longitud++;
    /*
    Nodo* n = new Nodo;
    n -> valor = elem;
    n -> siguiente = NULL;
    if (_longitud == 0){
        n -> anterior = NULL;
        primero = n;
    } else {
        ultimo -> siguiente = n;
        n -> anterior = ultimo;
    }
    ultimo = n;
    _longitud++;
     */
}

template <typename T>
int Lista<T>::longitud() const {
    return _longitud;
    /*Nodo* p = primero;
    int n = 0;
    if (p != NULL and p == ultimo) n++;
    else if (p != NULL){
        while (p != ultimo) {
            n++;
            p = p->siguiente;
        }
        n++;
    }
    return n;*/
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    return iesimo(i);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* p = primero;
    for (int j = 0; j < i; ++j) {
        p = p -> siguiente;
    }
    return p -> valor;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    if (i == 0) {
        Nodo* p = primero;
        if (_longitud > 1) {
            Nodo *nuevoPrimero = p -> siguiente;
            primero = nuevoPrimero;
            nuevoPrimero -> anterior = NULL;
        } else {
            primero = NULL;
            ultimo = NULL;
        }
        delete p;
    } else if (i == _longitud - 1) {
        Nodo* u = ultimo;
        Nodo* nuevoUltimo = u -> anterior;
        ultimo = nuevoUltimo;
        nuevoUltimo -> siguiente = NULL;
        delete u;
    } else {
        Nodo* n = primero;
        for (int j = 0; j < i; ++j) {
            n = n -> siguiente;
        }
        Nodo* antesp = n -> anterior;
        Nodo* sigp = n -> siguiente;

        sigp -> anterior = antesp;
        antesp -> siguiente = sigp;
        delete n;
    }
    _longitud--;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
    o << "[";
    for (int i = 0; i < _longitud; ++i) {
        o << iesimo(i) << ",";
    }
    o << "]";
}
