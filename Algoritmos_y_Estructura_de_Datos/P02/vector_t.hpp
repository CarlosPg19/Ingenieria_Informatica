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

using namespace std;

template<class T>
class Vector_t {
 public:
  Vector_t(const int = 0);  // Constructor
  ~Vector_t();  // Destructor
  
  void Resize(const int);
  
  // Getters
  T GetValor(const int) const;
  int GetSize(void) const;
  
  // setters
  void SetValor(const int, const T);
  
  // Getters-Setters
  T& at(const int);
  T& operator[](const int);
  
  // Getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // Metodos E/S
  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:
  T *v_;
  int size_;
  
  void build(void);
  void destroy(void);
};


// Implementacion del constructor
template<class T>
Vector_t<T>::Vector_t(const int n) { 
  size_ = n;
  build();
}

// Implementacion del destructor
template<class T>
Vector_t<T>::~Vector_t() {
  destroy();
}

// Implementacion metodo privado build
template<class T>
void Vector_t<T>::build() {
  v_ = NULL;
  if (size_ != 0) {
    v_ = new T[size_];
    assert(v_ != NULL);
  }
}

// Implementacion metodo privado destroy
template<class T>
void Vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  size_ = 0;
}

// Implementacion del metodo Resize
template<class T>
void Vector_t<T>::Resize(const int n) {
  destroy();
  size_ = n;
  build();
}

// Implementacion Getters
template<class T>
inline T Vector_t<T>::GetValor(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T>
inline int Vector_t<T>::GetSize() const {
  return size_;
}

// Implementacion Setters
template<class T>
void Vector_t<T>::SetValor(const int i, const T d) {
  assert(i >= 0 && i < GetSize());
  v_[i] = d;
}

// Implementacion metodos y sobrecarga del operador[] de acceso
template<class T>
T& Vector_t<T>::at(const int i) {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T>
T& Vector_t<T>::operator[](const int i) {
  return at(i);
}

template<class T>
const T& Vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T>
const T& Vector_t<T>::operator[](const int i) const {
  return at(i);
}

// Metodos E/S
template<class T>
void Vector_t<T>::write(ostream& os) const { 
  os << GetSize() << ":\t";
  for (int i = 0; i < GetSize(); i++)
    os << at(i) << "\t";
  os << endl;
}

template<class T>
void Vector_t<T>::read(istream& is) {
  is >> size_;
  Resize(size_);
  for (int i = 0; i < size_; ++i)
    is >> at(i);
}

// FASE II: producto escalar
template<class T>
T scal_prod(const Vector_t<T>& v, const Vector_t<T>& w) {
  assert(v.GetSize() == w.GetSize());
  T suma{0};
  for (int i{0}; i < v.GetSize(); ++i) {
    suma = suma + v.GetValor(i) * w.GetValor(i);
  }
  return suma;
}

double scal_prod(const Vector_t<Rational>& v, const Vector_t<Rational>& w) {
  assert(v.GetSize() == w.GetSize());
  double suma{0.0};
  for (int i{0}; i < v.GetSize(); ++i) {
    suma = suma + v[i].Value() * w[i].Value();
  }
  return suma;
  
}
