// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
  // PA problemas 08/04
  void MoveTwoFirstToEnd();
  void Duplicate();
  queue_l_t<T> EraseOdds();
  void MoveToTwoTails(double numero, queue_l_t<T>& cola_menor, queue_l_t<T>& cola_mayor);
  void queue_l_t<T>::Maximo();
};

// PA problemas 08/04
template<class T>
void queue_l_t<T>::MoveTwoFirstToEnd() {
  T aux1 = front();
  pop();
  T aux2 = front();
  pop();
  push(aux2);
  push(aux1);
}

template<class T>
void queue_l_t<T>::Duplicate() {
  T aux;
  int cont{0};
  int size = size();
  while(cont < size) {
    aux = front();
    pop();
    push(aux);
    push(aux);
    ++cont;
  }
}

template<class T>  
queue_l_t<T> queue_l_t<T>::EraseOdds() {
  queue_l_t<T> nueva_cola;
  while (!empty()) {
    pop();
    if (!empty()) {
      nueva_cola.push(front());
      pop();
    }
  return nueva_cola;
  }
}

template<class T>
void queue_l_t<T>::MoveToTwoTails(double numero, queue_l_t<T>& cola_menor, queue_l_t<T>& cola_mayor) {
  while(!empty()) {
    if (front() < numero) {
      cola_menor.push(front());
      pop();
    }
    else {
      cola_mayor.push(front);
      pop();
    }
  }
}

template<class T>  
void queue_l_t<T>::Maximo() {
  assert(!empty());
  T aux1, aux2;
  while (size() != 1) {
    aux1 = front();
    pop();
    aux2 = front();
    pop();
    if (aux1 < aux2) {
      push(aux2);
    }
    else {
      push(aux1);
    }
  }
}

// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}


#endif  // QUEUE_H_
