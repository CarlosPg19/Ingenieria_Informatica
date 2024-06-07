#include <iostream>
#include <cmath>

int main() {
  int n = 10;
  int A[n] = {5, 3, 2 ,1, 5, 1, 4, 2, 1 ,6};
  int* B;
  B = new int[n];
  int* C;
  C = new int[n];
  int multiplo{0}, nomultiplo{0};
  int sumamult{0}, sumanomult{0};
  double modulo{0};
  for (int i{0}; i < n; ++i) {
      if (A[i] % 3 == 0) {
        B[multiplo] = i;
        sumamult += A[i];
        ++multiplo;
      }
      else {
        C[nomultiplo] = A[i];
        sumanomult += A[i];
        modulo += A[i] * A[i];
        ++nomultiplo;
      }
  }
  std::cout << " suma multiplos: " << sumamult << " no multplos suma: " << sumanomult << std::endl;
  std::cout << std::sqrt(modulo) << std::endl;
  double eee{0};
  for (int i{0}; i < n; ++i) {
    eee += C[i] * C[i];
  }
  std::cout << eee << std::endl;
  delete[] C;
  C = NULL;
  delete[] B;
  B = NULL;

}