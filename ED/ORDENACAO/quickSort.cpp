#include <iostream>

using namespace std;

int partition(int vet[], int ini, int fim){
    int pivo = vet[fim];
    int j = fim - 1;

    for(int i = fim - 1; i >= ini ; i--){
        if(vet[i] >= pivo)
            swap(vet[i], vet[j--]);
    }

    swap(vet[fim], vet[++j]);
    return j;    
}

void quick_sort(int vet[], int ini, int fim) {
    if (ini < fim) {
        int j = partition(vet, ini, fim);
        quick_sort (vet, ini, j -1);
        quick_sort (vet, j+1, fim);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    quick_sort(vetor, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}