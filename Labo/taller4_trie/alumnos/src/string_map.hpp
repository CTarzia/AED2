
template <typename T>
string_map<T>::string_map(){
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    _size = d._size;
    _raiz = d._raiz;
}

template <typename T>
string_map<T>::~string_map(){
    if(_raiz != NULL) {
        borraHijos(_raiz);
        delete _raiz;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if(_size == 0){
        _raiz = new Nodo(NULL ,NULL);
    }
    return buscameEsta(clave, _raiz);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    int res = 0;
    if (laDefini(clave, 0, _raiz)) res++;
    return res;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return at(clave);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return buscameEsta(clave, _raiz);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* n = buscamePuntero(clave, 0, _raiz);
    if(n->siguientes == NULL){
        while(!hermanosTienenHijos(n)){
            n = n->padre;
            borraHijos(n);
        }
    } else {
        n->definicion = NULL;
        if(_size == 1){
            borraHijos(_raiz);
            delete _raiz;
            _raiz = NULL;
        }
    }
    _size --;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template <typename T>
void string_map<T>::borraHijos(string_map::Nodo *d) {
    if(d->siguientes != NULL){
        for (int i = 0; i < 256; ++i) {
            borraHijos(d->siguientes[i]);
        }
    }
}

template <typename T>
T& string_map<T>::buscameEsta(const string &clave, string_map::Nodo *d) {
    if (count(clave) == 0) _size++;
    return *buscamePuntero(clave,0, d)->definicion;
}

template <typename T>
typename string_map<T>::Nodo *string_map<T>::buscamePuntero(const string &clave, int pos, string_map::Nodo* d) {
    if(clave.size()-1 < pos){
        return d;
    } else if(d->siguientes == NULL){
        d->siguientes = new Nodo*[256];
        for (int i = 0; i < 256; ++i) {
            d->siguientes[i] = new Nodo(d, NULL);
        }
        return buscamePuntero(clave, pos+1, d->siguientes[(char)clave[pos]]);
    }
}

template <typename T>
bool string_map<T>::laDefini(const string &clave, int pos, string_map::Nodo *d) const {
    if(_size == 0) return false;
    else if(clave.size()-1 < pos and d->definicion != NULL){
        return true;
    } else if (d->siguientes == NULL){
        return false;
    } else {
        return laDefini(clave, pos+1, d->siguientes[(char)clave[pos]]);
    }
}

template <typename T>
bool string_map<T>::hermanosTienenHijos(string_map::Nodo *d) {
    Nodo* p = d->padre;
    bool res = false;
    Nodo* q;
    for (int i = 0; i < 256 and !res; ++i) {
        q = p->siguientes[i];
        if(q != d and q->siguientes != NULL){
            res = true;
        }
    }
    return res;
}







