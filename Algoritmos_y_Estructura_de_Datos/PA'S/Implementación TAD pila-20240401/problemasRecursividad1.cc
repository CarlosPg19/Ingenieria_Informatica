// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: programa de prueba de recursividad
// Se compila con:
// g++ problemasrecursividad1.cc -o problemasrecursividad1

#include "iostream"
#include "cmath"

using namespace std;

unsigned int digits(const unsigned int);						// PROTOTIPOS
unsigned int sum(const unsigned int);
unsigned int bin(const unsigned int);
unsigned int collatz(const unsigned int);

int main(void)
{
	// setlocale(LC_ALL, "");

	// 1. Calcular el número de dígitos de un número entero positivo.
	unsigned int number = 15;
    cout << number << endl;
	cout << "El numero de digitos de " << number << " es de... " << digits(number) << std::endl;

	// 2. Sumar los digitos de un numero entero positivo.
	cout << "La suma de los digitos de " << number << " es de... " << sum(number) << std::endl;

	// 3. Calcular la codificación binaria de un número entero positivo.
	// Devolver el resultado como un valor entero pseudo-binario (19 -> 10011 - diez mil once).
	cout << "La codificacion binaria de " << number << " es... " << bin(number) << std::endl;

	// 4. Conjetura de Collatz: Si se aplica la función f(n) = n/2 si n es par y 3n + 1 si n es impar, 
	// se produce una secuencia de números que siempre termina en 1 (a partir de encontes se repiten 4 2 1 periodicamente).
	// Se pretende calcular la longitud de la secuencia hasta la aparición del primer 1, dado un entero positivo.
	// Ejemplo: Collatz(13) tiene 10 elementos (13, 40, 20, 10, 5, 16, 8, 4, 2, 1).
	cout << "El numero de elementos de la secuencia de Collatz de " << number << " es... " << collatz(number) << std::endl;

	return 0;
}

unsigned int digits(const unsigned int number) { 
	return number > 0 ? 1 + digits(floor(number / 10)) : 0; 
}

unsigned int sum(const unsigned int number) {
	return number > 0 ? (number % 10) + sum(floor(number / 10)) : 0;
}

unsigned int bin(const unsigned int number) {
	return number > 1 ? (bin(floor(number / 2)) * 10) + (number % 2) : number;
}

unsigned int collatz(const unsigned int number) {
	if (number == 1) return 1;
	else return number % 2 == 0? 1 + collatz(number / 2) : 1 + collatz(3*number + 1);			
}



