#include "matriz.h"
#include <cstring>
#include <math.h>

template <typename T> MatrizQuadrada<T>::MatrizQuadrada(int ordem) {
  this->n = ordem;
  this->vetor = new T[static_cast<size_t>(std::pow(this->n, 2))];
  std::memset(vetor, 0, static_cast<size_t>(std::pow(this->n, 2)) * sizeof(T));
}

template <typename T> MatrizQuadrada<T>::MatrizQuadrada(int ordem, int tipo) {
  this->tipo = tipo;
  this->n = ordem;
  this->vetor = new T[static_cast<size_t>(std::pow(this->n, 2))];
  std::memset(vetor, 0, static_cast<size_t>(std::pow(this->n, 2)) * sizeof(T));
}

template <typename T> MatrizQuadrada<T>::~MatrizQuadrada() { delete[] vetor; }

template <typename T> int MatrizQuadrada<T>::getOrdem() { return n; }

template <typename T> int MatrizQuadrada<T>::getTipo() { return tipo; }

template <typename T> T MatrizQuadrada<T>::get(int i, int j) const {
  if (tipo == MATRIZ_GENERICA)
    return vetor[this->n * i + j];
  else if (tipo == MATRIZ_IDENTIDADE) {
    return (i == j) ? 1 : 0;
  } else if (tipo == MATRIZ_TRIANGULAR_SUPERIOR) {
    if (i > j)
      return 0;
    int aux = i * this->n + j - ((i + 1) * i) / 2;
    return vetor[aux];
  } else {
    if (i < j)
      return 0;
    int aux = i * this->n + j - ((2 * this->n - 2 + (i - 1) * (-1)) * i) / 2;
    return vetor[aux];
  }
  return 0;
}

template <typename T> void MatrizQuadrada<T>::set(int i, int j, T value) {
  if (tipo == MATRIZ_GENERICA) {
    int aux = i * this->n + j;
    vetor[aux] = value;
  } else if (tipo == MATRIZ_IDENTIDADE) {
    return;
  } else if (tipo == MATRIZ_TRIANGULAR_SUPERIOR) {
    if (i > j)
      return;
    int aux = i * this->n + j - ((i + 1) * i) / 2;
    vetor[aux] = value;
  } else if (tipo == MATRIZ_TRIANGULAR_INFERIOR) {
    if (i < j)
      return;
    int aux = i * this->n + j - ((2 * n - 2 + (i - 1) * (-1)) * i) / 2;
    vetor[aux] = value;
  }
}

template <typename T>
MatrizQuadrada<T> MatrizQuadrada<T>::soma(const MatrizQuadrada<T> &B) {
  MatrizQuadrada<T> C(this->n, MATRIZ_GENERICA);

  for (int i = 0; i < this->n; ++i) {
    for (int j = 0; j < this->n; ++j) {
      C.set(i, j, this->get(i, j) + B.get(i, j));
    }
  }

  return C;
}

template <typename T>
MatrizQuadrada<T> MatrizQuadrada<T>::multiplicacao(const MatrizQuadrada<T> &B) {
  MatrizQuadrada<T> C(this->n, MATRIZ_GENERICA);

  for (int i = 0; i < this->n; i++) {
    for (int j = 0; j < this->n; j++) {
      for (int m = 0; m < this->n; m++) {
        C.set(i, j, C.get(i, j) + this->get(i, m) * B.get(m, j));
      }
    }
  }

  return C;
}

template <typename T> void MatrizQuadrada<T>::multiplicacaoPorEscalar(T alpha) {
  for (int i = 0; i < this->n; ++i) {
    for (int j = 0; j < this->n; ++j) {
      this->set(i, j, this->get(i, j) * alpha);
    }
  }
}
