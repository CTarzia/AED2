
template <class T>
Conjunto<T>::Conjunto() {
    _raiz = NULL;
    _tamanio = 0;
}

template <class T>
Conjunto<T>::~Conjunto() {
    vector<Nodo*> v;
    v.push_back(_raiz);
    while(v.size()>0){
        Nodo* x = v.back();
        v.pop_back();
        if (x != NULL){
            v.push_back(x->izq);
            v.push_back(x->der);
            delete x;
        }
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    bool res = false;
    Nodo* n = buscar(_raiz,clave);
    if (n != NULL and n->valor == clave){
            res = true;
        }
    return res;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::buscar(Conjunto<T>::Nodo* n, const T &clave) const{
    if(n == NULL or n->valor == clave) {
        return n;
    } else if (clave < n->valor) {
        if (n->izq == NULL){
            return n;
        } else {
            buscar(n->izq,clave);
        }
    } else if (clave > n->valor) {
        if (n->der == NULL){
            return n;
        } else {
            buscar(n->der,clave);
        }
    }
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)){
        if (_raiz == NULL){
            Nodo* n = new Nodo(clave, NULL);
            _raiz = n;
        } else {
            Nodo *padre = buscar(_raiz, clave);
            Nodo *n = new Nodo(clave, padre);
            if(clave < padre->valor){
                padre->izq = n;
            } else {
                padre->der = n;
            }
        }
        _tamanio++;
    }

}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (pertenece(clave)) {
        Nodo *n = buscar(_raiz, clave);
        if (n->der == NULL and n->izq == NULL) {
            if (n == _raiz) {
                _raiz = NULL;
            } else {
                if (n->padre->der == n) {
                    n->padre->der = NULL;
                } else {
                    n->padre->izq = NULL;
                }
            }
        } else if (n->der != NULL and n->izq != NULL) {
            Nodo *m = maximoN(n->izq);
            if (n == _raiz) {
                _raiz = m;
            }
            if (n == m->padre) {
                reemplazarConIzq(n);
            } else {
                swap(m, n);
                n->padre->der = n->izq;
                if (n->izq != NULL) {
                    n->izq->padre = n->padre;
                }
            }
        } else {
            Nodo *x;
            if (n->izq != NULL) {
                x = n->izq;
            } else {
                x = n->der;
            }
            if (n->padre != NULL) {
                if (n->padre->der == n) {
                    n->padre->der = x;
                } else {
                    n->padre->izq = x;
                }
                x->padre = n->padre;
            } else {
                x->padre = NULL;
                _raiz = x;
            }
        }

        n->der = n->izq = n->padre = NULL;
        delete n;
        _tamanio--;
    }

}

template <class T>
void Conjunto<T>::reemplazarConIzq(Nodo *n) {
    Nodo* reemplazo = n->izq;
    if (n->padre != NULL){
        if(n->padre->der == n){
            n->padre->der = reemplazo;
        } else {
            n->padre->izq = reemplazo;
        }
    }
    reemplazo->padre = n->padre;
    reemplazo->der = n->der;
    reemplazo->der->padre = reemplazo;
}

template <class T>
void Conjunto<T>::swap(Nodo *a, Nodo *b) {
    Nodo* pA = a->padre;
    Nodo* pB = b->padre;
    if(pA != NULL){
        if(pA->der == a) {
            pA->der = b;
        } else {
            pA->izq = b;
        }
    }
    if(pB != NULL){
        if(pB->der == b) {
            pB->der = a;
        } else {
            pB->izq = a;
        }
    }
    if (a->izq != NULL){
        a->izq->padre = b;
    }
    if (a->der != NULL){
        a->der->padre = b;
    }
    if (b->izq != NULL){
        b->izq->padre = a;
    }
    if (b->der != NULL){
        b->der->padre = a;
    }

    Nodo* izq = b->izq;
    Nodo* der = b->der;

    b->izq = a->izq;
    b->der = a->der;
    b->padre = pA;

    a->izq = izq;
    a->der = der;
    a->padre = pB;

}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::maximoN(Conjunto<T>::Nodo* n)const {
    if(n != NULL){
        while (n->der != NULL){
            n = n->der;
        }
    }
    return n;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::minimoN(Conjunto<T>::Nodo* n) const{
    if(n != NULL){
        while (n->izq != NULL){
            n = n->izq;
        }
    }
    return n;
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) const{
    Nodo* x = buscar(_raiz, clave);
    if (x->der != NULL){
        return  minimoN(x->der)->valor;
    } else {
        Nodo* y = x->padre;
        while (y != NULL and x == y->der){
            x = y;
            y = y->padre;
        }
        return y->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    return minimoN(_raiz)->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return maximoN(_raiz)->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return (unsigned int)_tamanio;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream& os) const {
    os << "[";
    T i = minimo();
    while (i != maximo()){
        os << i << " ,";
        i = siguiente(i);
    }
    os << i << "]";
}

