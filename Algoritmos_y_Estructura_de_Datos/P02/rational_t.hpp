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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class Rational {
  // pautas de estilos [44] y [73]: primero "public" y después "private"
 public:
  Rational(const int numerador = 0, const int denominador= 1); // Constructor
  ~Rational() {}  // Destructor 
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // Getters
  int numerador() const;
  int denominador() const;
  
  // Setters
  void SetNumerador(const int);
  void SetDenominador(const int);

  // Operaciones (Valor, Opuesto y Reciproco)
  double Value(void) const;
  Rational Opposite(void) const;
  Rational Reciprocal(void) const;

  // Comparaciones boolenas
  bool is_equal(const Rational&, const double precision = EPSILON) const;
  bool is_greater(const Rational&, const double precision = EPSILON) const;
  bool is_less(const Rational&, const double precision = EPSILON) const;

  // Operaciones aritmeticas
  Rational add(const Rational&) const;
  Rational substract(const Rational&) const;
  Rational multiply(const Rational&) const;
  Rational divide(const Rational&) const;

  // Metodos E/S
  void Write(ostream& os = cout) const;
  void Read(istream& is = cin);
  
 private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int numerador_, denominador_;
};


// Sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const Rational&);
istream& operator>>(istream& is, Rational&);

// FASE I: Operadores Aritmeticos
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

