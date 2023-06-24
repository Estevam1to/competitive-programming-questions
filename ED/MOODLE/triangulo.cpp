#include <stdio.h>
#include <string.h>


void imprimir_triangulo(int vet[], int n){
    static int x = n;

    if(n - 1 <= 0){
        return;
    }

    int aux[n - 1];

    for(int i = 0; i < n - 1; ++i){
        aux[i] = vet[i] + vet[i + 1];
    }

    imprimir_triangulo(aux, n - 1);
    
    for(int i = 0; i < n - 1; ++i){
        printf("%d ", aux[i]);
    }

    printf("\n");

    if(n == x){
        for(int i = 0; i < n; ++i) {
            printf("%d ", vet[i]);
        }
        printf("\n");
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    imprimir_triangulo(vetor, n);
    return 0;
}