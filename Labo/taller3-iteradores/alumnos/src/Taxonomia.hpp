#include <sstream>

// Métodos de Taxonomia (ya implementados por la cátedra):

template<class T>
int Taxonomia<T>::_espiarProximoCaracter(istream& is) const {
	int c = is.peek();
	while (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
		is.get();
		c = is.peek();
	}
	return is.peek();
}

template<class T>
typename Taxonomia<T>::Nodo* Taxonomia<T>::_leerDe(istream& is) {
	Taxonomia<T>::Nodo* nodo = new Taxonomia<T>::Nodo();
	is >> nodo->valor;
	if (_espiarProximoCaracter(is) == '{') {
		is.get();
		while (_espiarProximoCaracter(is) != '}') {
			nodo->hijos.push_back(_leerDe(is));
		}
		is.get();
	}
	return nodo;
}

template<class T>
Taxonomia<T>::Taxonomia(const string& input) {
	istringstream is(input);
	_raiz = _leerDe(is);
}

template<class T>
void Taxonomia<T>::_borrar(Taxonomia<T>::Nodo* nodo) {
	for (int i = 0; i < nodo->hijos.size(); i++) {
		_borrar(nodo->hijos[i]);
	}
	delete nodo;
}

template<class T>
Taxonomia<T>::~Taxonomia() {
	_borrar(_raiz);
}

template<class T>
void Taxonomia<T>::_identar(ostream& os, int tab) const {
	for (int i = 0; i < tab; i++) {
		os << "  ";
	}
}

template<class T>
void Taxonomia<T>::_mostrarEn(
		ostream& os, Taxonomia<T>::Nodo* nodo, int tab) const {
	_identar(os, tab);
	os << nodo->valor;
	if (nodo->hijos.size() == 0) {
		os << "\n";
	} else {
		os << " {\n";
		for (int i = 0; i < nodo->hijos.size(); i++) {
			_mostrarEn(os, nodo->hijos[i], tab + 1);
		}
		_identar(os, tab);
		os << "}\n";
	}
}

template<class T>
void Taxonomia<T>::mostrar(ostream& os) const {
	_mostrarEn(os, _raiz, 0);
}

////////////////////////////////////////

// Métodos para implementar el iterador de Taxonomia<T> (para completar)

template <class T>
Taxonomia<T>::iterator::iterator(Nodo* n, int pos) {
    pair<Nodo*,int> p = make_pair(n,pos);
    _camino.push_back(p);
    _actual = n;
}

// Devuelve un iterador válido al principio de la taxonomía.

template<class T>
typename Taxonomia<T>::iterator Taxonomia<T>::begin() {
    return iterator(_raiz, 0);
}

// Devuelve un iterador válido al final de la taxonomía.
template<class T>
typename Taxonomia<T>::iterator Taxonomia<T>::end() {
	Nodo* n = _raiz;
    iterator it = iterator(n,0);
    int numHijos = (int) n->hijos.size()-1;
    while(numHijos >= 0){
        n = n->hijos.back();
        it.subcategoria(numHijos);
        numHijos = (int) n->hijos.size()-1;
    }
    return it;
}

// Constructor por defecto del iterador.
// (Nota: puede construir un iterador inválido).
template<class T>
Taxonomia<T>::iterator::iterator() {
	_actual = NULL;
    vector< pair<Nodo*, int> > v;
    _camino = v;
}

// Referencia mutable al nombre de la categoría actual.
// Pre: el iterador está posicionado sobre una categoría.
template<class T>
T& Taxonomia<T>::iterator::operator*() const {
	return _actual->valor;
}

// Cantidad de subcategorías de la categoría actual.
// Pre: el iterador está posicionado sobre una categoría.
template<class T>
int Taxonomia<T>::iterator::cantSubcategorias() const {
    return (int)_actual->hijos.size();
}

// Ubica el iterador sobre la i-ésima subcategoría.
// Pre: el iterador está posicionado sobre una categoría
// y además 0 <= i < cantSubcategorias().
template<class T>
void Taxonomia<T>::iterator::subcategoria(int i) {
    _camino.push_back(make_pair(_actual->hijos[i], i));
    _actual = _actual->hijos[i];
}

// Devuelve true sii la categoría actual es la raíz. 
// Pre: el iterador está posicionado sobre una categoría.
template<class T>
bool Taxonomia<T>::iterator::esRaiz() const {
	return _camino.size() == 1;
}

// Ubica el iterador sobre la supercategoría de la categoría
// actual.
// Pre: el iterador está posicionado sobre una categoría
// y además !esRaiz()
template<class T>
void Taxonomia<T>::iterator::supercategoria() {
	_camino.pop_back();
    _actual = _camino.back().first;
}

