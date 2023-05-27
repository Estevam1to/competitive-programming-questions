#include <stdio.h>
#include <stdlib.h>
#include "matriz.cpp"

void readMatrix(MatrizQuadrada& matrix){
    for(int i = 0; i < matrix.getOrdem(); i++){
        for(int j = 0; j < matrix.getOrdem(); j++){
            double value;
            scanf("%lf", &value);
            matrix.set(i, j, value);
        }
    }    
}
void printMatrix(MatrizQuadrada& matrix){
    printf("%d %d\n", matrix.getOrdem(), matrix.getTipo());
    for(int i = 0; i < matrix.getOrdem(); i++){
        for(int j = 0; j < matrix.getOrdem(); j++){
            printf("%.2f ", matrix.get(i, j));
        }
        printf("\n");
    }    
}
int main(){
    //ENTRADA DE DADOS
    int n, tipo;
    scanf("%d", &n);
    scanf("%d", &tipo);
    MatrizQuadrada A(n, tipo);
    readMatrix(A);
    scanf("%d", &tipo);
    MatrizQuadrada B(n, tipo);
    readMatrix(B);    
    //#################################################################
    printf("Testando o construtor e funcoes getOrdem e set\n");
    printMatrix(A);
    printMatrix(B);
    printf("Testando a funcao get\n");
    int i, j;
    double value;
    for(int k = 0; k < 5; k++){
        scanf("%d %d", &i, &j);
        printf("A[%d][%d] = %.2f\n", i, j, A.get(i, j));
        printf("B[%d][%d] = %.2f\n", i, j, B.get(i, j));
    } 
    printf("Testando a funcao set\n");
    for(int k = 0; k < 5; k++){
        scanf("%d %d %lf", &i, &j, &value);
        A.set(i, j, value);
        B.set(i, j, value);
        printf("A[%d][%d] = %.2f\n", i, j, A.get(i, j));
        printf("B[%d][%d] = %.2f\n", i, j, B.get(i, j));
    } 
    
    printf("Testando a funcao soma\n");
    MatrizQuadrada soma = A.soma(B);
    printMatrix(soma);

    printf("Testando a funcao multiplicacao\n");
    MatrizQuadrada multiplicacao = A.multiplicacao(B);
    printMatrix(multiplicacao);   
  
    printf("Testando a funcao MultiplicacaoPorEscalar\n");
    double alpha1, alpha2;
    scanf("%lf %lf", &alpha1, &alpha2);
    A.multiplicacaoPorEscalar(alpha1);
    B.multiplicacaoPorEscalar(alpha2);
    printMatrix(A);    
    printMatrix(B);   
    
    return 1;
}





