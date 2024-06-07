// AUTOR: Carlos Perez Gomez 
// FECHA: 12/04/2024
// EMAIL: alu0101564005@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> 
class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

  // Ejercicio clase
  const int n_op(const char c) {return GetNumOp(c);};
  int GetNumOp(const char c) const;

 private: 
  T stack_;
  void operate_(const char operador);
};

// Ejercicio clase
template <class T>
int rpn_t<T>::GetNumOp(const char c) const {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || 
         c == '^' || c == 'r' || c == 'l' || c == 'c');
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return 2;
      break;

    case 'l':
    case 'r':
    case 'c':
      return 1;
      break;

  }
}

// operaciones
template<class T> 
const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } 
    else {
      std::cout << " (es un operador)" << std::endl;
      // poner código
      operate_(c);
    }
  }
  // poner código
  return stack_.top();
}

template<class T> 
void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || 
         c == '^' || c == 'r' || c == 'l' || c == 'c');

  // poner código
  int b = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << b << std::endl;
  
  int a;
  if (n_op(c) == 2) {
    // poner código
    a = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << a << std::endl;
  }

  switch (c) {
    case '+':
      // poner código
      stack_.push(a + b);
      break;

    // poner código resto de operadores
    case '-':
      // poner código
      stack_.push(a - b);
      break;

    case '*':
      // poner código
      stack_.push(a * b);
      break;

    case '/':
      // poner código
      stack_.push(a / b);
      break;

    case '^':
      // poner código
      stack_.push(pow(a,b));
      break;

    case 'r':
      // poner código
      stack_.push(sqrt(b));
      break;

    case 'l':
      // poner código
      stack_.push(log2(b));
      break;

    case 'c':
      // poner código
      stack_.push(b * b);
      break;
  }

  // poner código
  std::cout << "   Metemos en la pila el resultado: "<< stack_.top() << std::endl;
}

 
#endif  // RPNT_H_
