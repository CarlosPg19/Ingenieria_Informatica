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
  Rational(int numerador = 0, int denominador = 1) :  // Constructor con lista de inicializacion
          numerador_{numerador}, denominador_{denominador} {  // y assert paa evitar denominador = 0
    assert(denominador != 0);
  }
  
  ~Rational() {}  // Destructor de la clase
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int numerador() const;  // Getters para acceder a los valores de los atributos
  int denominador() const;
  
  // setters
  void SetNumerador(const int);  // Setters para cambiar los valores de los atributos 
  void SetDenominador(const int);

  double Value() const; // Devuelve el valor de la fraccion en decimal

  // FASE II
  bool is_equal(const Rational&, const double precision = EPSILON) const;  // Declaracion de operaciones booleanas
  bool is_greater(const Rational&, const double precision = EPSILON) const;  // (igual (==), mayor que(>) y menor que (<))
  bool is_less(const Rational&, const double precision = EPSILON) const;
  
  // FASE III
  Rational add(const Rational&);
  Rational substract(const Rational&);  // Declaracion de operaciones aritmeticas
  Rational multiply(const Rational&);  // (suma, resta, multiplicacion y division)
  Rational divide(const Rational&);
  
  void Write(ostream& = cout) const;  // Metodo para escribir un numero por pantalla
  void Read(istream& = cin);   // Metodo para leer un numero por pantalla
  
  // Ejercicio calse
  Rational RaizDenominador();
  
 private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int numerador_;
  int denominador_;  // Atributos privados de la clase Rational
};
