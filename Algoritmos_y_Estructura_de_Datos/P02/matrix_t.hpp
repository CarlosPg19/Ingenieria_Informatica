// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class Matrix_t {
 public:
  Matrix_t(const int = 0, const int = 0);
  ~Matrix_t();
  
  void resize(const int, const int);
  
  // Getters
  int GetM(void) const;
  int GetN(void) const;
  
  // Getters-Setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // Getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // Operaciones y operadores
  void multiply(const Matrix_t<T>&, const Matrix_t<T>&);

  // Metodos E/S
  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:
  int m_, n_; // m_ filas y n_ columnas
  Vector_t<T> v_;
  
  int pos(const int, const int) const;
};

// Implementacion del constructor
template<class T>
Matrix_t<T>::Matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.Resize(m_ * n_);
}

// Implementacion del destructor
template<class T>
Matrix_t<T>::~Matrix_t()
{}

// Implementacion del metodo resize
template<class T>
void Matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.Resize(m_ * n_);
}

// Implementacion Getters
template<class T>
inline int Matrix_t<T>::GetM() const {
  return m_;
}

template<class T>
inline int Matrix_t<T>::GetN() const {
  return n_;
}

// Implementacion metodos y sobrecagas de operadores de acceso
template<class T>
T& Matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= GetM());
  assert(j > 0 && j <= GetN());
  return v_[pos(i, j)];
}

template<class T>
T& Matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template<class T>
const T& Matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= GetM());
  assert(j > 0 && j <= GetN());
  return v_[pos(i, j)];
}

template<class T>
const T& Matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

// Implementacion metodos E/S
template<class T>
void Matrix_t<T>::write(ostream& os) const { 
  os << GetM() << "x" << GetN() << endl;
  for (int i = 1; i <= GetM(); ++i) {
    for (int j = 1; j <= GetN(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

template<class T>
void Matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= GetM(); ++i)
    for (int j = 1; j <= GetN(); ++j)
      is >> at(i, j);
}

// Implementacion del metodo privado pos
template<class T>
inline int Matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= GetM());
  assert(j > 0 && j <= GetN());
  return (i - 1) * GetN() + (j - 1);
}

// FASE III: producto matricial
template<class T>
void Matrix_t<T>::multiply(const Matrix_t<T>& A, const Matrix_t<T>& B) {
  assert(A.GetN() == B.GetM());
  resize(A.GetM(), B.GetN());

  for (int i{1}; i <= A.GetM(); ++i) {
    for (int j{1}; j <= B.GetN(); ++j) {
      at(i,j) = 0;
      for (int k{1}; k <= A.GetN(); ++k) {
        at(i,j) = at(i,j) + A.at(i,k) * B.at(k,j);
      }
    }
  }
}
