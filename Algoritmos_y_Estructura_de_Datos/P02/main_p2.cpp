// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main() {
  Rational a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).Write();

  cout << "b - a: ";
  (b-a).Write();

  cout << "a * b: ";
  (a*b).Write();
  
  cout << "a / b: ";
  (a/b).Write();
  
  cout << endl;
  
  // FASE II
  Vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  Vector_t<Rational> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<Rational>: " << scal_prod(x, y) << endl << endl;
  
  
  // FASE III
  Matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();
  
  return 0;
}