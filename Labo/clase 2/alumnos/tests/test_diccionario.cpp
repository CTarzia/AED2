#include "gtest/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

TEST(diccionario, ej5_seBorro){
	Diccionario d;
	d.definir(4,6);
	d.borrar(4);
	ASSERT_EQ (d.def(4), false);
}

TEST(diccionario,ej5_lasDemasExisten){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	d.borrar(4);
	ASSERT_EQ(d.def(3),true);
	ASSERT_EQ(d.obtener(3), 7);
}

TEST(diccionario, ej5_noModifico){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	d.borrar(8);
	ASSERT_EQ(d.obtener(4), 6);
	ASSERT_EQ(d.obtener(3), 7);
}


#endif

#if EJ >= 6

int apariciones (vector<int> v, int n){
	int res = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == n) res++;
	}
	return res;
}

bool esPermutacion(vector<Clave> v1, vector<Clave> v2){
	bool res = true;
	if(v1.size()!=v2.size()) res = false;
	else{
		for (int i = 0; i < res and v1.size(); ++i) {
			if(apariciones(v1, v1[i])!= apariciones(v2, v1[i])) res = false;
		}
	}
	return res;
}

TEST(diccionario, ej6_desordenadas){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	Diccionario d2;
	d2.definir(3,7);
	d2.definir(4,6);
	ASSERT_EQ(esPermutacion(d.claves(),d2.claves()), true);
}

TEST(diccionario, ej6_true){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	vector<int> t;
	t.push_back(4);
	t.push_back(3);
	ASSERT_EQ(esPermutacion(d.claves(),t), true);
}

TEST(diccionario, ej6_false){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	vector<int> t;
	t.push_back(4);
	t.push_back(3);
	t.push_back(6);
	ASSERT_EQ(esPermutacion(d.claves(),t), false);
}

#endif

#if EJ >= 7
TEST(diccionario, ej7_desordenadas){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	Diccionario d2;
	d2.definir(3,7);
	d2.definir(4,6);
	ASSERT_EQ(d==d2, true);
}

TEST(diccionario, ej7_false){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	Diccionario d2;
	d2.definir(6,7);
	d2.definir(4,6);
	ASSERT_EQ(d==d2, false);
}

TEST(diccionario, ej7_unaDeMas){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	d.definir(6,8);
	Diccionario d2;
	d2.definir(3,7);
	d2.definir(4,6);
	ASSERT_EQ(d==d2, false);
}

TEST(diccionario, ej7_unaDeMasAlReves){
	Diccionario d;
	d.definir(4,6);
	d.definir(3,7);
	Diccionario d2;
	d2.definir(3,7);
	d2.definir(4,6);
	d2.definir(6,8);
	ASSERT_EQ(d==d2, false);
}

#endif

#if EJ >= 8

#endif

