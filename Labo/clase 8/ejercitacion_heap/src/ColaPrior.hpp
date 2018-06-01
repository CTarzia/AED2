
template<class T>
ColaPrior<T>::ColaPrior() {
	vector<T> heap;
    v = heap;
    //_tam = 0;
    //_ultimo = 0;
}

template<class T>
int ColaPrior<T>::tam() const {
	return v.size();
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	v.push_back(elem);
    siftUp(v.size()-1);

}

template<class T>
const T& ColaPrior<T>::proximo() const {
	return v[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	swap(0,v.size()-1);
    v.pop_back();
    siftDown(0);
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
	v = elems;
    for (int i = posPadre(v.size()-1) ; i >= 0 ; i--) {
        siftDown(i);
    }
}

template<class T>
int ColaPrior<T>::posPadre(int i) {
    return (i-1)/2;
}

template<class T>
int ColaPrior<T>::posIzq(int i) {
    return 2*i+1;
}

template<class T>
int ColaPrior<T>::posDer(int i) {
    return 2*i+2;
}

template <class T>
int ColaPrior<T>::hijoMax(int pos) {
    int hm;
    if (posDer(pos) > v.size()-1 or v[posIzq(pos)] > v[posDer(pos)]) hm = posIzq(pos);
    else hm = posDer(pos);
    return hm;
}

template<class T>
void ColaPrior<T>::siftDown(int pos) {
    if(!esHoja(pos)){
        int m = hijoMax(pos);
        if(v[m] > v[pos]) {
            swap(pos,m);
            return siftDown(m);
        }
    }
}

template<class T>
void ColaPrior<T>::siftUp(int pos) {
    if(pos != 0 and v[pos] > v[posPadre(pos)]){
        swap(pos,posPadre(pos));
        return siftUp(posPadre(pos));
    }
}

template<class T>
void ColaPrior<T>::swap(int a, int b) {
    T save = v[a];
    v[a] = v[b];
    v[b] = save;
}

template<class T>
bool ColaPrior<T>::esHoja(int pos) {
    if(v.size() == 1) return true;
    int ultimaRama = posPadre(v.size()-1);
    return pos > ultimaRama;
}