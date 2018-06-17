
template <typename T>
string_map<T>::string_map(){
    _size = 0;
    _raiz = NULL;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    if (_raiz != NULL) {
        delete _raiz;
    }
    _size = d._size;
    if (d._raiz != NULL) {
        if(d._raiz->definicion != NULL) {
            _raiz = new Nodo(NULL, d._raiz->definicion);
        } else {
            _raiz = new Nodo(NULL);
        }
        copiaHijos(d._raiz, _raiz);
    }
}

template <typename T>
string_map<T>::Nodo::~Nodo() {
    delete this->definicion;
    this->definicion = NULL;
    if (this->siguientes != NULL) {
        for (int i = 0; i < 256; ++i) {
            if (this->siguientes[i] != NULL) {
                delete this->siguientes[i];
                this->siguientes[i] = NULL;
            }
        }
    }
    delete [] this->siguientes;
    this->siguientes = NULL;
    this->padre = NULL;
    /*if (this != NULL) {
        this->padre = NULL;
        if (this->siguientes != NULL) {
            for (int i = 0; i < 256; ++i) {
                if (this->siguientes[i] != NULL) {
                    delete this->siguientes[i];
                    this->siguientes[i] = NULL;
                }
            }
            delete [] this->siguientes;
            this->siguientes = NULL;
        }
        if (this->definicion != NULL) {
            delete this->definicion;
            this->definicion = NULL;
        }
    }*/
}

template <typename T>
string_map<T>::~string_map(){
    if (this != NULL and _raiz != NULL) {
        _size = 0;
        delete _raiz;
        _raiz = NULL;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if(_size == 0){
        _raiz = new Nodo(NULL);
    }
    return buscameEsta(clave, _raiz);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    int res = 0;
    if (laDefini(clave, _raiz)) res++;
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
    if(_size == 1){
        delete _raiz;
        _raiz = NULL;
    } else {
        Nodo *n = buscamePuntero(clave, _raiz);
        delete n->definicion;
        n->definicion = NULL;
        if (n->siguientes == NULL) {
            while (!hermanosTienenHijos(n)) {
                n = n->padre;
            }
            Nodo* m = n->padre;
            int pos;
            for (int i = 0; i < 256; ++i) {
                if(m->siguientes[i]==n) {
                    pos = i;
                }
            }
            m->siguientes[pos] = NULL;
            delete n;

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
T& string_map<T>::buscameEsta(const string &clave, string_map::Nodo *d) {
    if (count(clave) == 0) _size++;
    Nodo* n = buscamePuntero(clave, d);
    if(n->definicion == NULL) {
        n->definicion = new T;
    }
    return *n->definicion;
}

template <typename T>
typename string_map<T>::Nodo *string_map<T>::buscamePuntero(const string &clave, string_map::Nodo* d) {
    Nodo* n = d;
    for (int j = 0; j < clave.size(); ++j) {
        if(n->siguientes == NULL) {
            n->siguientes = new Nodo *[256];
            for (int i = 0; i < 256; ++i) {
                n->siguientes[i] = new Nodo(n);
            }
        }
        n = n->siguientes[(char)clave[j]];
    }
    return n;
}

template <typename T>
bool string_map<T>::laDefini(const string &clave, string_map::Nodo *d) const {
    //bool res = false;
    if(_size != 0) {
        Nodo* n = d;
        //bool salir = false;
        for (int i = 0; i <= clave.size(); ++i) {
            if (n == NULL){
                return false;
            } else if (i == clave.size() and n->definicion != NULL) {
                //res = true;
                //salir = true;
                return true;
            } else if (n->siguientes == NULL) {
                return false;
            } else if (i < clave.size()){
                n = n->siguientes[(char)clave[i]];
            }
        }
    }
    return false;
    //return res;
}

template <typename T>
bool string_map<T>::hermanosTienenHijos(string_map::Nodo *d) {
    Nodo* p = d->padre;
    bool res = false;
    Nodo* q;
    if (p->siguientes != NULL) {
        for (int i = 0; i < 256 and !res; ++i) {
            q = p->siguientes[i];
            if (q != d and (q->siguientes != NULL or q->definicion != NULL)) {
                res = true;
            }
        }
    }
    return res;
}

template <typename T>
void string_map<T>::copiaHijos(string_map<T>::Nodo *desde, string_map<T>::Nodo *hacia) {
    if (desde != NULL) {
        if (desde->siguientes != NULL) {
            hacia->siguientes = new Nodo *[256];
            for (int i = 0; i < 256; ++i) {
                if (desde->siguientes[i] != NULL) {
                    if (desde->siguientes[i]->definicion != NULL){
                        hacia->siguientes[i] = new Nodo(hacia, desde->siguientes[i]->definicion);
                    } else {
                        hacia->siguientes[i] = new Nodo(hacia);
                    }
                    copiaHijos(desde->siguientes[i], hacia->siguientes[i]);
                }
            }
        }
    }
}









