/**
 * AUTOR: Carlos Perez Gomez
 * FECHA: 9/02/2024
 * EMAIL: alu0101564005@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 1
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
 */

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <cmath>
#include "rational_t.hpp"

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
int Rational::numerador() const {  // Definicion del getter numerador
  return numerador_;  
}

int Rational::denominador() const {  // Definicion del getter denominador
  return denominador_;
}

void Rational::SetNumerador(const int numerador) {  // Definicion del setter numerador
  numerador_ = numerador;
}

void Rational::SetDenominador(const int denominador) {  // Definicion del setter denominador 
  assert(denominador != 0);
  denominador_ = denominador;
}

double Rational::Value() const {  // Definicion del metodo Value
  return static_cast<double>(numerador()) / static_cast<double>(denominador());
}


// Definicion de comparaciones booleanas
bool Rational::is_equal(const Rational& numero, const double precision) const {
  return fabs(Value() - numero.Value()) < precision;  // Comprobar si dos numeors son  iguales
}

bool Rational::is_greater(const Rational& numero, const double precision) const {
  return Value() - numero.Value() > precision;  // Comprobar si un numero es mayor que otro
}

bool Rational::is_less(const Rational& numero, const double precision) const {
  return numero.Value() - Value() > precision;  // Comprobar si un numero es menor que otro
}


// Definicion de operaciones arritmeticas
Rational Rational::add(const Rational& numero) {
  return Rational(numerador() * numero.denominador() + numero.numerador() * denominador(), 
                  denominador() * numero.denominador());  // Sumar dos numeros 
}

Rational Rational::substract(const Rational& numero) {
  return Rational(numerador() * numero.denominador() - denominador() * numero.numerador(),
                  denominador() * numero.denominador());  // Restar dos numeros
}

Rational Rational::multiply(const Rational& numero) {
  return Rational(numerador() * numero.numerador(),
                  denominador() * numero.denominador());  // Multiplicar dos numeros
}

Rational Rational::divide(const Rational& numero) {
  return Rational(numerador() * numero.denominador(),
                  denominador() * numero.numerador());  // Dividir dos numeros
}

// Ejercicio clase implementacion
Rational Rational::RaizDenominador() {
  cout << numerador() << "/√" << denominador() << " = "
       << numerador() / sqrt(denominador()) << endl;
  return Rational{numerador(), sqrt(denominador())};
}

// Definicion de funciones de E/S
void Rational::Write(ostream& os) const {  // Escribir un numero por pantalla
  os << numerador() << "/" << denominador() << "=" << Value() << endl;
}

void Rational::Read(istream& is) {  // Leer un numero por pantalla
  cout << "Numerador? ";
  is >> numerador_;
  cout << "Denominador? ";
  is >> denominador_;
  assert(denominador_ != 0);
}
