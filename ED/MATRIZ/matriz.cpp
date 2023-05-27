#include "matriz.h"
#include <math.h>
#include <string.h>

MatrizQuadrada::MatrizQuadrada(int ordem){
    this->n = ordem;
    this->vetor = (double *) malloc(sizeof(double)* std::pow(this->n, 2));
    memset(vetor, 0, std::pow(this->n, 2) * sizeof(vetor));
}

MatrizQuadrada::MatrizQuadrada(int ordem, int tipo){
    this->tipo = tipo;
    this->n = ordem;
    this->vetor = (double *) malloc(sizeof(double) * std::pow(this->n, 2));
    memset(vetor, 0, std::pow(this->n, 2) * sizeof(vetor));
}

MatrizQuadrada::~MatrizQuadrada(){
    free(vetor);
}

int MatrizQuadrada::getOrdem(){
    return this->n;
}

int MatrizQuadrada::getTipo(){
    return this->tipo;
}

double MatrizQuadrada::get(int i, int j){
    if(this->tipo == MATRIZ_GENERICA)
        return vetor[this-> n * i + j];
    else if(this->tipo == MATRIZ_IDENTIDADE){
        return i == j;
    } else if(this->tipo == MATRIZ_TRIANGULAR_SUPERIOR) {
        if(i > j) return 0;
        int aux = i*this->n + j - ((i + 1)*i)/2;
        return vetor[aux];
    } else {
        if(i < j) return 0;
        int aux =  i*this->n + j - ((2*this->n - 2 + (i - 1)*(-1))*i)/2;
        return vetor[aux];
    }
  return 0;
}

void MatrizQuadrada::set(int i, int j, double value){
    if(this->tipo == MATRIZ_GENERICA) {
        int aux = i*this->n + j;
        vetor[aux] = value;
    } else if(tipo == MATRIZ_IDENTIDADE) {
        return;
    } else if(this->tipo == MATRIZ_TRIANGULAR_SUPERIOR) {
        if(i > j) return;
        int aux = i*this->n + j - ((i + 1)*i)/2;
        vetor[aux] = value;
    } else if(this->tipo == MATRIZ_TRIANGULAR_INFERIOR) {
        if(i < j) return;
        int aux =  i*this->n + j - ((2*n - 2 + (i - 1)*(-1))*i)/2;
        vetor[aux] = value;
    }
}

MatrizQuadrada MatrizQuadrada::soma(MatrizQuadrada& B){
    MatrizQuadrada *C = new MatrizQuadrada(this->n, MATRIZ_GENERICA);

    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->n; ++j ){
            C->set(i, j, this->get(i,j) + B.get(i, j));
        }
    }
    return *C;
}

MatrizQuadrada MatrizQuadrada::multiplicacao(MatrizQuadrada& B){
    MatrizQuadrada *C = new MatrizQuadrada(this->n, MATRIZ_GENERICA);

    for(int i = 0; i < this->n; i ++) {
        for(int j = 0; j < this->n; j ++) {
            for(int m = 0; m < this->n; m ++) {
                C->set(i, j, C->get(i, j) + this->get(i, m)*B.get(m, j));
            }
        }
    }
    return *C;
}

void MatrizQuadrada::multiplicacaoPorEscalar(double alpha){
    for(int i = 0; i < this->n; ++ i)
        for(int j = 0; j < this->n; ++ j)
            this->set(i, j, this->get(i, j) * alpha);
}
