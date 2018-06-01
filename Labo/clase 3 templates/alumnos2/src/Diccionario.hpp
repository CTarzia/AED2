using namespace std;
#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP
#include <cassert>
#include <vector>


template <class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    vector<Clave> claves() const;
    vector<Clave> clavesDesordenadas() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template <class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {
}

template <class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template <class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template <class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template <class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template <class T>
int buscarMin(vector<T> v){
    int res = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i]<=v[res]) res = i;
    }
    return res;
}

template <class T>
void borrar (int n, vector<T> &v){
    v[n] = v[v.size()-1];
    v.pop_back();
}

template <class T>
vector<T> selectionSort(vector<T> v){
    vector<T> res;
    while (0 < v.size()) {
        int min = buscarMin(v);
        res.push_back(v[min]);
        borrar(min,v);
    }
    return res;
}

template <class Clave, class Valor>
vector<Clave> Diccionario<Clave,Valor>::claves() const {
    return selectionSort(clavesDesordenadas());
}

template <class Clave, class Valor>
vector<Clave> Diccionario<Clave,Valor>::clavesDesordenadas() const {
    vector<Clave> res;
    for (int i = 0; i < _asociaciones.size(); ++i) {
        res.push_back(_asociaciones[i].clave);
    }
    return res;
}

#endif