// Compara dos iteradores por igualdad.
// Pre: deben ser dos iteradores de la misma taxonomía.
template<class T>
bool Taxonomia<T>::iterator::operator==(const Taxonomia<T>::iterator& otro) const {
	return _actual == otro._actual /*and _camino == otro._camino*/;
}

// Ubica el iterador sobre la categoría siguiente a la actual
// en el recorrido *preorder* de la taxonomía.
// Si se trata de la última categoría de la taxonomía,
// el iterador resultante debe ser igual al iterador end()
// de la taxonomía.
template<class T>
void Taxonomia<T>::iterator::operator++() {
    if (!esEnd()) {
        if (_actual->hijos.size() > 0) {
            subcategoria(0);
        } else {
            pair<Nodo *, int> p = _camino.back();
            _camino.pop_back();
            while (_camino.back().first->hijos.size() == p.second + 1) {
                p = _camino.back();
                _camino.pop_back();
            }
            _actual = _camino.back().first;
            subcategoria(p.second + 1);
        }
    }
}

template <class T>
bool Taxonomia<T>::iterator::esEnd() {
    if (_actual->hijos.size() > 0) return false;
    else if (esRaiz()) return _actual->hijos.size() == 0;
    bool res = true;
    vector< pair<Nodo*, int> > cam = _camino;
    pair<Nodo*, int> p;
    while (cam.size() > 1 and res){
        p = cam.back();
        cam.pop_back();
        if (cam.back().first->hijos.size() - 1 != p.second){
            res = false;
        }
    }
    return res;
}

// Ubica el iterador sobre la categoría anterior a la actual
// en el recorrido *preorder* de la taxonomía.
// Si se trata de la raíz de la taxonomía el iterador
// resultante debe ser igual al iterador end() de la taxonomía.
// Pre: el iterador está posicionado sobre una categoría.
template<class T>
void Taxonomia<T>::iterator::operator--() {
    if (esRaiz()) {
        int numHijos = (int) _actual->hijos.size()-1;
        while(numHijos >= 0) {
            subcategoria(numHijos);
            numHijos = (int) _actual->hijos.size()-1;
        }
    } else {
        if (_camino.back().second == 0){
            supercategoria();
        } else {
            int nuevaPos = _camino.back().second - 1;
            supercategoria();
            subcategoria(nuevaPos);
            while (_actual->hijos.size() > 0) {
                subcategoria((int) _actual->hijos.size()-1);
            }
        }
    }
}

// Inserta una subcategoría con el nombre indicado
// en el lugar i-ésimo.
// Observación: esta operación modifica la taxonomía y
// puede invalidar otros iteradores.
// Pre: el iterador está posicionado sobre una categoría,
// y además 0 <= i <= cantSubcategorias().
/*
template <class T>
void insertar (vector<T>& v, int pos, T elem){
    v.push_back(NULL);
    int i = (int) v.size()-2;
    while (i >= pos){
        v[i+1] = v[i];
        i--;
    }
    v[pos] = elem;
}
*/
template<class T>
void Taxonomia<T>::iterator::insertarSubcategoria(int i, const T& nombre) {
    //insertar(_actual->hijos, i, nombre);
    _actual->hijos.push_back(NULL);
    int j = (int) _actual->hijos.size()-2;
    while (j >= i){
        _actual->hijos[j+1] = _actual->hijos[j];
        j--;
    }
    Nodo* n = new Nodo();
    n->valor = nombre;
    _actual->hijos[i] = n;
}

// Elimina la categoría actual de la taxonomía
// (y todas sus subcategorías).
// Observación: esta operación modifica la taxonomía y
// puede invalidar otros iteradores. Debe encargarse de
// liberar la memoria.
// Pre: el iterador está posicionado sobre una categoría,
// y además !esRaiz().

template <class T>
void eliminar (vector<T>& v, int pos){
    int i = pos + 1;
    while (i < v.size()){
        v[i-1] = v[i];
        i++;
    }
    v.pop_back();
}


template<class T>
void Taxonomia<T>::iterator::_borrar2(Taxonomia<T>::Nodo* nodo) {
    for (int i = 0; i < nodo->hijos.size(); i++) {
        _borrar2(nodo->hijos[i]);
    }
    delete nodo;
}

template<class T>
void Taxonomia<T>::iterator::eliminarCategoria() {
	Nodo* actual = _actual;
    supercategoria();
    int i = 0;
    while (_actual->hijos[i] != actual){
        i++;
    }
    eliminar(_actual->hijos, i);
    _borrar2(actual);
}

