#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

template <class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
   /* const typename Contenedor::value_type* min = &*(c.begin());
    for (auto& e : c) {
        if (e < *min)
            min = &e;
    }
    return *min;*/

    auto min = c.begin();
    for (auto i = c.begin(); i != c.end() ; ++i) {
        if (*i < *min)
            min = i;
    }
    return *min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type total = 0;
    int size = 0;
    for (auto i = c.begin(); i != c.end() ; ++i) {
        total += *i;
        size++;
    }
    return total/size;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min = desde;
    for (auto i = desde; i != hasta ; ++i) {
        if (*i < *min)
            min = i;
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type total = 0;
    int size = 0;
    for (auto i = desde; i != hasta ; ++i) {
        total += *i;
        size++;
    }
    return total/size;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto i = c.begin();
    while (i != c.end()) {
        if (*i == elem) {
            i = c.erase(i);
        } else {
            i++;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c){
    if (c.begin() == c.end()) return true;
    bool res = true;
    auto i = c.begin();
    auto a = *i;
    auto b = *i;
    i++;
    while (i != c.end() and res) {
        b = *i;
        if (a > b) {
            res = false;
        } else {
            a = *i;
            i++;
        }
    }
    return res;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    std::pair<Contenedor, Contenedor> res;
    for (auto i = c.begin(); i != c.end() ; ++i) {
        if (*i < elem) {
            res.first.insert(res.first.end(), *i);
        } else {
            res.second.insert(res.second.end(), *i);
        }
    }
    return res;
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    Contenedor cc1 = c1;
    Contenedor cc2 = c2;
    auto i1 = cc1.begin();
    auto i2 = cc2.begin();
    while(i1 != cc1.end() or i2 != cc2.end()){
        if(i1 != cc1.end() and i2 != cc2.end()){
            if (*i1 < *i2){
                res.insert(res.end(), *i1);
                i1 = cc1.erase(i1);
            }else{
                res.insert(res.end(), *i2);
                i2 = cc2.erase(i2);
            }
        } else if (i1 == cc1.end() and i2 != cc2.end()){
            res.insert(res.end(), *i2);
            i2 = cc2.erase(i2);
        } else if (i1 != cc1.end() and i2 == cc2.end()){
            res.insert(res.end(), *i1);
            i1 = cc1.erase(i1);
        }
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
