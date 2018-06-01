#include "DiccHash.h"

/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash() {
	_tabla = new list<Asociacion>[TAM_INICIAL];
    _tam = TAM_INICIAL;
    _cant_claves = 0;
}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {
    for (int i = 0; i < _tabla->size(); ++i) {
        list<Asociacion>* l = &_tabla[i];
        delete l;
    }
    //delete _tabla;
}

template<class V>
typename DiccHash<V>::Asociacion* DiccHash<V>::buscar(string clav) {
    list<Asociacion>& l = _tabla[fn_hash(clav)];
    Asociacion* res;
    for (typename std::list<Asociacion>::iterator it = l.begin(); it!=l.end(); ++it) {
            if (it->clave == clav) {
            return &*it;
        }
    }
}

/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string& clav) const {
	bool res = false;
    list<Asociacion>& l = _tabla[fn_hash(clav)];
    for (auto& a : l) {
        if(a.clave == clav){
            res = true;
        }
    }
    return res;
}

/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 *
 * Pasos a seguir para redimensionar la tabla:
 * - Crear una tabla del doble de tamaño de la original.
 * - Insertar todas las claves de la tabla original en la tabla nueva.
 * - Liberar la memoria reservada para la tabla original.
 */
template<class V>
void DiccHash<V>::definir(const string& clav, const V& sig) {
	if (definido(clav)){
        Asociacion* posicion = buscar(clav);
        posicion->valor = sig;
    } else {
        Asociacion a = Asociacion(clav,sig);
        _tabla[fn_hash(clav)].push_back(a);
        _cant_claves++;
    }
}

/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V& DiccHash<V>::significado(const string& clav) {
	return buscar(clav)->valor;
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string& clav) {
    list<Asociacion>& l = _tabla[fn_hash(clav)];
    bool flag = true;
    typename std::list<Asociacion>::iterator it = l.begin();
    while (it!=l.end() and flag) {
        if (it->clave == clav) {
            flag = false;
        } else {
            it++;
        }
    }
    l.erase(it);
    _cant_claves--;
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
	return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
	set<string> res;
    for (int i = 0; i < _tam; ++i) {
        list<Asociacion>& l = _tabla[i];
        for (auto& a : l) {
            res.insert(a.clave);
        }
    }
    return res;
}

/* SÓLO PARA TESTING
 *
 * Devuelve el factor de carga de la tabla de hash.
 * Factor de carga : cantidad de claves definidas / tamaño de la tabla.
 */
template<class V>
float DiccHash<V>::factorCarga() const {
	return _cant_claves / _tam;
}

/* SÓLO PARA TESTING
 * Devuelve la cantidad de colisiones que tiene el diccionario.
 *
 * Observación: si en una celda de la tabla conviven n elementos,
 * hay n * (n - 1) / 2 colisiones en esa celda.
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
	unsigned int suma = 0;
	for (int i = 0; i < _tam; i++) {
		suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
	}
	return suma;
}

/* Función de hash.
 * Recordar usar "hash = hash % _tam".
 * (El operador "%" calcula el resto en la división o "módulo").
 * Devuelve la posición de la tabla asociada a la clave dada.
 */
template<class V>
unsigned int DiccHash<V>::fn_hash(const string& str) const {
	int val = 0;
    for(auto a : str){
        val += (int) a;
    }
    return val % _tam;
}

