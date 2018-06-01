//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
  if (anio % 4 == 0 and anio % 100 != 0) return true;
  else if (anio % 400 == 0) return true;
  else return false;
}

// Ejercicio 2: diasEnMes
int diasEnMes (Anio anio, Mes mes){
  int res;
  if (mes == FEBRERO){
    if (esBisiesto(anio)) res = 29;
    else res = 28;
  } else if (mes == ABRIL or mes == JUNIO or mes == SEPTIEMBRE or mes == NOVIEMBRE) res = 30;
  else res = 31;
  return res;
}

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  void sumar_periodo(Periodo p);

 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) {
  _dia = dia % diasEnMes(anio, mes);
  _mes = mes % 12;
  _anio = anio;
}

Anio Fecha::anio() const {
  return _anio;
}

Mes Fecha::mes() const {
  return _mes;
}

Dia Fecha::dia() const {
  return _dia;
}

// ej 4


bool Fecha::operator== (Fecha f) const {
  return (_dia == f.dia() and _mes == f.mes() and _anio ==f.anio());
}

bool Fecha::operator< (Fecha f) const {
  bool res;
  if (_anio < f.anio()) res;
  else if (_anio > f.anio()) !res;
  else {
    if (_mes < f.mes()) res;
    else if (_mes > f.mes()) !res;
    else{
      if (_dia < f.dia()) res;
      else !res;
    }
  }
  return res;
}

// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
  if (f1 == f2) return false;
  else return true;
}

// Ejercicio 6: clase período
class Periodo {
public:
    Periodo(int anios, int meses, int dias);
    int anios() const;
    int meses() const;
    int dias() const;

private:
    int _anios;
    int _meses;
    int _dias;
};

Periodo::Periodo(int anios, int meses, int dias) {
  _anios = anios;
  _meses = meses % 12;
  _dias = dias;
}

int Periodo::anios() const {
  return _anios;
}
int Periodo::meses() const {
  return  _meses;
}
int Periodo::dias() const {
  return  _dias;
}

// ej 7

void Fecha::sumar_anios(int anios) {
  _anio += anios;
}

void Fecha::sumar_meses(int meses) {
  _mes += meses;
  if (_mes > 12) {
    _anio ++;
    _mes += -12;
  }
}

void Fecha::sumar_dias(int dias) {
  _dia += dias;
  while (diasEnMes(_anio,_mes)<_dia){
    _dia = _dia - diasEnMes(_anio, _mes);
    sumar_meses(1);
  }
}

void Fecha::sumar_periodo(Periodo p){
  sumar_dias(p.dias());
  sumar_meses(p.meses());
  sumar_anios(p.anios());
}


// Ejercicio 8: clase Intervalo

class Intervalo {
public:
    Intervalo(Fecha desde, Fecha hasta);
    Fecha desde() const;
    Fecha hasta() const;
    int enDias() const;

private:
    Fecha _desde;
    Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde.dia(), desde.mes(), desde.anio()), _hasta(hasta.dia(), hasta.mes(), hasta.anio()){
}

Fecha Intervalo::desde() const {
  return _desde;
}

Fecha Intervalo::hasta() const {
  return _hasta;
}
/*
int Intervalo::enDias() const {
  int res =
}*/