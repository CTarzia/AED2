#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
template<class T>
T cuadrado(T x) {
    return x * x;
}

// Ejercicio 2: Pasar a templates
template <class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template <class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
  if (a.size() >= b.size) return false;
  bool res = true;
  for (int i = 0; i < a.size() and res; ++i) {
    if (a[i] != b[i]) res = false;
  }
  return res;
}

// Ejercicio 4: Función maximo con un template contenedor y uno elemento

template <class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem res = c[0];
    for (int i = 1; i < c.size(); ++i) {
        if (res<c[i]) res = c[i];
    }
    return res;
}

#endif