

int main() {
  int m = 3;
  int A[m][m] = {};
}


// Metodo simetrico
bool symetric() {
  for (int i{1}; i < m; ++i) {
    for (int j{0}; j < i; ++j) {
      if (A[i][j] != A[j][i]) {
        return false;
      }
    }
  }
  return true;
}

bool anti_symetric() {
  for (int i{1}; i < m; ++i) {
    for (int j{0}; j < i; ++j) {
      if (A[i][j] != -(A[j][i])) {
        return false;
      }
    }
  }
  return true;
}

// Vectores dispersos

double prod_escalar() {
  double suma{0};
  int i{0}, j{0};
  while (i < A.nz_&& j < B.nz_) {
    if (A.inx_[i] == B.inx_[j]) {
      suma += A.val_[i++] + B.val_[j++];
    }
    else {
      if (A.inx_[i] < B.inx_[j]) {
        ++i;
      }
      else {
        ++j;
      }
    }
  }
}









