/* Completar */
#include "Diccionario.h"



Diccionario::Diccionario() {};

bool Diccionario::def(Clave k) const {
    bool res = false;
    for (int i = 0; !res and i < diccionario.size(); ++i) {
        if(diccionario[i].clave == k) res = true;
    }
    return res;
}

int Diccionario::posicion(Clave k) const{
    int posicion;
    for (int i = 0; i < diccionario.size(); ++i) {
        if(diccionario[i].clave == k) posicion = i;
    }
    return posicion;
}

void Diccionario::definir(Clave k, Valor v) {
    if(def(k)){
        int pos = posicion(k);
        diccionario[pos].valor = v;
    } else {
        Asociacion a;
        a.clave=k;
        a.valor=v;
        diccionario.push_back(a);
    }

}

Valor Diccionario::obtener(Clave k) const {
    int pos = posicion(k);
    Valor res = diccionario[pos].valor;
    return res;
}


void Diccionario::borrar(Clave k) {
    if (def(k)){
        int pos = posicion(k);
        diccionario.erase(diccionario.begin() + pos);
    }
}

vector<Clave> Diccionario::claves() const {
    vector<Clave> res;
    for (int i = 0; i < diccionario.size(); ++i) {
        res.push_back(diccionario[i].clave);
    }
    return res;
}

bool Diccionario::operator==(Diccionario o) {
    bool res=true;
    if (claves().size() != o.claves().size()) res = false;
    for (int i = 0; res and i < diccionario.size(); ++i) {
        if(!o.def(diccionario[i].clave)) res = false;
        else if (diccionario[i].valor != o.obtener(diccionario[i].clave)) res = false;
    }
    return res;
}

int Diccionario::size() {
    return claves().size();
}

Diccionario Diccionario::operator||(Diccionario o) {
    for (int i = 0; i < o.size(); ++i) {
        definir(o[i].clave, o[i].valor);
    }
}

Diccionario Diccionario::operator&&(Diccionario o) {
    for (int i = 0; i < ; ++i) {
        
    }
}






