#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__
using namespace std;
#include <vector>

typedef int Clave;
typedef int Valor;


class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	int posicion (Clave k) const;
	vector<Clave> claves() const;
	bool operator==(Diccionario o);
	Diccionario operator|| (Diccionario o);
	Diccionario operator&& (Diccionario o);
	int size();
	
private:
	struct Asociacion{
		Clave clave;
		Valor valor;
	};
	vector<Asociacion> diccionario;x
};

#endif /*__DICCIONARIO_H__*/
