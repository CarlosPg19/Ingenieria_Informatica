// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: clase TAD cola implementada con un vector circular

#pragma once

#include <iostream>
#include <cassert>

#include "round_vector_t.h"

const unsigned char MAX_STACK_SIZE = 20;

using namespace std;

template <class T>
class queue_v_t
{
public:
  // constructor, constructor por defecto y destructor
	queue_v_t(const int);
	queue_v_t(void);
	~queue_v_t(void);

	bool empty(void) const;
	bool full(void) const;
	int size(void) const;
	
	void push(const T& dato);
	void pop(void);
	const T& front(void) const;
	const T& back(void) const;

	void write(ostream& os = cout) const;

  // PA problemas 08/04
  void MoveTwoFirstToEnd();
  void Duplicate();
  queue_v_t<T> queue_v_t<T>::EraseOdds();
  void MoveToTwoTails(double numero, queue_v_t<T>& cola_menor, queue_v_t<T>& cola_mayor);
  void Maximo();
	
private:
	round_vector_t<T> v_;
	int         		  front_;
	int       				back_;
};

// PA problemas 08/04
template<class T>
void queue_v_t<T>::MoveTwoFirstToEnd() {
  T aux1 = front();
  pop();
  T aux2 = front();
  pop();
  push(aux2);
  push(aux1);
}

template<class T>
void queue_v_t<T>::Duplicate() {
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
queue_v_t<T> queue_v_t<T>::EraseOdds() {
  queue_v_t<T> nueva_cola;
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
void queue_v_t<T>::MoveToTwoTails(double numero, queue_v_t<T>& cola_menor, queue_v_t<T>& cola_mayor) {
  while(!empty()) {
    if (front() < numero) {
      cola_menor.push(front());
    }
    else {
      cola_mayor.push(front);
    }
    pop();
  }
}

template<class T>  
void queue_v_t<T>::Maximo() {
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

template<class T>
queue_v_t<T>::queue_v_t(const int max_sz):
v_(max_sz),
front_(0),
back_(-1)
{}

template<class T>
queue_v_t<T>::queue_v_t(void):
v_(MAX_STACK_SIZE),
front_(0),
back_(-1)
{}

template<class T>
queue_v_t<T>::~queue_v_t(void)
{}

template<class T>
bool
queue_v_t<T>::empty(void) const
{
	return (back_ < front_);
}

template<class T>
bool
queue_v_t<T>::full(void) const
{
	return (size() >= v_.get_size() - 1);
}

template<class T>
int
queue_v_t<T>::size(void) const
{
 	return back_ - front_ + 1;
}

template<class T>
void
queue_v_t<T>::push(const T& dato)
{
	assert(!full());
	back_++;
	v_.at(back_) = dato;
}

template<class T>
void
queue_v_t<T>::pop(void)
{
	assert(!empty());			
	front_++;
}

template<class T>
const T&
queue_v_t<T>::front(void) const
{
	assert(!empty());
	return v_.at(front_);
}

template<class T>
const T&
queue_v_t<T>::back(void) const
{
	assert(!empty());
	return v_.at(back_);
}

template<class T>
void
queue_v_t<T>::write(ostream& os) const
{
	for(int i = back_; i >= front_; i--)
		os << v_.at(i) << " ";  
	os << endl;
}

template<class T>
ostream&
operator<<(ostream& os, const queue_v_t<T>& q)
{
	q.write(os);
	return os;
}

