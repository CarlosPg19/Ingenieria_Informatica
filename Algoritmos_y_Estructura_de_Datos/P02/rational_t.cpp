/**
 * AUTOR: Carlos Perez Gomez
 * FECHA: 24/02/2024
 * EMAIL: alu0101564005@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 2
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
 */
// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

Rational::Rational(const int numerador, const int denominador) : 
                  numerador_{numerador}, denominador_{denominador} {
  assert(denominador != 0);
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método

// Implementacion de Getters
inline int Rational::numerador() const {
  return numerador_;
}

inline int Rational::denominador() const {
  return denominador_;
}

// Implementacion de Setters  
void Rational::SetNumerador(const int numerador) {
  numerador_ = numerador;
}
  
void Rational::SetDenominador(const int denominador) {
  assert(denominador != 0);
  denominador_ = denominador;
}

// Implementacion para devolver el valor de la fraccion
inline double Rational::Value() const { 
  return static_cast<double>(numerador()) / denominador();
}

// Implementacion del opuesto
Rational Rational::Opposite() const { 
  return Rational((-1) * numerador(), denominador());
}

// Implementacion del reciproco
Rational Rational::Reciprocal() const { 
  return Rational(denominador(), numerador());
}

// Comparaciones booleanas
bool Rational::is_equal(const Rational& r, const double precision) const { 
  return fabs(Value() - r.Value()) < precision;
}

bool Rational::is_greater(const Rational& r, const double precision) const {
  return (Value() - r.Value()) > precision;
}

bool Rational::is_less(const Rational& r, const double precision) const {
  return r.is_greater(*this, precision);
}


// Operaciones aritmeticas
Rational Rational::add(const Rational& r) const {
  return Rational(numerador() * r.denominador() + denominador() * r.numerador(), 
                    denominador() * r.denominador());
}

Rational Rational::substract(const Rational& r) const {
  return add(r.Opposite());
}

Rational Rational::multiply(const Rational& r) const {
  return Rational(numerador() * r.numerador(), denominador() * r.denominador());
}

Rational Rational::divide(const Rational& r) const {
  return multiply(r.Reciprocal());
}

// FASE I: Sobrecarga de operadores
Rational operator+(const Rational& a, const Rational& b) {
  return Rational(a.numerador() * b.denominador() + a.denominador() * b.numerador(), 
                    a.denominador() * b.denominador());
}

Rational operator-(const Rational& a, const Rational& b) {
  return Rational(a.numerador() * b.denominador() - a.denominador() * b.numerador(), 
                    a.denominador() * b.denominador());
  
}

Rational operator*(const Rational& a, const Rational& b) {
  return Rational(a.numerador() * b.numerador(), 
                  a.denominador() * b.denominador());
}

Rational operator/(const Rational& a, const Rational& b) {
  return Rational(a.numerador() * b.denominador(), 
                  a.denominador() * b.numerador());
}

// E/S
void Rational::Write(ostream& os) const {
  os << numerador() << "/" << denominador() << "=" << Value() << endl;
}

void Rational::Read(istream& is) {
  is >> numerador_ >> denominador_;
  assert(denominador_ != 0);
}

// Sobrecarga operadores E/S
ostream& operator<<(ostream& os, const Rational& r) {
  r.Write(os);
  return os;
}


istream& operator>>(istream& is, Rational& r) {
  r.Read(is);
  return is;
}