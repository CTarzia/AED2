#ifndef MULTICONJUNTO_HPP
#define MULTICONJUNTO_HPP

#include "Diccionario.hpp"

template <class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar (T x);
    int ocurrencias (T x) const;
    bool operator<= (Multiconjunto<T> otro);

private:
    Diccionario<T,int> _multi;
};

template <class T>
Multiconjunto<T>::Multiconjunto() {
}

template <class T>
void Multiconjunto<T>::agregar(T x) {
    if(!_multi.def(x)){
        _multi.definir(x, 1);
    } else {
        _multi.definir(x,_multi.obtener(x)+1);
    }
}

template <class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    if(!_multi.def(x)) return 0;
    else return _multi.obtener(x);
}

template <class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) {
    vector<T> c1 = _multi.claves();
    bool res = true;
    for (int i = 0; i < c1.size() and res; ++i) {
        if (ocurrencias(c1[i])>otro.ocurrencias(c1[i]) ) res = false;
    }
    return res;
}

#endif